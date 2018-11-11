# Notes

Deep copy

In an object, anything larger than primitive data types are stored outside the object.
So when a copy is made with the assignment it only copies what is in the object.
A deep copy copies everything by walking though all the data.

## Testing stages

During requirements / design

60 percent of bugs

Developer testing

Unit testing

- Automated tests for all your methods
- regression testing run all tests regularly
- test driven development

Code reviews

Formal testing

- begins with alpha "feature complete" release (or just prior)
- test plan from requirements specification used.

Beta release

- limited number of real users help.
- Also part of advertising?

Release candidates (from beta version fixes)

Production release

- bugs exist, some may be known. Cost could be too high to delay release
- Amazon does A/B testing by releasing more than one version at once.

Testing happens everywhere

Sonner the better. (TDD)

Issues tracking

- GitHub, Trello, etc.

QA Engineers

What is a test case?

What info should go into a test case?

- state info(pre-condition), user input, expected output

Test case:

- identifiers
- test item (title)
- pre-conditions
- input spec (recreation steps)
- output spec
- env needs
- special procedural requirements
- inter case dependencies

Test case for Settlers of Catan

- Resource management
- Testing the methods for storage and add/remove resource cards from players inventory.
- pre-conditions
	- have enough resources to remove
- input specification
	- (call removeResourceCard method) build a city/settlement
- output (removed n resourceCards from players inventory)
- environment: game is started...
- special procedural req.
- inter case dependencies

## Assert

alert and potentially stop execution of the program based on a variable value

```java
	@Test
	public void addition_isCorrect() {
		assertEquals(4, 2);
	}

	// radius, x, y, and color
	public void testSpotConstructor() {
		Spot testSpot = new Spot();

		assertEquals(20, testSpot.getSize());
	}
```

`assertEquals(factorial(1), 1);`

## Parallelism

Threads: 1 channel of program execution

They don't run at the same time, but they switch off. But it is so fast it really doesn't matter.

Fast responsive computer

Example:

video				button press
frame 1
frame 2
...
frame 4000			tap!      onclick
						if (button == etc.)
							videoplayer.pause();

no more frames
rendered pause

parallelism: same thing happening

concurrency: different things happening at once. Looping an array while also playing music, etc.

Benefits of using threads:

- responsiveness
- Increased performance (speed/throughput)
- need to do more than one things **concurrently**

Issues with threads:

- complexity (programmer difficulty)
- difficult to debug
- data race: same / shared data used by two or more threads. If race winner determines data outcome, then we have a race.
  - `final int LENGTH = 100;`
  - all threads can use `LENGTH`
  - no race here
  - final is safe, because data races cant happen on it
- debugging:
- tons of possible values for just a simple program
- which one is correct

The **runnable** interface is proffered to sub classing Thread

```java
implements Runnable // stuff todo

@Override public void run() // stuff todo

Thread myThread = new Thread(runnableObject);
myThread.start(); // please run this as a thread
```

Synchronization:

```java
if (x > 1) {
	x--;
}
```

At the end i is one less, if there is only 1 thread. If there is more than one thread behavior may be weird.

```java
if (x > 1) {
	x--;
}
```

If it spreads this code across 3 threads, and evaluates all of the if statements and then all of the rest of the code it will subtract 3 from x after all of the if statements are completed.

```java
public Object getElement(ArrayList<String> v) {
	synchronized(v) {
		if (v.isEmpty()) return null;
		String rtnVal = v.elementAt(0);
		v.removeElementAt(0);
		return rtnVal;
	}
}
```
