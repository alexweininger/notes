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

They dont run at the same time, but they switch off. But it is so fast it really doesnt matter.

Fast responsive computer

Example:

video				button press
