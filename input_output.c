#include <stdio.h>

int main()
{
   int this_is_a_number;
   printf("Please enter a number: ");

   /*
   http://www.cplusplus.com/reference/cstdio/scanf/

   Read formatted data from stdin

   A format specifier for scanf follows this prototype:

   %[*][width][length]specifier 

   To store the result of a scanf operation on a regular variable, its name should be preceded by the reference operator (&)

   */
   scanf("%d", &this_is_a_number);

   printf("You entered %d\n", this_is_a_number);

   /*
   Get character from stdin. This line is included because many compiler environments will open a new console window, run the program, and then close the window before you can see the output. This command keeps that window from closing because the program is not done yet because it waits for you to hit enter. Including that line gives you time to see the program run. 
   */
   getchar();

   return 0;
}
