/* sscanf example */
#include <stdio.h>

int main ()
{
  char sentence []="chr1 10 44 years old today";
  char str [20];
  int start;
  int end;

  sscanf (sentence,"%s %d %d",str,&start,&end);
  printf ("%s\t%d\t%d\n",str,start,end);
  
  return 0;
}
