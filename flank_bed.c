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
  char chr [30];
  int start;
  int end;
  char id [30];
  int score;
  char strand [2];

  char *my_file_name = argv[1];

  ifp = fopen(my_file_name, mode);

  if (ifp == NULL) {
    fprintf(stderr, "Could not open input file %s!\n", my_file_name);
    exit(1);
  }

  /* http://stackoverflow.com/questions/3501338/c-read-file-line-by-line */
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, ifp)) != -1) {
    /* printf("Retrieved line of length %zu :\n", read); */
    sscanf (line, "%s %d %d %s %d %s", chr, &start, &end, id, &score, strand);
    printf ("%s\t%d\t%d\t%s\t%d\t%s\n", chr, start-200, end+200, id, score, strand);
  }

  fclose(ifp);

  return 0;
}
