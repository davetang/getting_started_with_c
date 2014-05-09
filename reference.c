#include <stdio.h>
#include <stdarg.h>

/*
   In C, references or pointers are used for

   * strings
   * dynamic memory allocation
   * sending function arguments by reference
   * building complicated data structures

   a pointer is essentially a simple integer variable which holds a memory address that points to a value

   the computer's memory is a sequential store of data, and a pointer points to a specific part of the memory
*/

int main ()
{
   // dereferencing a pointer is done by using *
   int a = 1;

   // define a pointer variable, and point it to a using &
   int * pointer_to_a = &a;

   printf("The value of a is %d\n", a);
   printf("The value of a using the pointer is %d\n", *pointer_to_a);

   return 0;
}
