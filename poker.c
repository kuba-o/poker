#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pattern {
    int computerScore;
    int playerScore;
    char p;
    int obtained;
    char *name;
  };

struct pattern table[15];

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
  system("clear");
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

void getScore(struct pattern table[15], int countAmount[5]){
  
}

void playerMove(int die[5], int *rerollCount, int countAmount[5]){
  while (*rerollCount<2){
    reroll(die, rerollCount);
    showDies(die);
  }
  countDies(die, countAmount);
}

int main(){

  srand(time(NULL));

  int i;
  int die[5];
  int countAmount[5];
  int *rerollCount, count = 0;
  rerollCount = &count;
  
  //TU COPY1

  char *names[]={"ones", "twoes", "threes", "fours", "fives", "sixes", "pair", "pairs", "triple", "mStreet", "bStreet", "full", "quadlet", "poker", "chance"};

  struct pattern ones;
  struct pattern twoes;
  struct pattern threes;
  struct pattern fours;
  struct pattern fives;
  struct pattern sixes;
  struct pattern pair;
  struct pattern pairs;
  struct pattern triple;
  struct pattern mStreet;
  struct pattern bStreet;
  struct pattern full;
  struct pattern quadlet;
  struct pattern poker;
  struct pattern chance;

  //TU COPY2
  
  table[0]=ones;
  table[1]=twoes;
  table[2]=threes;
  table[3]=fours;
  table[4]=fives;
  table[5]=sixes;
  table[6]=pair;
  table[7]=pairs;
  table[8]=triple;
  table[9]=mStreet;
  table[10]=bStreet;
  table[11]=full;
  table[12]=quadlet;
  table[13]=poker;
  table[14]=chance;
  
  for (i=0; i<15; i++){
    table[i].name = names[i];
  }

  char z = 'a';
  for (i=0; i<15; i++){
    table[i].playerScore=-1;
    table[i].computerScore=-1;
    table[i].p=z;
    z++;
    table[i].obtained = 0;
  }
  system("clear");
  getScore(table, countAmount);
  fillRandomDies(die);
  showDies(die);

  playerMove(die, rerollCount, countAmount);

  return 0;
}