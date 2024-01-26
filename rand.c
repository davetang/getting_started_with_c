#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   srand(time(NULL));
   // printf("RAND_MAX = %u\n", RAND_MAX);
   // RAND_MAX = 2147483647

   int N = 10;
   if (argc > 1){
      char *a = argv[1];
      N = strtol(a, &a, 10);
   }

   for (int i = 0; i < N; i++) {
      // between 0 to RAND_MAX
      int random = rand();
      printf("%d\n", random);
   }

   return 0;
}
