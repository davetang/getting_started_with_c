Learning C
----------

Why am I learning C? Check out my [blog post](http://davetang.org/muse/2014/04/28/getting-started-with-c/) and this [post](http://blog.revolutionanalytics.com/2016/07/r-moves-up-to-5th-place-in-ieee-language-rankings.html). You can create a PDF of this README using [pandoc](http://pandoc.org/):

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

Conditionals
------------

Use `if`, `else if`, and `else`.

~~~~{.c}
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
~~~~

Loops
-----

There are three types of loops: `for`, `while`, and `do..while`; see `loop.c`.

~~~~{.c}
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
~~~~

Functions
---------

Functions need to be declared right at the start or its prototype. Prototypes are declarations of functions; they are only necessary to alert the compiler about the existence of a function if we don't want to go ahead and fully define the function.

~~~~{.c}
/*
   The general format for a prototype
   return-type function_name (arg_type arg1, ..., arg_type argN); 
*/

int add (int a, int b);

// the actual function
int add (int a, int b){
  return x + y;
}
~~~~

See `function.c` for implementing functions with a variable number of arguments.

Switch case
-----------

Switch case statements are a substitute for long `if` statements that compare a variable to several values.

~~~~{.c}
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
~~~~

Pointers
--------

[Pointers](http://www.cprogramming.com/tutorial/c/lesson6.html) point to specific memory locations.

~~~~{.c}
/*
   The pointer declaration looks like this:
   <variable_type> *<name>;

   For example, you could declare a pointer that stores the
   address of an integer with the following syntax:
*/

int *points_to_integer;
int *pointer1, *pointer2;
~~~~

Below is an example of obtaining the memory location and how to dereference a pointer.

~~~~{.c}
#include <stdio.h>

int main(){ 
   int x = 31;
   int *p;

   p = &x;

   printf("The memory location of x is %p\n", p );
   printf("The pointer, p, points to the value %d\n", *p );

   return(0);
}
~~~~

malloc
------

The function [malloc](http://c-faq.com/malloc/index.html), which resides in the stdlib.h header file, is used to initialise pointers with memory from free store. The argument to malloc is the amount of memory requested (in bytes), and malloc obtains a block of memory of that size and then returns a pointer to the block of memory allocated.

~~~~{.c}
#include <stdlib.h>

float *pointer;
// the sizeof function takes an expression and returns its size
pointer = malloc(sizeof(*pointer)); 

// the free function returns memory to the operating system
free(pointer);
~~~~

Rosalind
--------

I am attempting to solve [Rosalind problems](http://rosalind.info/problems/list-view/) using C. The solutions will be stored in the rosalind folder.

Links
-----

Some notes on my [Wiki](http://davetang.org/wiki2/index.php?title=C).

