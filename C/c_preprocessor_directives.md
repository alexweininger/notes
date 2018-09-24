# GNU 12 Preprocessor Directives

<!-- TOC -->

- [GNU 12 Preprocessor Directives](#gnu-12-preprocessor-directives)
	- [12 Preprocessor directives](#12-preprocessor-directives)
		- [12.1 A few directives](#121-a-few-directives)
		- [12.2 Macros](#122-macros)
			- [12.2.1 Macro Functions](#1221-macro-functions)

<!-- /TOC -->

## 12 Preprocessor directives

### 12.1 A few directives<!-- TOC -->

All preprocessor directives are started with a hash mark ('#').

One example we have already used is the #includedirective:

`#include <stdio.h>`

`#if ... #endif` The lines of code between #if and #endif will be comiled only if the expression is true.  This is called conditional compilation.

`#else`

`#line` constant filename

`#error` Forces compiler to abort

### 12.2 Macros

The simplest use of macros is to give constant values meaningful names.

`#define MY_PHONE 5551234`

Any C code can e make into a macro, they are strings that are physically replaced with thier values by the preprocessor before compilation.

example:

`#define SUM 1 + 2 + 3 + 4`

means that `SUM * 2` does not equal 20, it equals 14.

`#undef` undefines a macro

`#ifdef` if macro is defined then this directive is true

`#ifndef` opposite of `#ifdef` 

#### 12.2.1 Macro Functions

Macros can also accept parameters and return values.  These are called *macro functions*.

