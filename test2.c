#include <stdio.h>
#include <stdlib.h>

int i,j;

void fillRandomDies(int die[5]){
  for (i=0; i<5; i++)
    die[i]=rand()%6+1;
}

void showDies(int die[5]){
  printf("Here are your actual values on the dies: \n");
  for (i=0; i<5; i++)
    printf("%i: %i\n", i+1, die[i]);
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
    countAmount[i]=countAmount[i]/2;
  }
}


int main(){

	int die[5];
	int countAmount[6];

	fillRandomDies(die);
	showDies(die);
	resetCounted(die, countAmount);
	countDies(die, countAmount);

for (i=0; i<6; i++)
      printf("THE countAmount of %d is %d\n", i+1, countAmount[i]);
	return 0;
}