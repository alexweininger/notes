# CS 301 Exam Review

<!-- TOC -->

- [Binary](#binary)
- [Hexadecimal](#hexadecimal)
- [Android Colors](#android-colors)
	- [Encoding](#encoding)
	- [Decoding](#decoding)
- [Layouts](#layouts)
- [Android](#android)

<!-- /TOC -->

## Binary

Binary is a way to represent decimal numbers in a string of 1's and 0's.  Each 1 or 0 is 1 bit, the smallest unit of storage in a computer. Here are some examples of binary:

`1100` `11000101`

Binary is called base 2 because for each digit instead of increasing in value by 10 like decimal values, they increase by a factor of 2.

So the first digit of a binary string (from right to left) is the 1's column.

So `0` in binary is the decimal number 0. And `1` in binary is the decimal number 1.

The next digit is the 2's column. So `10` = 2.  And `11` = 3. The value of each column tells whether or not the column number is added to the decimal value or not.

In the case of `11`, we have a 1, and we have a 2. Adding them we get 3.

The columns are: 1, 2, 4, 8, 16...

So, `1000` = the decimal value 8. As we have a 1 in the 8's column, and 0's in all other columns.

## Hexadecimal

Hexadecimal, also known as base 16 or hex, allows for more numbers to be represented as inside of a single digit. As said before binary is base 2.  Hexadecimal is base 16, meaning each column increases by a factor of 16.

Digits go from 0 - 9 and then go on starting at A, ending at F.

`0 1 2 3 4 5 6 7 8 9 A (10) B (11) C (12) D (13) E (14) F (15)`

The decimal value of a hex value is determined just like binary. For example consider the decimal value of `D1CE`.

`D1CE = 13 * 16^3 + 1 * 16^2 + 12 * 16 + 14`

E is the number 14.

C is the number 12, and since it is in the (sixteens column) we multiply 12 * 16^1.

1 is just 1, and it is in the 256 column (16^2), so we take 1 * 16^2.

D is the number 13, and is in the 16^3 column, so we take 13 * 16^3.

Adding all the numbers up, `D1CE = 53710` in decimal.

## Android Colors

Colors in Android are represented as sRGB with the 4 components packed into a 32-bit integer value.

### Encoding

The four components of a color int are encoded in the following way:

`int color = (A & 0xff) << 24 | (R & 0xff) << 16 | (G & 0xff) << 8 | (B & 0xff);`

Because of this encoding, color integers can easily be described as an integer constant in source. For instance, opaque blue is 0xff0000ff and yellow is 0xffffff00.

To easily encode color integers, it is recommended to use the static methods argb(int, int, int, int) and rgb(int, int, int). The second method omits the alpha component and assumes the color is opaque (alpha is 255). As a convenience this class also offers methods to encode color integers from components defined in the  range: `argb(float, float, float, float)` and `rgb(float, float, float)`.

Color longs (defined below) can be easily converted to color ints by invoking the toArgb(long) method. This method performs a color space conversion if needed.

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

## Layouts

Linear Layout

	orientation: horizontal / vertical
	weight of each child

Constraint Layout
	constraints and relative

## Android

```java
Button myButton = (Button) findViewById(R.id.myButton);

myButton.setOnClickListener(new onClickListener() {
	@Override
	public void onClick(View v) {
		...
	}
})
```

topics

- number systems: hex, binary => android color

- hash tables

- basic java, ArrayList

- generics