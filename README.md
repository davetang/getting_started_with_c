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

Rosalind
--------

I am attempting to solve [Rosalind problems](http://rosalind.info/problems/list-view/) using C. The solutions will be stored in the rosalind folder.

Links
-----

Some notes on my [Wiki](http://davetang.org/wiki2/index.php?title=C).

