#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandomDies(int die[5]){
  int i;
  for (i=0; i<5; i++)
    die[i]=rand()%5+1;
}

void showDies(int die[5]){
  int i;
  printf("Here are your actual values on the dies: \n");
  for (i=0; i<5; i++)
    printf("%i: %i\n", i+1, die[i]);
}

void reroll(int die[5], int *rerollCount){
  int i, a;
  (*rerollCount)++;
  char ruch[5] = {-100, -100, -100, -100, -100};
  
  printf("Reroll: \n");
  scanf("%s", ruch);
  i=0;
  
  if (ruch[0]!='x'){
    while (ruch[i]!='\0'){
      a = (int)(ruch[i] - '0');
      die[a-1] = rand()%5+1;
      i++;
    }
  }

  else
    *rerollCount=3;    
}

void countDies(int die[5], int countAmount[5]){
  int i, j;
  for (i=0; i<5; i++)
    countAmount[i]=0;

  for (i=0; i<5; i++){
    for (j=0; j<5; j++){
      if (die[j]==(i+1))  
        countAmount[i]++;
    }
  }
}

void playerMove(int die[5], int *rerollCount, int countAmount[5]){
  while (*rerollCount<3){
    reroll(die, rerollCount);
    showDies(die);
    countDies(die, countAmount);
  }
}

int main(){

  srand(time(NULL));

  int i;
  int die[5];
  int countAmount[5];
  int *rerollCount, count = 0;
  rerollCount = &count;
  
  struct pattern {
    int computerScore;
    int playerScore;
  };

  struct pattern ones;
  
  struct pattern table[15];

  table[0]=ones;

  fillRandomDies(die);
  showDies(die);

  playerMove(die, rerollCount, countAmount);

  return 0;
}

/*

*/