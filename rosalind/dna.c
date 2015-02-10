#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 1000

int main()
{
   char s[BUFFERSIZE];
   printf("Please enter DNA string: ");

   fgets(s, BUFFERSIZE , stdin);

   /*remove newline*/
   size_t ln = strlen(s) - 1;
   if (s[ln] == '\n')
   s[ln] = '\0';

   /*
   printf("%s\n", s);
   */

   int a, c, g, t, i;
   char x[1];

   for (i = 0; i < strlen(s); i++){
      /* memcpy(dest, src, strlen(src)+1); */
      memcpy( x, &s[i], 1 );
      *x = toupper(*x);
      switch(*x){
      case 'A':
         ++a;
         break;
      case 'C':
         ++c;
         break;
      case 'G':
         ++g;
         break;
      case 'T':
         ++t;
         break;
      default:
         printf("Skipping unrecognised nucleotide: %s\n", x);
         break;
      }
   }

   printf("%i %i %i %i", a, c, g, t);
   return 0;
}
