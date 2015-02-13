#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// http://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux/8534275#8534275
char *strrev(char *str)
{
   char *p1, *p2;

   if (! str || ! *str)
      return str;
   for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
      *p1 ^= *p2;
      *p2 ^= *p1;
      *p1 ^= *p2;
   }
   return str;
}

int main( int argc, char *argv[] )
{

   if(argc != 2){
     fprintf(stderr, "Please input a file name\n");
     exit(1);
   }

   char *my_file = argv[1];

   FILE * fp;
   char * line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(my_file, "r");
   if (fp == NULL)
      exit(EXIT_FAILURE);

   int i = 0;

   // printf("Retrieved line of length %zu :\n", read);
   while ((read = getline(&line, &len, fp)) != -1) {
      /*
      printf("Retrieved line of length %zu :\n", read);
      printf("%s", line);
      */

      /*remove newline*/
      size_t ln = strlen(line) - 1;
      if (line[ln] == '\n')
      line[ln] = '\0';

      for (i = 0; i < strlen(line); i++){
         /* memcpy(dest, src, strlen(src)+1); */
         char x;
         memcpy( &x, &line[i], 1 );
         x = toupper(x);
         switch(x){
            case 'A':
               line[i] = 'T';
               break;
            case 'C':
               line[i] = 'G';
               break;
            case 'G':
               line[i] = 'C';
               break;
            case 'T':
               line[i] = 'A';
               break;
            default:
               break;
         }
      }
      printf("%s\n", strrev(line));
   }

   fclose(fp);
   if (line)
      free(line);

   return 0;
}
