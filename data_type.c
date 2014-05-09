#include <stdio.h>

int main(void)
{

   /*
   http://en.wikipedia.org/wiki/C_data_types

   In the C programming language, data types refers to an extensive system for declaring variables of different types.

   The language itself provides basic arithmetic types and syntax to build array and compound types.

   Several headers in the standard library contain definitions of support types, that have additional properties, such as exact size, guaranteed.

   The C language provides many basic types.

   Most of them are formed from one of the four basic arithmetic type specifiers in C (char, int, float and double), and optional specifiers (signed, unsigned, short, long).

   */

   // http://www.learnconline.com/2010/04/data-types-in-c-programming-language.html

   /*
      int is used to define integer numbers. It occupies 2 bytes of memory (16-bit compiler)
      integers can be defined using char, int, short, long or long long
      Unsigned integers are whole numbers that can only be positive
      defined using unsigned char, unsigned int, unsigned short, unsigned long or unsigned long long
   */
   int my_integer;
   my_integer = 5;
   printf("my_integer -> %i\n", my_integer);

   /* float is used to define floating type numbers. It occupies 4 bytes of memory (16-bit compiler) */
   // can be defined using float and double
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

   // http://stackoverflow.com/questions/5739888/what-is-the-difference-between-signed-and-unsigned-int

   /*
      C uses arrays of characters to define strings

      Arrays are special variables that can hold more than one value using the same variable, using an index.
   */

   // define an array of 10 integers
   int number[10];


   return 0;
}
