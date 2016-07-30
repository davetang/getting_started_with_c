#include <stdio.h>

int main(){
   int input = 4;

   switch (input) {
      case 1:
         printf("Input is %i\n", input);
         break;
      case 2:
         printf("Input is %i\n", input);
         break;
      case 3:
         printf("Input is %i\n", input);
         break;
      case 4:
         printf("Input is %i\n", input);
         break;
      default:
         printf("Input was not 1, 2, 3, or 4!\n");
         break;
   }

   return 0;

}

