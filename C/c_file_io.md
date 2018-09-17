# File I/O

An introduction into file input and output in C.

<!-- TOC -->

- [1.1. File writing](#11-file-writing)
- [1.2. File reading](#12-file-reading)
- [1.3. Summary](#13-summary)

<!-- /TOC -->

## 1.1. File writing

**Method 1:**

The first method is simply redirecting `stdout` to a file.  

You can accomplish this by compiling your project normally with gcc, then typing the `>` then the file you want to recieve the output.

`my_program > output.txt`

This will cause what would normally be printed to the console (printf(), etc.) to be put into `output.txt`

**Method 2:**

Method two is to explicitly open, and write to a file within your C program using `fprintf or fputc` (there are many other functions that write to files, but for now we'll stick with these).  To have your program write to both the console and a file you must use this method (instead of method 1).  

`fprintf`
Similar to printf, except instead of writing to the console, it writes to a file.  It takes a stream pointer as the first argument, then a format string.  It returns the number of characters it writes to a file, or a negative value if an error occured.  

`fputc`
Writes a single character to the file.  It takes a char, then a stream.  

To create a stream pointer you can use the function `fopen`, which takes the filename, and a character to specify whether you will be reading or writing the file.

```c
FILE * fp;
fp = fopen("file.txt", "w");

int number = 22;
int fprintf(fp, "The number is %d\n", number);
fputc("h", fp);

fclose(fp);
//  file.txt now contains:
// The number is 22
// h
```

When done reading or writing to a file, you must close the file.  Use the `fclose`function to close a file (stream pointer).

## 1.2. File reading

**Method 1:**

Just like we did in method 1 of file writing, you can reditect a file to `stdin`.  This is useful if you have interactive prompts and don't want to re-type the data each time you run your program.

This will take the text from the file and read it just like you typed it into the console.  So `scanf` normally received input from the console, but here it receives data from the text in input.txt.

Example showing input.txt being redirecting to the `stdin`of my_program.

`my_program < input.txt`

**Method 2:**

Read from a file in your C program.  As noted before this is necessary if you want to receive input from the keyboard and read a file.

Below is an example of a program that reads from a file and prints the file contents to the console.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char filename[101];
    printf("Enter the name of the input file.  File name must be less than 101 characters.\n");
  
    scanf("%100[^\n]s", &filename);  // stores up to 100 characters (not including newline) in the char array filename
    // note: this program does not error check scanf, but probably should
  
    FILE *in = fopen(filename, "r");
    printf("Trying to open file: %s\n", filename);
  
     if (in == NULL) {
         fprintf(stderr, "Error opening file. Exiting.\n");
          return EXIT_FAILURE;
     }

     // read each character intul we reach the end of the file (EOF)
     int c;
     while ((c = fgetc(in)) != EOF) {
         putc(c, stdout);
     }
     putc('\n'', stdout);

     fclose(in); // remember to close the file stream!
     return EXIT_SUCCESS;
```

## 1.3. Summary

Useful file related functions:

```c
 FILE * fopen(const char * filename, const char * mode)

 int fclose(FILE *fp)

 int fscanf(FILE *fp, const char * control_string, .. addresses of variables for storage)

 int fprintf(FILE *fp, const char * control_string, ... addresses of varables for storage)

 int fputc(int c, FILE *fp)

 int fgetc(FILE *fp)

 ssize_t getline(char **linept, size_t  *n, FILE *fp) - reads one line into linept and reallocates linept if it is not big enough - getline is a safe function
```
