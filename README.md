Table of Contents
=================

   * [Getting started](#getting-started)
   * [Introduction](#introduction)
   * [Data types](#data-types)
   * [Conditionals](#conditionals)
   * [Loops](#loops)
   * [Functions](#functions)
   * [Switch case](#switch-case)
   * [Pointers](#pointers)
   * [malloc](#malloc)
   * [Structures](#structures)
   * [Strings](#strings)
   * [File input/output](#file-inputoutput)
   * [Libraries](#libraries)
   * [Rosalind](#rosalind)
   * [Links](#links)

Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc)

Why am I learning C? Check out my [blog post](http://davetang.org/muse/2014/04/28/getting-started-with-c/) and this [post](http://spectrum.ieee.org/computing/software/the-2016-top-programming-languages). You can create a PDF of this README using [pandoc](http://pandoc.org/):

```bash
pandoc README.md -o readme.pdf
```

Getting started
===============

You will need a compiler, such as `gcc` (GNU C compiler); I have some notes of my [GitHub page](http://davetang.github.io/2014/11/03/compiling.html) on compiling. Basically a compiler analyses a program and translates it into a form that is suitable for execution on your computer. If you are using Windows or macOS, you can use [Docker](https://github.com/davetang/learning_docker) to run an instance of Ubuntu so that you can compile the examples.

During the compilation process, the source code is translated by the compiler into assembly code and then translated into actual machine instructions in a format known as *object code*. This file typically has the same name as the source file but with a `.o` suffix.

If the program uses other programs, they need to be linked together. Programs that are used from the system's program library are also searched and linked together with the object program. The process of compiling and linking a program is often called *building*. The final linked file is an executable object saved as a file.

To compile a specific example, type:

```bash
# C programs typically end in .c
# choose_number is the final executable object
gcc input_output.c -o choose_number
```

or to compile all the examples, type:

```bash
make
```

The binaries will be stored in the `bin` folder.

Introduction
============

Here's the source code of a simple C program:

```c
#include <stdio.h>

/*
   This is a comment
*/

int main(){
   printf("Hello world.\n");
   return 0;
}
```

The [include directive](https://en.wikipedia.org/wiki/Include_directive) tells the compiler to put code from the header called stdio.h into our program before creating the executable. The "main" function is called when the C program is executed, thereby running the printf() function. The return is used to tell the operating system whether the program has succeeded or not; a return value of 0 means success. Now to compile and to execute the program.

```bash
gcc hello.c -o say_hello

say_hello 
#Hello world.
```

Data types
==========

Data types are used to store different types of data; basic types include `char`, `int`, and `float`. A variable of type `char` stores a single character; type `int` stores integers; and type `float` stores decimal numbers. The keywords `char`, `int`, and `float` are used to declare a variable. For example, in `data_type.c`:

```c
char my_char;
my_char = 'A';
printf("my_char -> %c\n", my_char);

int my_integer;
my_integer = 5;
printf("my_integer -> %i\n", my_integer);

float my_float;
my_float = 1.200000001;
printf("my_float -> %f\n", my_float);
```

Conditionals
============

Use `if`, `else if`, and `else`.

```c
#include <stdio.h>

int main(){
   float answer;

   printf("What is the square root of 2?\n");
   scanf("%f", &answer);

   if (answer >  1.4141 && answer < 1.4143){
      printf ("Correct!\n" );
   } else if (answer > 1 && answer < 2){
      printf("You are close!\n");
   } else {
      printf("Wrong!\n" );
   }

   return 0;
}
```

Loops
=====

There are three types of loops: `for`, `while`, and `do..while`; see `loop.c`.

```c
// for loop
int series[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int i;
for (i = 0; i < 10; i++){
   printf("%d\n", series[i]);
}

// while loop with break and continue statements
int n = 0;
while (1){
   n++;
   if (n % 2 == 1){
      continue;
   }

   printf("%d is an even number\n", n);

   // exit loop when n = 20
   if (n == 20){
      printf("Reached 20 loops\n");
      break;
   }
}

// do..while
do {
   printf( "I will run once even when a condition is not met\n" );
} while (0);
```

Functions
=========

Functions need to be declared right at the start or its prototype. Prototypes are declarations of functions; they are only necessary to alert the compiler about the existence of a function if we don't want to go ahead and fully define the function. If the function returns a value, you must declare the type of value the function returns in the function declaration. In the example below, an integer is returned (the result of adding the two arguments).

```c
#include <stdio.h>

/*
   The general format for a prototype
   return-type function_name (arg_type arg1, ..., arg_type argN); 
*/
int add (int a, int b);

// function
int add (int a, int b){
   return a + b;
}

int main (void){
   int a = add(22, 20);
   printf("%i\n", a);
   return 0;
}
```

Note that a C function can only return a single value.

See `function.c` for implementing functions with a variable number of arguments.

Switch case
===========

Switch case statements are a substitute for long `if` statements that compare a variable to several values.

```c
#include <stdio.h>

int main(){
   int input = 4;

   switch (input) {
      case 1:
         printf("Input is %i\n", input);
         break;
      case 2:
         printf("Input is %i\n", input);
         break;
      case 3:
         printf("Input is %i\n", input);
         break;
      case 4:
         printf("Input is %i\n", input);
         break;
      default:
         printf("Input was not 1, 2, 3, or 4!\n");
         break;
   }

   return 0;

}
```

Pointers
========

[Pointers](http://www.cprogramming.com/tutorial/c/lesson6.html) point to specific memory locations.

```c
/*
   The pointer declaration looks like this:
   <variable_type> *<name>;

   For example, you could declare a pointer that stores the
   address of an integer with the following syntax:
*/

int *points_to_integer;
int *pointer1, *pointer2;
```

Below is an example of obtaining the memory location and how to dereference a pointer.

```c
#include <stdio.h>

int main(){ 
   int x = 31;
   int *p;

   p = &x;

   printf("The memory location of x is %p\n", p );
   printf("The pointer, p, points to the value %d\n", *p );

   return(0);
}
```

malloc
======

The function [malloc](http://c-faq.com/malloc/index.html), which resides in the stdlib.h header file, is used to initialise pointers with memory from free store. The argument to malloc is the amount of memory requested (in bytes), and malloc obtains a block of memory of that size and then returns a pointer to the block of memory allocated.

```c
#include <stdlib.h>

float *pointer;
// the sizeof function takes an expression and returns its size
pointer = malloc(sizeof(*pointer)); 

// the free function returns memory to the operating system
free(pointer);
```

Structures
==========

[Structures](http://www.cprogramming.com/tutorial/c/lesson7.html) provide a way of storing many different values in variables of potentially different types under the same name.

```c
/*
   The format for defining a structure is:

   struct Tag {
      Members
   };
*/
```

Example code in `structure.c`:

```c
#include <stdio.h>

struct gene {
   int entrez;
   int hgnc;
   int omim;
};

int main(){
   struct gene HBA1;
   HBA1.entrez = 3039;
   HBA1.hgnc   = 4823;
   HBA1.omim   = 141800;

   printf("The Entrez ID for HBA1 is %i\n", HBA1.entrez);
   printf("The HGNC ID for HBA1 is %i\n", HBA1.hgnc);

   struct gene *pointer;

   pointer = &HBA1;
   printf("The OMIM ID for HBA1 is %i\n", pointer->omim);

   return 0;
}
```

Strings
=======

C has no data type for strings; instead an array of characters is used: [C-style strings](http://www.cprogramming.com/tutorial/c/lesson9.html) are always terminated with a null character, a '\0' character (with the value of 0). The string below can store 99 letters.

```c
char string[100];
```

Use fgets to read in a string from stdin:

```c
#include <stdio.h>

int main(){
   char string[256];                               

   printf("Please a string: ");
   fgets(string, 256, stdin);           
   printf( "You this string, %s", string );

   return 0;
}
```

`string.h` is a header file that contains many functions for manipulating strings. Some examples are below.

```c
// string comparison
int strcmp (const char *s1, const char *s2);

// string concatenation
char *strcat (char *dest, const char *src);

// string copying
char *strcpy (char *dest, const char *src);

// length of string
size_t strlen (const char *s);
```

File input/output
=================

For [C File I/O](http://www.cprogramming.com/tutorial/cfileio.html) you need to use a FILE pointer; you can think of it as the memory address of the file or the location of the file. Use `fopen` to obtain the FILE pointer, which allows you to perform functions on the file.

```c
FILE *fopen(const char *filename, const char *mode);
```

Code to open and read a file (see `read_file.c`):

```c
#include <stdio.h>

int main(){

   FILE *fr;
   char buff[255];

   fr = fopen("etc/transcript.txt", "r");

   while(fgets(buff, 255, fr) != NULL){
      printf ("%s", buff);
   }
   
   fclose(fr);

   return 0;
}
```

Libraries
=========

C supports the notion of modular programming and statements for a particular program can be split across many logically grouped files. For example, if your statements are split across three files:

```bash
gcc mod1.c mod2.c main.c -o dbtest
```

To call a function that resides in another file, always make certain to include a prototype declaration so the compiler knows the function's argument types and the type of the return value.

Functions contained in separate files can communicate through external variables, an extension to global variables.

You can group all your commonly used definitions inside an include file and include said file in any program that requires those definitions.

The Unix utility `ar` can be used to create your own libraries, which is useful for creating a bunch of utility functions that are frequently used. You can use the option `-llib` to link your own library and functions are pulled from the library and linked together with your program during the linking phase.

Rosalind
========

I am attempting to solve [Rosalind problems](http://rosalind.info/problems/list-view/) using C. The solutions will be stored in the rosalind folder.

Links
=====

* [C Programming Tutorial](https://randu.org/tutorials/c/index.php)
* [The Basics of C Programming](https://computer.howstuffworks.com/c.htm)
* [My notes](http://davetang.org/wiki2/index.php?title=C).

