#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pattern {
    int computerScore;
    int playerScore;
    char p;
    int obtained;
    char *name;
    int maxValue;
    int currentValue;
    float currentValuesPercent;
  };
  int i, j;
struct pattern table[15];

void fillRandomDies(int die[5]){
  for (i=0; i<5; i++)
    die[i]=rand()%6+1;
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
      die[a-1] = rand()%6+1;
      i++;
    }
  }

  else
    *rerollCount=3;
  system("clear");
}

void resetCounted(int die[5], int countAmount[6]){
    for (i=0; i<6; i++)
    countAmount[i]=0;
    
    for (i=0; i<6; i++){
      for (j=0; j<6; j++){
        if (die[j]==(i+1))  
          countAmount[i]++;
      }
    }
}

void countDies(int die[5], int countAmount[6]){
  for (i=0; i<6; i++){
    for (j=0; j<6; j++){
      if (die[j]==(i+1))  
        countAmount[i]++;
    }
  }
}

void theScore(int die[5], struct pattern table[15], int countAmount[6], int number, int canReroll[5]){
  resetCounted(die, countAmount);
  
  int *temp;
  int a = 0;
  temp=&a;
  int value;

  if (number == 0){ //ones
    for (i = 0; i<5; i++){
      if (die[i]!=1)
        canReroll[i]=1;
    }
  }

  if (number == 1){ //twoes
    for (i = 0; i<5; i++){
      if (die[i]!=2)
        canReroll[i]=1;
    }
  }

  if (number == 2){ //threes
    for (i = 0; i<5; i++){
      if (die[i]!=3)
        canReroll[i]=1;
    }  
  }

  if (number == 3){ //fours
    for (i = 0; i<5; i++){
      if (die[i]!=4)
        canReroll[i]=1;
    }
  }

  if (number == 4){ //fives
    for (i = 0; i<5; i++){
      if (die[i]!=5)
        canReroll[i]=1;
    }
  }

  if (number == 5){ //sixes
    for (i = 0; i<5; i++){
      if (die[i]!=6)
        canReroll[i]=1;
    
    }
  }  

  if (number == 6){ //pair
    for (i=0; i<6; i++){
      if (countAmount[i]>1){
        *temp = i+1;
      }
    }
    for (i=0; i<5; i++){
      if (die[i]!=*temp)
        canReroll[i]=1;
    }
  }

  if (number == 7){ //pairs
    int a = -1;
    int b = -1;
      for (i=0; i<6; i++){
        if (countAmount[i]>1){
          a=i;
        }
      }
    
    for (j=0; j<a; j++){
      if (countAmount[j]>1){
        b=j;
      }
    }
    for (i=0; i<5; i++){
      if (die[i]!=a+1  && die[i]!=b+1){
        canReroll[i]=1;
      }
    }
  }

  if (number == 8){ //triple
    for (i=0; i<6; i++){
      if (countAmount[i]>2){
        *temp = i+1;
      }
    }
    for (i=0; i<5; i++){
      if (die[i]!=*temp)
        canReroll[i]=1;
    } 
  }
  /*
  if (number == 9){ //Strit

  }
  
  if (number == 10){ //bStrit
  
  }
    
  if (number == 11){ //full
    int a = -1;
    int b = -1;
    for (i=0; i<6; i++){
        if (countAmount[i]>2){
          a=i;
        }
      }
    
    for (j=0; j<6; j++){
      if (countAmount[j]>1){
        b=j;
      }
    }
    printf("THEBUG: %d     %d\n", a, b);
    for (i=0; i<5; i++){
      if (die[i]!=a+1  && die[i]!=b+1){
        canReroll[i]=1;
      }     
    }
  }
  
  if (number == 12){ //quadlet
    for (i=0; i<6; i++){
      if (countAmount[i]>3){
        *temp=i+1;
      }
    }

    for (i=0; i<5; i++){
      if (die[i]!=*temp)
        canReroll[i]=1;
    }
  }
  */

}

void getScore(int die[5], struct pattern table[15], int countAmount[6]){
    resetCounted(die, countAmount);
    table[0].currentValue=(countAmount[0]-3)*1;

    table[1].currentValue=(countAmount[1]-3)*2;

    table[2].currentValue=(countAmount[2]-3)*3;

    table[3].currentValue=(countAmount[3]-3)*4;
  
    table[4].currentValue=(countAmount[4]-3)*5;

    table[5].currentValue=(countAmount[5]-3)*6;

  //pair
  for (i=0; i<5; i++){
    if (countAmount[i]>1){
      table[6].currentValue=2*(i+1);
    }
  }
  
  int done = 0;
  int i=0;
  int j=0;

  //pairs
  int a=-1;
  int b=-1;
  for (i=0; i<6; i++){
    if (countAmount[i]>1){
      a=i;
    }
  }
  
  for (j=0; j<a; j++){
    if (countAmount[j]>1){
      b=j;
    }
  }
  if (a!=-1 && b!=-1)
    table[7].currentValue=(2*(a+1) + 2*(b+1));

  //triple
  for (i=0; i<5; i++){
    if (countAmount[i]>2){
      table[8].currentValue=3*(i+1);
    }
  }

  //mStrit
  if(countAmount[0]==1 && countAmount[1]==1 && countAmount[2]==1 && countAmount[3]==1 && countAmount[4]==1){
    table[9].currentValue=15; 
  }

  //dStrit
  if(countAmount[1]==1 && countAmount[2]==1 && countAmount[3]==1 && countAmount[4]==1 && countAmount[5]==1){
    table[10].currentValue=20;
  }

  //full
  a=-1;
  b=-1;
  for (i=0; i<6; i++){
    if (countAmount[i]>2){
      a=i;
    }
  }

  for (j=0; j<6; j++){
    if (countAmount[j]==2){
      b=j;
    }
  }
  
  if (a!=-1 && b!=-1){
    table[11].currentValue=3*(a+1) + 2*(b+1) + 10;  
  }

  //quadlet
  for (i=0; i<6; i++){
    if (countAmount[i]>3)
      table[12].currentValue=4*(i+1)+20;
  }
  
  //poker
  for (i=0; i<6; i++){
    if (countAmount[i]==5){
      table[13].currentValue=5*(i+1)+50;
    }
  }

  //chance
  table[14].currentValue=0;
  int chance = 0;
  for (i=0; i<6; i++){ 
    table[14].currentValue+=die[i];
  }
}

