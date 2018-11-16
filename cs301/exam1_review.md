# CS 301 Exam Review

<!-- TOC -->

- [Number Systems](#number-systems)
	- [Binary](#binary)
	- [Hexadecimal](#hexadecimal)
	- [Converting Binary to Hexadecimal](#converting-binary-to-hexadecimal)
	- [Android Colors](#android-colors)
	- [Encoding](#encoding)
	- [Decoding](#decoding)
- [Hash Tables (HashMaps)](#hash-tables-hashmaps)
- [Layouts](#layouts)
	- [SurfaceView and Canvas](#surfaceview-and-canvas)
	- [Layouts and Views](#layouts-and-views)
		- [LinearLayout](#linearlayout)
		- [TextView](#textview)
		- [Button](#button)
		- [Spinner](#spinner)
		- [RadioButton](#radiobutton)
		- [SeekBar](#seekbar)
- [Post Exam Notes](#post-exam-notes)
	- [Inheritance](#inheritance)
	- [Use cases](#use-cases)
- [Android API notes](#android-api-notes)

<!-- /TOC -->

## Number Systems

### Binary

Binary is a way to represent decimal numbers in a string of 1's and 0's. Each 1 or 0 is 1 bit, the smallest unit of storage in a computer. Here are some examples of binary:

`1100` `11000101`

Binary is called base 2 because for each digit instead of increasing in value by 10 like decimal values, they increase by a factor of 2.

So the first digit of a binary string (from right to left) is the 1's column.

So `0` in binary is the decimal number 0. And `1` in binary is the decimal number 1.

The next digit is the 2's column. So `10` = 2. And `11` = 3. The value of each column tells whether or not the column number is added to the decimal value or not.

In the case of `11`, we have a 1, and we have a 2. Adding them we get 3.

The columns are: 1, 2, 4, 8, 16...

So, `1000` = the decimal value 8. As we have a 1 in the 8's column, and 0's in all other columns.

### Hexadecimal

Hexadecimal, also known as base 16 or hex, allows for more numbers to be represented as inside of a single digit. As said before binary is base 2. Hexadecimal is base 16, meaning each column increases by a factor of 16.

Digits go from 0 - 9 and then go on starting at A, ending at F.

`0 1 2 3 4 5 6 7 8 9 A (10) B (11) C (12) D (13) E (14) F (15)`

The decimal value of a hex value is determined just like binary. For example consider the decimal value of `D1CE`.

`D1CE = 13 * 16^3 + 1 * 16^2 + 12 * 16 + 14`

E is the number 14.

C is the number 12, and since it is in the (sixteens column) we multiply 12 \* 16^1.

1 is just 1, and it is in the 256 column (16^2), so we take 1 \* 16^2.

D is the number 13, and is in the 16^3 column, so we take 13 \* 16^3.

Adding all the numbers up, `D1CE = 53710` in decimal.

### Converting Binary to Hexadecimal

To convert a value from binary to hexadecimal, you first add a number of 0's to the left of the most significant bit of the binary number, so the number of bits of the new binary number is a multiple of 4. Then, you simply translate each 4-bit binary nibble to its hexadecimal digit equivalent.

For example, to convert to hex the binary number `1100100011`, we add two zeros to the left of the most significant bit:`0011 0010 0011`.

Then we translate `0011 0010 0011` to `0x323`, as `0011` is `0x3` and `0010` is `0x2`.

### Android Colors

Colors in Android are represented as sRGB with the 4 components packed into a 32-bit integer value.

The format is either `#RRGGBB` or `#AARRGGBB`, where `AA` is the hex alpha value. `FF` would be fully opaque and `00` would be full transparent. `RR` is the hex red value.

### Encoding

The four components of a color int are encoded in the following way:

`int color = (A & 0xff) << 24 | (R & 0xff) << 16 | (G & 0xff) << 8 | (B & 0xff);`

Because of this encoding, color integers can easily be described as an integer constant in source. For instance, opaque blue is 0xff0000ff and yellow is 0xffffff00.

To easily encode color integers, it is recommended to use the static methods argb(int, int, int, int) and rgb(int, int, int). The second method omits the alpha component and assumes the color is opaque (alpha is 255). As a convenience this class also offers methods to encode color integers from components defined in the range: `argb(float, float, float, float)` and `rgb(float, float, float)`.

It is also possible to create a color int by invoking the method toArgb() on a color instance.

### Decoding

The four ARGB components can be individually extracted from a color int using the following expressions:

```java
 int A = (color >> 24) & 0xff;	// or color >>> 24
 int R = (color >> 16) & 0xff;
 int G = (color >>  8) & 0xff;
 int B = (color      ) & 0xff;
```

This class offers convenience methods to easily extract these components:

```java
alpha(int)	// to extract the alpha component
red(int)	// to extract the red component
green(int)	// to extract the green component
blue(int)	// to extract the blue component
```

## Hash Tables (HashMaps)

HashTable refers to a specific type of data structure that stores key-value pairs. In Java, HashTables are implemented as `HashMap`.

You can declare a HashMap like so:

`import java.util.HashMap<K,V>;`

```java
HashMap<String, Integer> agesOfPeople = new HashMap<String, Integer>;
```

K - the type of key in the map

V - the type of mapped values

You can add key-value pairs to a HashMap with the `put()` method. And can retrieve a value with the `get(Object key)` method.

```java
HashMap<String, Integer> agesOfPeople = new HashMap<>();
agesOfPeople.put("Alex", 19);
int a = agesOfPeople.get("Alex");
```

`boolean containsKey(Object key);` returns true if key exists in HashMap, false otherwise

`boolean containsValue(Object value);` returns true if value exists in HashMap, false otherwise

`Object remove(Object key);` removes the pair given key

`int size()` returns the number of key-value pairs in the HashMap

**Note: if a key already exists in the HashMap, and you call put(key, value), it will replace the value that is already paired with that key in the HashMap.**

## Layouts

Linear Layout

    orientation: horizontal / vertical
    weight of each child

Constraint Layout
constraints and relative

```java
Button myButton = (Button) findViewById(R.id.myButton);

myButton.setOnClickListener(new onClickListener() {
	@Override
	public void onClick(View v) {
		...
	}
})
```

### SurfaceView and Canvas

SurfaceView can be extended to create a custom SurfaceView with a Canvas object we can draw on.

You can extend the SurfaceView class like so:

```java
public class customSurfaceView extends SurfaceView {

  // constructors
  public boardSurfaceView(Context context) {
    super(context);
    setWillNotDraw(false); // MANDATORY
  }

  public boardSurfaceView(Context context, AttributeSet attrs) {
    super(context, attrs);
    setWillNotDraw(false);
  }

  public void OnDraw(Canvas canvas) {
    // drawing goes in here
  }

}
```

the `OnDraw(Canvas)` method is called automatically for you.

To draw on the canvas you first need a paint.

```java
Paint redPaint = new Paint();
redPaint.setColor(Color.RED);
redPaint.setStyle(Paint.Style.FILL);
```

Then you can draw on the canvas using this paint with a method like this:

`canvas.drawRect(float left, float top, float right, float bottom, Paint paint);`

```java
canvas.drawRect(100, 100, 200, 200, redPaint);
```

### Layouts and Views

#### LinearLayout

LinearLayout provides a container for holding Views. A LinearLayout can be of two orientations, vertical or horizontal.

You can specify orientation with `android: orientation="vertical/horizontal"`

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingLeft="16dp"
    android:paddingRight="16dp"
    android:orientation="vertical" >
    <EditText
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="@string/subject" />
    <Button
        android:layout_width="100dp"
        android:layout_height="wrap_content"
        android:layout_gravity="right"
        android:text="@string/send" />
</LinearLayout>
```

#### TextView

TextView is a simply displays a string.

```xml
   <TextView
        android:id="@+id/label_g"
        android:layout_width="40dp"
        android:layout_height="wrap_content"
        android:layout_marginTop="8dp"
        android:text="@string/green"
        android:textColor="@android:color/black"
        app:layout_constraintStart_toStartOf="@+id/label_r"
        app:layout_constraintTop_toBottomOf="@+id/label_r" />
```

#### Button

```java
button.setOnClickListener(new View.OnClickListener() {
	@Override
	public void onClick(View view) {
		// code executed when button is clicked
	}
})
```

#### Spinner

```java
ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.data,
	android.R.layout.simple_spinner_item);
adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
spinner.setAdapter(adapter);

spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
	@Override
	public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
		adapterView.getItemSelectedPosition(); // get index of selected item
		adapterView.getItemSelected();
	} // primary
	@Override
	public void onNothingSelected(AdapterView<?> adapterView) {}
})
```

#### RadioButton

```java
radioButtonGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	@Override
	public void onCheckChanged(RadioGroup radioGroup, int idChecked) {
		if (idChecked == radioButton.getId()) {} // executed when radio button is checked/changed
	}
})
```

#### SeekBar

```java
seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
	@Override
	public void onProgressChanged(SeekBar seekBar, int i, boolean b) {}
	@Override
	public void onStartTrackingTouch(SeekBar seekBar) {}
	@Override
	public void onStopTrackingTouch(SeekBar seekBar) {}
})
```

## Post Exam Notes

### Inheritance

`Apple -> Pear ->Grape`

```java
public class Apple {
	protected int core = 3;

	public Apple (int x) {
		core = x + 1;
	}

	public String eat() {
		return "c: " + core;
	}
}

public class Pear extends Apple {
	public Pear (int x) {
		super (5);
	}
}

public class Grape extends Apple {
	public Grape (int y) {
		super(y);
		core = 0;
	}

	public String eat() {
		return "p: " + core;
	}
}
```

Consider the following code

```java
Apple a1 = new Apple(5);
Apple a2 = new Pear(10);
Apple a3 = new Grape(20);
System.out.println(a1.eat());
System.out.println(a2.eat());
System.out.println(a3.eat());

/* Prints:
 * c: 6
 * c: 6
 * p: 0
 */
```

### Use cases

Primary actor:

Preconditions:

Trigger:

Description:

Story:

Preconditions:

Exceptions/alternatives:

## Android API notes

```java
public class MainActivity extends AppCompatActivity {
	@Override
	protected void onCreate() {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// important lines
		Button b = (Button) findViewById(R.id.zeButton); // id given from xml
		MySV sv = (MySC) findViewById(R.id.thing); // id given from xml
		SVHandler svh = new SVHandler(sv);
		b.setOnClickListener(svh);
	}
}

public class SVHandler implements View.OnClickHandler { // ***
	MySV theSV = null;

	public SVHandler(MySV sv) {
		theSV = sv;
	}

	@Override
	public void onClick(View v) {
		theSV.flip(); // ***
		theSV.invalidate(); // ***
	}
}
```