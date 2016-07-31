#include <stdio.h>

/*
   r  - open for reading
   w  - open for writing (file need not exist)
   a  - open for appending (file need not exist)
   r+ - open for reading and writing, start at beginning
   w+ - open for reading and writing (overwrite file)
   a+ - open for reading and writing (append if file exists)
*/

int main(){

   FILE *fr;
   char buff[255];

   fr = fopen("etc/transcript.txt", "r");

   if(fr == NULL) {
      perror("Error opening file etc/transcript.txt");
      return(-1);
   }

/*
   fgets(): char *fgets(char *str, int n, FILE *stream)
      str: This is the pointer to an array of chars where the string read is stored
      n: This is the maximum number of characters to be read (including the final null-character). Usually, the length of the array passed as str is used
      stream: This is the pointer to a FILE object that identifies the stream where characters are read from
*/

   while(fgets(buff, 255, fr) != NULL){
      printf ("%s", buff);
   }
   
   fclose(fr);

   return 0;
}

