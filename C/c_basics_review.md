# Exam 1 Review

## Topics for review

- C control flow (if, if/else, switch, for, while)
- Functions (prototypes, definition, parameters, return type)
- Variables and types (examples: int, char, double, int *, char *, int **, etc.) and their sizes
- Arrays
- Structs
- Typedef
- Malloc, free, sizeof (allocating memory on the heap)
- Pointers (to variables, to structs, to arrays)
- NULL, dereferencing pointers, dangling pointers, pointer arithmetic
- Preprocessor directives
- Printing to console (stdout with fprintf, or use printf)
- Reading data from keyboard (stdin with fscanf, or use scanf)
- File I/O (reading from text files, writing to text files)
- Identifying when a segmentation fault would occur
- Identifying syntax errors
- Good programming style

### data types and thier sizes

- int, 2 or 4 bytes
- char, 1 byte
- long, 4 bytes
- double, 8 bytes
- float, 4 bytes
- int *, 4 or 8 bytes
- char *, 4 or 8bytes
- double *, 4 or 8 bytes

### arrays

An array can be declares and defined in C just like you would in Java.

`int arr = {1, 2, 3};`
`int arr[3];`

An array is treated as a pointer to its first element, e.g. arr = &arr[0]

### strings

Strings can be declared and defined in a few ways, here are the 3 most common ways

```c
char str[40] = "Here is my text";
```

This creates a character array of 40 characters.  The first 15 characters will be set according to the specifies string.  The rest will be set to nulls.

### structs

Structs are like classes in Java.  

Declare and define a struct like so:

```c
struct car {
    int id;
    char[30] model;
    int year;
}
```

## Review problems

### Question 1

Question 1 (Multiple choice, choose the best answer):
Fill in the blank. If __________ is dereferenced, a segmentation fault can occur.
a. NULL.
b. a dangling pointer (points to memory not allocated to the program)
c. Both a and b.
d. None of the above.

**Answer:**
c. both a and b

### Question 2

**Could the following program result in a segmentation fault or bus error?**
a. Yes, because the integer i cannot be used to index a character array.
b. Yes, because the for-loop executes too many times.
c. Yes, because the size of the array is too large for a C program.
d. No, the program is fine; it would not result in any memory faults.
```c

#include <stdio.h>
int main(void) {
int i;
char a[100];
for(i = 0; i <= 100; i++)
a[i] = ‘a’ + i;
return 0;
}
```

**Answer:**
d. because although the program reaches outside of the array by 1, int i is above the array on the stack, so it would be reaching into the memory allocated for int i.

### Question 3

**What is the output of the program below?**
a. The program does not execute successfully; a segmentation fault occurs.
b. abc
c. 012
d. aaa
```c

#include <stdio.h>
int main(void){
char c = ‘a’;
char *p;
p = &c;
printf(“%c%c%c”, *p, *p + 1, *p + 2);
return 0;
}
```

**Answer:**
b. abc because *p + 1 dereferences p, then adds 1 to that value.  And adding 1 to the asci value of a gives b.

**NOTE: *p + 1, the *p is evaluated before the + 1.  *  has higher precedence than  +.**

### Question 4

**The C compiler has a preprocessor built into it. How would one define a program-specific**
**constant called “PI” using a preprocessor directive?**
a. define 3.14159 PI;
b. #define 3.14159 PI;
c. #define PI 3.14159
d. #PI 3.14159

**Answer:**
c. #define PI 3.14159

### Question 5

**Consider the short program below. Note that this program compiles and executes**
**successfully.**

**Suppose that this program is invoked from the command line using:`$ ./a.out Go Pilots**`

**If it is invoked using the above, what are the values of argc and argv at the start of the**
**program? If you want to use a picture to illustrate your answer, please do.**
```c

int main(int argc, char * argv[]) {
if(argc != 3) {
printf("%s error: incorrect number of parameters \n", argv[0]);
return 1;
}
printf("Correct! \n");
return 0;
}
```

**Answer:**
argc = 3
argv = {"./a.out", "Go", "Pilots"}

### Question 6

