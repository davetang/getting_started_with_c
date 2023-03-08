#include <stdio.h>
#include <stdarg.h>

/*
   In C, functions must be first defined before they are used

   They can be either declared first and then implemented later on using a
   header file or in the beginning of the C file

   C functions receive either a fixed or variable amount of arguments

   Functions can only return one value, or none

   The first line of a function definition tells the compiler four things about
   the function (from left to right):

   1. Who can call it
   2. The type of value it returns
   3. Its name
   4. The arguments it takes
*/

int times_ten(int x){
   return x * 10;
}

/*
   Functions with variable argument lists in C using va_list

   http://www.cprogramming.com/tutorial/c/lesson17.html
*/

int product (int size, ... ){   
   int total = 1;
   va_list numbers;

   va_start (numbers, size);

   for ( int x = 0; x < size; x++ ){
      total *= va_arg(numbers, int);
   }
   va_end (numbers);

   return total;
}

/*
   Newton-Raphson method for computing the square root:

   1. Set guess to 1
   2. If |guess^2 - x| < limit, proceed to step 4
   3. Set guess to (x / guess + guess) / 2 and return to step 2
   4. Return guess, which is the approximation of the square root
*/

float abs_ (float x){
   if (x < 0)
      x = -x;
   return x;
}

double sqrt_ (double x){
   // const to declare that a variable's value will not be changed
   const double e = 0.000001;
   double guess = 1.0;
   while ( abs_(guess * guess - x) >= e ){
      printf("Guessing %f\n", guess);
      guess = ( x / guess + guess ) / 2.0;
   }
   return guess;
}

int main (void){
   printf("10 times 10 is %d\n", times_ten(10));

   printf("The product of 1, 2, 3, 4, and 5 is %d\n", product(5, 1, 2, 3, 4, 5));

   printf("The square root of 25 is %f\n", sqrt_(25));
   printf("The square root of 28 is %f\n", sqrt_(28));
  
   return 0;
}