void getPattern(int *rerollCount, int countAmount[6], struct pattern table[15]){
  char choice;
  int a;

  //print out possible choices
  for (i = 0; i<6; i++){
    if (table[i].obtained==0){
      printf("%d is a current value of the %s pattern, press %c to chose this score\n",table[i].currentValue, table[i].name, table[i].p);
    }
  }

  for (i=6; i<15; i++){
    if (table[i].obtained==0 && table[i].currentValue!=0){
      printf("%d is a current value of the %s pattern, press %c to chose this score\n",table[i].currentValue, table[i].name, table[i].p);
    }
  }
  printf("If you prefer to cross out a category, press z.\n");
  
  printf("Give me your choice: \n");
  scanf(" %c", &choice);
  a = (int) (choice - 97);

  //while chosen ?
  if (choice == 'z'){
    for (i=0; i<15; i++){
      if (table[i].obtained==0){
        printf("To cross out the %s pattern, press %c. \n", table[i].name, table[i].p);
      }
    }
    scanf(" %c", &choice);
    a = (int) (choice - 97);
    table[a].playerScore=0;
    table[a].obtained=1;
  }

  else{
    while (table[a].obtained==1){
      printf("You can't fill that pattern, chose different: ");
      scanf(" %c", &choice);
      a = (int) (choice - 97);
    }
    if (rerollCount==0){
      table[a].playerScore = 2* table[a].currentValue;  
    }
    table[a].obtained=1;  
  }
} //end of getPattern function

void patternsToGet(struct pattern table[15]){
    system("clear");
  printf("Below are patterns which you are still missing: \n");
  for (i=0; i<15; i++){
    if (table[i].obtained==0)
      printf("%s\n", table[i].name);
  }
  printf("\n");
}

void playerMove(int die[5], int *rerollCount, int countAmount[6]){
  patternsToGet(table); 
  fillRandomDies(die);
  showDies(die);
  
  while (*rerollCount<2){
    patternsToGet(table);
    showDies(die);
    reroll(die, rerollCount);
  }

  countDies(die, countAmount);
  patternsToGet(table);
  showDies(die);
  getScore(die, table, countAmount);
  getPattern(rerollCount, countAmount, table);
  *rerollCount=0;
}

void computerMove(int die[5], struct pattern table[15]){
  int i=0;
  int temp;
  for (i=0; i<15; i++){
    printf("%f procent %s\n", 100*(table[i].currentValue/(table[i].maxValue*1.0)), table[i].name);
    table[i].currentValuesPercent = 100*(table[i].currentValue/(table[i].maxValue*1.0));
  }
  temp = 0;
  for (i=1; i<15; i++){
    if (table[i].currentValuesPercent>=table[temp].currentValuesPercent){
      if (table[i].maxValue > table[temp].maxValue){
        temp = i;
      }
    }
  }
}

int main(){

  srand(time(NULL));

  int die[5];
  int canReroll[] = {0, 0, 0, 0, 0};
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

  //chance is set to 25, free to change
  int maxValues[]={3, 6, 9, 12, 15, 18, 12, 22, 18, 15, 20, 38, 40, 80, 25};
  
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
  
  char z = 'a';
  for (i=0; i<15; i++){
    table[i].name = names[i];
    table[i].maxValue = maxValues[i];
    table[i].currentValue=0;
    table[i].currentValuesPercent=0;
    table[i].playerScore=1;
    table[i].computerScore=-1;
    table[i].p=z;
    z++;
    table[i].obtained = 0;
  }

  system("clear");  
  int test = 11;
  
  playerMove(die, rerollCount, countAmount);

  die[0]=1;
  die[1]=1;
  die[2]=5;
  die[3]=5;
  die[4]=5;
  showDies(die);
  resetCounted(die, countAmount);
  theScore(die, table, countAmount, test, canReroll);

  for (i=0; i<6; i++)
      printf("THE countAmount of %d is %d\n", i, countAmount[i]);

  for (i=0; i<5; i++){
    if (canReroll[i]==1)
      printf("I can reroll %d\n", i);
  }
  return 0;
}