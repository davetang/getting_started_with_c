#include <stdio.h>

int main (){

   // create array of numbers
   int series[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

   /*
      loop from 0 to 9 and
      print out series
   */

   int i;
   for (i = 0; i < 10; i++){
      printf("%d\n", series[i]);
   }

   int n = 0;
   while (1){
      n++;

      /*
         On a continue statement, the loop will stop its current iteration,
         update itself and begin to execute again from the top; the condition
         below will skip odd numbers
      */

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
  
   do {
      printf( "I will run once even when a condition is not met\n" );
   } while (0);

   return 0;
}

