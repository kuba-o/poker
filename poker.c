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
  int i, j;
struct pattern table[15];

void fillRandomDies(int die[5]){
  for (i=0; i<5; i++)
    die[i]=rand()%5+1;
}

void showDies(int die[5]){
  printf("Here are your actual values on the dies: \n");
  for (i=0; i<5; i++)
    printf("%i: %i\n", i+1, die[i]);
}

void reroll(int die[5], int *rerollCount){
  int a;
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

void countDies(int die[5], int countAmount[6]){
  for (i=0; i<6; i++)
    countAmount[i]=0;

  for (i=0; i<6; i++){
    for (j=0; j<6; j++){
      if (die[j]==(i+1))  
        countAmount[i]++;
    }
  }
}

void getScore(int die[5], struct pattern table[15], int countAmount[6]){
  if (countAmount[0]!=0){
    printf("To chose the \"%s\" category, press %c.\n", table[0].name, table[0].p);
  }

  if (countAmount[1]!=0){
    printf("To chose the \"%s\" category, press %c.\n", table[1].name, table[1].p);
  }

  if (countAmount[2]!=0){
    printf("To chose the \"%s\" category, press %c.\n", table[2].name, table[2].p);
  }

  if (countAmount[3]!=0){
    printf("To chose the \"%s\" category, press %c.\n", table[3].name, table[3].p);
  }

  if (countAmount[4]!=0){
    printf("To chose the \"%s\" category, press %c.\n", table[4].name, table[4].p);
  }

  if (countAmount[5]!=0){
    printf("To chose the \"%s\" category, press %c.\n", table[5].name, table[5].p);
  }

  //pair
  for (i=5; i>-1; i--){ 
    if (countAmount[i]>1){
      printf("To chose the \"%s\" category, press %c.\n", table[6].name, table[6].p);
      //printf("WYNIK TO %d\n", 2*die[i]);
      break;
    }
  }
  int done = 0;
  
  //pairs
  for (i=5; i>-1; i--){
    for (j=5; j>-1; j--){
      if (countAmount[i]>1 && countAmount[j]>1 && i!=j){
        printf("To chose the \"%s\" category, press %c.\n", table[7].name, table[7].p);
        done++;
        break;
      }
      if(done!=0)
        break;
    }
  }
  done = 0;
  
  //triple
  for (i=5; i>-1; i--){ 
    if (countAmount[i]>2){
      printf("To chose the \"%s\" category, press %c.\n", table[8].name, table[8].p);
      //printf("WYNIK TO %d\n", 2*die[i]);
      break;
    }
  }
  //mStrit
  if(countAmount[0]==1 && countAmount[1]==1 && countAmount[2]==1 && countAmount[3]==1 && countAmount[4]==1){
      printf("To chose the \"%s\" category, press %c.\n", table[9].name, table[9].p);
  }

  //dStrit
  if(countAmount[1]==1 && countAmount[2]==1 && countAmount[3]==1 && countAmount[4]==1 && countAmount[5]==1){
      printf("To chose the \"%s\" category, press %c.\n", table[10].name, table[10].p);
  }
  //full
  for (i=5; i>-1; i--){
    for (j=5; j>-1; j--){
      if (countAmount[i]==3 && countAmount[j]==2 && i!=j){
        printf("To chose the \"%s\" category, press %c.\n", table[11].name, table[11].p);
        done++;
        break;
      }
      if(done!=0)
        break;
    }
  }
  //quadlet
  for (i=5; i>-1; i--){ 
    if (countAmount[i]>3){
      printf("To chose the \"%s\" category, press %c.\n", table[12].name, table[12].p);
      break;
    }
  }

  //poker
  for (i=0; i<6; i++){
    if (countAmount[i]==5){
      printf("To chose the \"%s\" category, press %c.\n", table[13].name, table[13].p);
    }
  }

  //chance
  int chance = 0;
  for (i=0; i<6; i++){ 
    chance+=die[i];
  }
      printf("To chose the \"%s\" category, press %c.\n", table[14].name, table[14].p);  
}

void playerMove(int die[5], int *rerollCount, int countAmount[6]){
  while (*rerollCount<2){
    reroll(die, rerollCount);
    showDies(die);
  }
  countDies(die, countAmount);
  getScore(die, table, countAmount);
}

int main(){

  srand(time(NULL));

  int die[5];
  int countAmount[6];
  int *rerollCount, count = 0;
  rerollCount = &count;

  char *names[]={"ones", "twoes", "threes", "fours", "fives", "sixes", "pair", "pairs", "triple", "mStrit", "bStrit", "full", "quadlet", "poker", "chance"};
  struct pattern ones;
  struct pattern twoes;
  struct pattern threes;
  struct pattern fours;
  struct pattern fives;
  struct pattern sixes;
  struct pattern pair;
  struct pattern pairs;
  struct pattern triple;
  struct pattern mStrit;
  struct pattern bStrit;
  struct pattern full;
  struct pattern quadlet;
  struct pattern poker;
  struct pattern chance;
  
  table[0]=ones;
  table[1]=twoes;
  table[2]=threes;
  table[3]=fours;
  table[4]=fives;
  table[5]=sixes;
  table[6]=pair;
  table[7]=pairs;
  table[8]=triple;
  table[9]=mStrit;
  table[10]=bStrit;
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
  fillRandomDies(die);
  showDies(die);
  playerMove(die, rerollCount, countAmount);

  return 0;
}