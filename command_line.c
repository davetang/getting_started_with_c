#include <stdio.h>

/*
http://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm
Command line arguments are handled using the main() function arguments,
where argc refers to the number of arguments passed,
and argv[] is a pointer array which points to each argument passed to the program.
*/

int main( int argc, char *argv[] )  
{
   int i;
   printf("The number of arguments passed is %d\n", argc);

   /*
   argv[0] is this file
   */

   for(i = 0; i < argc; ++i){
      printf("argv[%d] is %s\n", i, argv[i]);
   }

   return(0);
}
