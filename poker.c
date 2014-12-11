#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ZLE TUTAJ
void fillRandomDies(int die[5]){
  int i;
  printf("Here are your actual values on the dies: \n");
  for (i=0; i<5; i++){
    die[i]=rand()%5+1;
    printf("%i: %i\n", i+1, die[i]);
  }
}

void showDies(int die[5]){
  int i;
  printf("Here are your actual values on the dies: \n");
  for (i=0; i<5; i++)
    printf("%i: %i\n", i+1, die[i]);

}

void reroll(int die[5]){
  int i;
  int reroll[5] = {0, 0, 0, 0, 0};
  char ruch[5] = {0, 0, 0, 0, 0};
  
  printf("Reroll: \n");
  scanf("%s", ruch);
  
  if (ruch[0]!='x'){
    for (i=0; i<5; i++){
      reroll[i] = (int)(ruch[i] - '0');
    }
  }
  
}
int main(){

  srand(time(NULL));

  int i;
  int die[5];
    
    
  fillRandomDies(die);
  showDies(die);
  reroll(die);
  
  showDies(die);
  
  //get numbers of dies to reroll
  
     
  return 0;
}