**Consider the short program below. Note that the program compiles and executes successfully. Answer the following questions.**
**a. The program below has flaws. Name one style flaw and one actual error. Explain each answer.**
**b. Directly in the program below, add the line or lines of code that will fix the errors you identified in part a.**
**c. Draw the picture of memory (with pointers) that represents the program after you fixed the error.**
```c

int main(void) {
int *A = malloc(sizeof(int));
int *B = malloc(sizeof(int));
*A = 5;
*B = 17;
A = B;
B = 6;
printf(“A points to %d \n”, *A);
return 0;
}
```

**Answer:**
a. For style, you should not use uppercase letters for variables unless it is a constant.  The actual error is that the memory allocated to *A and *B are never freed.

b. edited code:
```c

int main(void) {
int *A = malloc(sizeof(int));
int *B = malloc(sizeof(int));
*A = 5;
*B = 17;
A = B;
B = 6;
printf(“A points to %d \n”, *A);
free(A);
return 0;
}
```

expanation of code:  Since A took the address of B freeing A frees both A and B.

c. **DO LATER**

**Consider the short program below. Note that this program compiles but does not execute**
**correctly. Explain why this program’s execution could result in a segmentation fault.**

```c
#include <stdio.h>
#include <stdlib.h>
int initializePointer(int * z);
int main (void) {
int *x;
initializePointer(x);
printf("%d \n", *x);
return 0;
}
int initializePointer(int * z) {
z = (int *)malloc(sizeof(int));
*z = 5;
return 0;
}
```

**Answer:**
This program could result in a segmentation fault because the pointer int *x is not defined before it is passed as a parameter to the initializePointer() function.  So in the initializePointer() function a pointer that points to a random garbage location is dereferences which could cause a degmentation fault.

### Question 7

**Consider the short program below. Note that this program compiles but does not execute correctly. Explain why this program’s execution could result in a segmentation fault.**

```c
#include <stdio.h>
#include <stdlib.h>
int initializePointer(int * z);
int main (void) {
    int *x;
    initializePointer(x);
    printf("%d \n", *x);
    return 0;
}
int initializePointer(int * z) {
    z = (int *)malloc(sizeof(int));
    *z = 5;
    return 0;
}
```

**Answer:**
This program could result in a segmentation fault because the pointer x is not defined before it is passed into the function initializePointer().  This can cause a segmentation fault because if x is not initialized, the address that is given to the function could be anywhere in memeory.

### Question 8

**C is a typed language. This means that when variables are declared, their type is also declared: int, char, ListNode*, and so forth. The C compiler may not compile a program if a variable assignment has mismatched types or if a struct’s fields are accessed incorrectly.**

**Consider the following type definitions and declarations.**

```c
// type definitions
typedef struct tag {
int count;
int *first;
int *last;
} Quack;
// variable declarations
Quack q1;
struct tag * q2;
int myCount = 5;
```

**Assume that each variable’s memory has been properly allocated. For each of the**
**assignments below, identify if the assignment would be successfully compiled.**

`q2 -> count = myCount;` 
would compile would not compile

`q2 -> first = &myCount;` 
would compile would not compile

`q1 -> count = myCount;` 
would compile would not compile

**Answer:**

`q2 -> count = myCount;` 
**would compile** would not compile

`q2 -> first = &myCount;` 
**would compile** would not compile

`q1 -> count = myCount;` 
would compile **would not compile**
This won't compile because q1 is not a pointer to the struct, it is just an instance of the struct.  So q1.count = myCount; would work.  

### Question 9

**Suppose that you have the following interface, or function prototype: `int getValue(struct mydata** list);**`
**The function returns an int representing the value of the elements in a “struct mydata” object. Complete the following program by calling the function getValue on the variable data1. Store the result in the variable value. You may assume that the functions createDataObject and freeDataObject have been defined elsewhere and work properly.**
```c

int main(void) {
int value = 0;
struct myData* data1 = createDataObject();
// Call the getValue function here using one of
// (a) thru (d) below.
printf("The value of the object is %d \n", value);
freeDataObject(data1);
data1 = NULL;
return EXIT_SUCCESS;
}
```

a. value = getValue(data1);
b. value = getValue(&data1);
c. &value = getValue(&data1);
d. value = getValue(*data1);

**Answer:**
b. The function getValue(struct mydata ** list) is asking for a double pointer.  This means that it will dereference the argument we pass to it twice.  So we need to pass the address of the pointer to struct data1 to the function.

