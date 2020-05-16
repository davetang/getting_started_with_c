#include <stdio.h>

int main(){ 
   int x = 31;
   int *p = &x;

   printf("The memory location of x is %p\n", (void*)&x );
   printf("The pointer, p, points to the value %d\n", *p );

   return(0);
}

