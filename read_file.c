#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )  
{

  if(argc != 2){
    fprintf(stderr, "Please input one file name\n");
    exit(1);
  }

  FILE *ifp;
  char *mode = "r";
  char chr;
  int start;
  int end;
  int id;
  int score;
  char strand;
  char line[1000];

  char *my_file_name = argv[1];

  ifp = fopen(my_file_name, mode);

  if (ifp == NULL) {
    fprintf(stderr, "Could not open input file %s!\n", my_file_name);
    exit(1);
  }

  while(fgets(line, 80, ifp) != NULL){
    sscanf (line, "%s %d %d %d %d %s", &chr, &start, &end, &id, &score, &strand);
    /* printf ("%c\n", chr); */
  }

  fclose(ifp);

  return 0;
}