### Question 10

**Write a main method that:**
**• Attempts opens a file, “xyz.txt”, for reading.**
**• If the file cannot be opened, the function should return EXIT_FAILURE.**
**• If the file can be opened, it should attempt to read a single character from the file.**
**• If no character exists (e.g., because the file is empty), the function should return EXIT_FAILURE.**
**• If a character is read, the function should print the character (as a character) to the console, followed by a newline character, and then return EXIT_SUCCESS.**
**The function should always close any files that it has successfully opened.**
**You may assume that any necessary #includes are given at the beginning of the file. Write your function definition here:**

**Answer:**

```c
int main(void) {
    FILE * fp = fopen("xyz.txt", "w");

    if (fp == NULL) {
        reutrn EXIT_FAILURE;
    }

    char c = fgetc(fp);
    if(c == EOF) {
        return EXIT_FAILURE;
    } else {
        printf("%c\n", c);
        return EXIT_SUCCESS;
    }
    fclose(fp);
}
```

### Question 11

**Given the type definition:**

```c
typedef struct abc {
int arr[10];
} abc;
```

**write a function createAbc that**
**• takes one parameter, an int**
**• malloc's memory for one abc object**
**• initializes all 10 array elements in the newly created object using the value of the**
**parameter**
**• returns a pointer to the abc object**
**Write your function definition here:**

**Answer:**

```c
createAbc(int x) {
    abc * myAbc = (abc *) malloc(sizeof(abc));
    int i;
    for (i = 0; i < 10; i++) {
        myAbc->arr[i] = x;
    }
    return myAbc;
}
```

### Question 12

**What are the contents of the array myArray after the following snippet is executed?**

```c
int myArray[] = {0,2,4,6,8,10,12,14,16,18,20};
int *p = myArray;
p += 3;
*p += 2;
p += 4;
*p += 5;
p--;
(*p)--;
```

**Draw array myArray here:**

**Answer:**

`{0, 2, 4, 8, 8, 10, 11, 19, 16, 18, 20};`

`p += 3` this moves the pointer 3 elements in the array, so p now points tomyArray[3]

`*p += 2`this adds 2 to the dereferenced value of p, so it adds 2 to 6 making 8.

`p--`this decrements the pointer position by 1.  p now points to myArray[6]

`(*p)--`this dereferences the pointer p, then decrements that value.  So this subtracts 1 from myArray[6], (12 - 1 = 11)

### Question 13

**What does the following program print?**

```c
#include <stdio.h>
#define ZZ 3
#define f(x) x*x
int main(void) {
printf("%d\t%d\t%d\n", ZZ, f(ZZ), f(ZZ+2));
return EXIT_SUCCESS;
}
```

**Answer:**

3    9    11

explanation: Since macros and macro functions are literary placed in the code where they are referenced, the third value in the printf() function is 11 because f(ZZ+2) evaluates as: 3 + 2 * 3 + 2, which equals 6 + 5, or 11. 

## Other questions (not from review sheet)

### Question 14

**Write the C code to define a struct called car that contains:**
**color (character array of length 30)**
**tank_size (double)**
**mpg_city (double)**
**mpg_hwy (double)**
**id (int)**

**Answer:**

```c
struct car {
    char[30] color;
    double tank_size;
    double mpg_city;
    double mpg_hwy;
    int id;
};
```

### Question 15

**Write a C program that opens the file named "intersting.txt" and writes every other character into the file "half_as_interesting.txt".  Asssume the appropriate includes are already included.  Make sure to do appropriate error checking and return EXIT_FAILURE if error, EXIT_SUCCESS if success.**

**Answer:**

```c
// write your code here
int main(void){
    FILE * file = fopen("interesting.txt", 'r');
    if(file == NULL){
        printf("File not found");
        return EXIT_FAILURE;
    }
    FILE * file2 = fopen("half_as_interesting.txt", 'w');

    if (file2 == NULL) {
        return EXIT_FAILURE;
    }

    int toggle = 1;
    char c;
    while((c = fgetc(file)) != EOF){
        if(toggle == 1){
            toggle--;
        } else {
            fputc(c, file2);
            toggle++;
        }
    }
    fclose(file);
    fclose(file2);
}
```