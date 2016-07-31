#include <stdio.h>

int main(){ 
   int x = 31;
   int *p;

   p = &x;

   printf("The memory location of x is %p\n", p );
   printf("The pointer, p, points to the value %d\n", *p );

   return(0);
}

