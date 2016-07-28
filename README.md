Learning C
----------

Why am I learning C? Check out my [blog post](http://davetang.org/muse/2014/04/28/getting-started-with-c/). You can create a PDF of this README using [pandoc](http://pandoc.org/):

~~~~{.bash}
pandoc README.md -o readme.pdf
~~~~

Getting started
---------------

You will need a compiler, such as `gcc`; I have some notes of my [GitHub page](http://davetang.github.io/2014/11/03/compiling.html) on compiling.

To compile a specific example, type:

~~~~{.bash}
gcc input_output.c -o choose_number
~~~~

or to compile all the examples, type:

~~~~{.bash}
make
~~~~

The binaries will be stored in the bin folder.

Introduction
------------

Here's the source code of a simple C program:

~~~~{.c}
#include <stdio.h>

/*
   This is a comment
*/

int main(){
   printf("Hello world.\n");
   return 0;
}
~~~~

The [include directive](https://en.wikipedia.org/wiki/Include_directive) tells the compiler to put code from the header called stdio.h into our program before creating the executable. The "main" function is called when the C program is executed, thereby running the printf() function. The return is used to tell the operating system whether the program has succeeded or not; a return value of 0 means success. Now to compile and to execute the program.

~~~~{.bash}
gcc hello.c -o say_hello

say_hello 
#Hello world.
~~~~

Data types
----------

Data types are used to store different types of data; basic types include `char`, `int`, and `float`. A variable of type `char` stores a single character; type `int` stores integers; and type `float` stores decimal numbers. The keywords `char`, `int`, and `float` are used to declare a variable. For example, in `data_type.c`:

~~~~{.c}
char my_char;
my_char = 'A';
printf("my_char -> %c\n", my_char);

int my_integer;
my_integer = 5;
printf("my_integer -> %i\n", my_integer);

float my_float;
my_float = 1.200000001;
printf("my_float -> %f\n", my_float);
~~~~

Rosalind
--------

I am attempting to solve [Rosalind problems](http://rosalind.info/problems/list-view/) using C. The solutions will be stored in the rosalind folder.

Links
-----

Some notes on my [Wiki](http://davetang.org/wiki2/index.php?title=C).

