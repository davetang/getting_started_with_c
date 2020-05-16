#include <stdio.h>
#include <string.h>

int main(void)
{

   /*
      http://en.wikipedia.org/wiki/C_data_types
      In the C programming language, data types refers to an extensive system for declaring variables of different types.
      The language itself provides basic arithmetic types and syntax to build array and compound types.
      Several headers in the standard library contain definitions of support types, that have additional properties, such as exact size, guaranteed.
      The C language provides many basic types.
      Most of them are formed from one of the four basic arithmetic type specifiers in C (char, int, float and double), and optional specifiers (signed, unsigned, short, long).
      http://www.learnconline.com/2010/04/data-types-in-c-programming-language.html
   */

   /*
      Declaring all my variables before any statements to adhere to ISO C90, which forbids mixing declarations and code
   */

   /*
     float is used to define floating type numbers. It occupies 4 bytes of memory (16-bit compiler) can be defined using float and double
   */
   float my_float;

   /*
      int is used to define integer numbers. It occupies 2 bytes of memory (16-bit compiler)
      integers can be defined using char, int, short, long or long long
      Unsigned integers are whole numbers that can only be positive
      defined using unsigned char, unsigned int, unsigned short, unsigned long or unsigned long long
   */
   int my_integer;

   /*
      double is used to store big floating point numbers. It reserves 8 bytes of memory (16-bit compiler)
   */
   double my_double;

   /*
      char is used to store characters. It occupies 1 byte of memory (16-bit compiler)
   */
   char my_char;

   /*
   The modifiers define the amount of storage allocated to the variable.
   int, float and double have the following four modifiers.
      1. short
      2. long
      3. signed
      4. unsigned
   */
   long double my_long_double;

   /*
      use pointer to a character array to define a simple string; but this string can only be read
      define string as a local character array, to be able to manipulate it
   */
   char * seq_read = "ATCAGTAGACCAGT";

   /*
      local array
      empty brackets tells the compiler to calculate the size of the array automatically
   */
   char seq[] = "ATCAGTAGACCAGT";

   /*
      Size of array using sizeof()
      http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c

   */
   int first = sizeof(seq);
   int second = sizeof(seq[0]);
   int third = first/second;

   /* define an array of 3 integers */
   int number[3];

   my_integer = 5;
   printf("my_integer -> %i\n", my_integer);

   my_float = 1.200000001;
   printf("my_float -> %f\n", my_float);

   my_double = 1.2000000000001;
   printf("my_double -> %f\n", my_double);

   my_char = 'A';
   printf("my_char -> %c\n", my_char);

   my_long_double = 1.2000000000001;
   printf("my_long_double -> %Lf\n", my_long_double);

   /*
      http://stackoverflow.com/questions/5739888/what-is-the-difference-between-signed-and-unsigned-int
      C uses arrays of characters to define strings
      Arrays are special variables that can hold more than one value using the same variable, using an index.
   */

   number[0] = 5;
   number[1] = 10;
   number[2] = 20;

   printf("The second number in the array is %d\n", number[1]);

   /* use printf to format a string */
   printf("Read only seq: %s\nWrite seq: %s\n", seq_read, seq);

   printf("%d\t%d\t%d\n", first, second, third);

   /*
      The function strncmp compares two strings and returns 0 if they are equal
      or we can simply use strncmp(seq_read, seq) without the length of the array
   */

   if (strncmp(seq_read, seq, (sizeof(seq)/sizeof(seq[0])-1) ) == 0){
      printf("seq_read and seq are equal\n");
   } else {
      printf("seq_read and seq are not equal\n");
   }

   return 0;
}

