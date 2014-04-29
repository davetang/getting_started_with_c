#include <stdio.h>

int main(void)
{
   /* http://www.learnconline.com/2010/04/data-types-in-c-programming-language.html */

   /* int is used to define integer numbers. It occupies 2 bytes of memory (16-bit compiler) */
   int my_integer;
   my_integer = 5;
   printf("my_integer -> %i\n", my_integer);

   /* float is used to define floating type numbers. It occupies 4 bytes of memory (16-bit compiler) */
   float my_float;
   my_float = 1.200000001;
   printf("my_float -> %f\n", my_float);

   /* double is used to store big floating point numbers. It reserves 8 bytes of memory (16-bit compiler) */
   double my_double;
   my_double = 1.2000000000001;
   printf("my_double -> %f\n", my_double);

   /* char is used to store characters. It occupies 1 byte of memory (16-bit compiler) */
   char my_char;
   my_char = 'A';
   printf("my_char -> %c\n", my_char);

   /*
   The modifiers define the amount of storage allocated to the variable.
   int, float and double have the following four modifiers.
      1. short
      2. long
      3. signed
      4. unsigned
   */

   long double my_long_double;
   my_long_double = 1.2000000000001;
   printf("my_long_double -> %Lf\n", my_long_double);

   return 0;
}
