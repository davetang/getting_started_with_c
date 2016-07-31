#include <stdio.h>

struct gene {
   int entrez;
   int hgnc;
   int omim;
};

int main(){
   struct gene HBA1;
   HBA1.entrez = 3039;
   HBA1.hgnc   = 4823;
   HBA1.omim   = 141800;

   printf("The Entrez ID for HBA1 is %i\n", HBA1.entrez);
   printf("The HGNC ID for HBA1 is %i\n", HBA1.hgnc);

   struct gene *pointer;

   pointer = &HBA1;
   printf("The OMIM ID for HBA1 is %i\n", pointer->omim);

   return 0;
}

