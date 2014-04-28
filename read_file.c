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
    printf("%s", line);
  }

  fclose(ifp);

  return 0;
}
