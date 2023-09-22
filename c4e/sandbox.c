#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

//Prototype
int hum();
int left(int toothpicks, int taken);
int occurancesInWord(char userguess, char answer);


int main() {

  int choice;
  int x;
  int *ptr2 = &x;
  int y;
  int *ptr3 = &y;
  int i= 0;
  double score;
  int result;
  char word [20];
  char starword [20];

  printf("Enter your word: ");
  scanf("%s", word);

  printf("Enter your starWord: ");
  scanf("%s", starword);

  printf(" word is %s \n", word );
  printf("StarWord is %s \n", starword );

  result = occurancesInWord(word[i],starword[i]);

  return 0;
}

int occurancesInWord(char userguess, char answer) {

  printf(" in fun word is %c \n", userguess );
  printf("in fun StarWord is %c \n", answer );

  if(answer != userguess){
    printf(" in fun word is %c \n", userguess );
    printf("in fun StarWord is %c \n", answer );
  }
  

  return 1;
}




int hum(){
  int choice;

  printf("Enter number: ");
  scanf("%d",&choice);

  return choice;
}

int left(int toothpicks, int taken) {

  int total;
  total = toothpicks - taken;
  return total;

}
