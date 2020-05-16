#include <stdio.h>
#include <stdarg.h>

/*
   In C, functions must be first defined before they are used

   They can be either declared first and then implemented later on using a header file or in the beginning of the C file

   C functions receive either a fixed or variable amount of arguments

   Functions can only return one value, or none
*/

int multiply_by_ten(int x){
   return x * 10;
}

/*

   Functions with variable argument lists in C using va_list

   http://www.cprogramming.com/tutorial/c/lesson17.html

*/

int multiply (int num, ... ){   
   int total = 0;
   va_list arguments;
   int x;

   va_start (arguments, num);

   for (x = 0; x < num; x++){   
      total *= va_arg(arguments, int);
   }
   va_end (arguments);

   return total;
}

int main (){
   printf("%d\n", multiply_by_ten(10));

   printf("%d\n", multiply(3, 10, 5, 2));
  
   return 0;
}

