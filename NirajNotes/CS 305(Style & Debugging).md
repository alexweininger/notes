# CS 305(Style & Debugging)
**Ch 22 Style**
Formatting Code:
```c
//Curly brackets in first column, which will help compiler find start of program easier
static char *
concat (char *s1, char *s2)
{
    ...
}
//Start a new line with a new operator, as opposed to right after it
if(foo_this == 2341234521509825
    && remaining == 00)
//Declare multiple variables in one line
int bar, bee;
```
-Descriptive function and variable names using '_' for multiple word names; also have separate distinct local variables
-Explicitly declare variable types

Global variables: Should be used after considering using a local variable; practical when passing through the same parameter many times; data structures should be defined globally; make sure no local variables share a name with any global variables

-Make the program readable to someone other than yourself

**Ch 23 Debugging**

C does not explicitly call out where an error occurs nor does it call that error while your are coding like other IDEs; the errors occurring, however, can offer hints as to what is occurring in your code

Compiler-timer errors:
    -'parse error...' : usuall a general syntax error; frequently caused by a missing semicolon; can sometimes reference on the line after the actual line the error occurs on; a missing curly bracket can also cause this error;
    -'undefined reference to...' : usually name of function or variable typed incorrectly; note that C is also case sensitve so this may also be the misspelling;
    -'unterminated string or character constant' : missing closed quotes (', ")
    -'...undeclared' : refers to an undefined variable
    -'different type arg' : mismatch in parameter data types
    -'too few/many parameters' : incorrect number of parameters passed through

Run-time errors:
    -Confusion of = and == : Simply consider if you are trying to define a value using '=' or trying to find out if a condition is true or false with '=='
    - ++foo vs foo++ : In a case like my_array[++my_index], my_index is incremented by 1 before finding the index position of the array and after if the '++' was used after my_index
    -Storage assumptions : Don't assume the size of a structure is the size of it's parts
    -Array out of bounds : self-explanatory
    -Uncoordinated output : strange effects when outputting to screen; use '\n; to buffer the outputs