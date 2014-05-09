#include <stdio.h>


int main ()
{
   /*
      For loops in C are straightforward
   */

   // create array of numbers
   int series[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   int i;

   // loop from 0 to 9
   for (i = 0; i < 10; i++){
      printf("%d\n", series[i]);
   }

   // while loop using a loop directives
   int n = 0;
   while (1){
      n++;
      // skip on odd numbers
      if (n % 2 == 1){
         continue;
      }
      printf("%d is an even number\n", n);
      if (n == 20){
         printf("Reached 20 loops\n");
         break;
      }
   }
  
   return 0;
}
