#include <stdio.h>

int main(){
   float answer;

   printf("What is the square root of 2?\n");
   scanf("%f", &answer);

   /* printf("You answered %f\n", answer); */

   /*
      1.41421356237309504880168872420969807856967187537694807317667973799073247846210
      7038850387534327641572735013846230912297024924836055850737212644121497099935831
      4132226659275055927557999505011527820605714701095599716059702745345968620147285
      1741864088919860955232923048430871432145083976260362799525140798968725339654633
      1808829640620615258352395054745750287759961729835575220337531857011354374603408
      4988471603868999706990048150305440277903164542478230684929369186215805784631115
      9666871301301561856898723723528850926486124949771542183342042856860601468247207
      7143585487415565706967765372022648544701585880162075847492265722600208558446652
      1458398893944370926591800311388246468157082630100594858704003186480342194897278
      2906410450726368813137398552561173220402450912277002269411275736272804957381089
      6750401836986836845072579936472906076299694138047565482372899718032680247442062
      9269124859052181004459842150591120249441341728531478105803603371077309182869314
   */

   if (answer >  1.4141 && answer < 1.4143){
      printf ("Correct!\n" );
   } else if (answer > 1 && answer < 2){
      printf("You are close!\n");
   } else {
      printf("Wrong!\n" );
   }

   return 0;
}
