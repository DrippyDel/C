//Delali Ekpeh
//Dr. Steinberg
//COP3223 Section 1
//Large Program 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 20

//Prototype
void rules(); //Displays rules of the game
void maskword(char starword[], int size); //Mask the word with stars to display
int playround(char starword[], char answer[]); //Play a round of Hangman
int occurancesInWord(char userguess, char answer[]); //Number of times letter occurs in word
void updateStarWord(char starword[], char answer[], char userguess); //Replaces respective * character
void playAgain(int *play); //Ask user if to play again. 1 is yes 2 is no


int main() {

  char word[MAX_SIZE];
  FILE *fptr;
  int size;

  rules();

  fptr = fopen("words.txt", "r");

  if(fptr == NULL) {
    printf("File did not open correctly \n");
  }

  while(fscanf(fptr, "%s", word) != -1) { //scans till end of file
    size = strlen(word);
    maskword(word,size);
  }

  fclose(fptr);

  return 0;
}

void rules() {
  printf("Welcome to the Hangman Game! \n");
  printf("************************************************************************\n");
  printf("Here are the rules. \n");
  printf("I will provide you a set of * characters for each round. \n");
  printf("Each * represents a letter in the English Alphabet. \n");
  printf("You must figure out each letter of the missing word. \n");
  printf("For every correct letter guessed, I will reveal its place in the word. \n");
  printf("Each mistake will result in a strike. \n");
  printf("6 strikes will result in a loss that round. \n");
  printf("Are you ready? Here we go! \n");
  printf("************************************************************************\n");
}

void maskword(char starword[], int size) {

  char word [MAX_LINES];
  int result = 0;

  strcpy(word,starword);// word is now starword
  memset(starword,'*',size); // Starword is now * characters

  result = playround(starword, word);
  playAgain(&result);
  if(result == 2) {
    printf("Thank you for playing today! \n");
    exit(0);//terminates program
  }
}

int playround(char starword[], char answer[]) {

  int size = strlen(starword);
  int j = 0;
  int y = 0;
  int strikes = 0;
  int result2 = 0;
  char guess[MAX_SIZE];
  char guessed[MAX_SIZE];
  guessed[x] = '\0';

  printf("Welcome to the Round! \n");
  printf("The size of the word has %d letters. \n\n", size);

  while(j != 1) {

    result2 = strcmp(starword,answer);//Compares the new starword to the answer
    if(result2 == 0) {
      printf("Congratulations! You Won! The word was %s \n", answer);
      printf("************************************************************************\n");
      j = 1;
      break;
      return 1;
    }
    if(strikes == 6) {
      printf("Sorry you did not win the round. The word was %s \n", answer);
      printf("************************************************************************\n");
      j = 1;
      break;
      return 1;
    }

    printf("You currently have %d strike(s). \n", strikes);
    printf("Letter(s) you have guessed: %s \n\n", guessed);
    printf("%s \n\n", starword);

    printf("Enter your guess: ");
    scanf("%s", guess);

    guess[y] = tolower(guess[y]);//Makes all alphabet inputs lowercase.

    guessed[x] = guess[y];//Saves the guesses the user has made this round
    guessed[x + 1] = '\0';//Prevents random grabage values from being inputed

    int result = occurancesInWord(guess[y],answer);

    if(result >= 1) {
      printf("The letter %s is in the word \n\n", guess);
      updateStarWord(starword, answer, guess[y]);
    }
    else {
      printf("The letter %s is NOT in the word \n\n", guess);
      strikes++;
    }
  }
  return 1;
}

int occurancesInWord(char userguess, char answer[]) {

  int size = strlen(answer);
  int count = 0;

  for(int i = 0; i < size; i++) { //Loops through answer to check if guess matches
    if(answer[i] == userguess){
      count++;
    }
    // else {
    //   return 0;
    // }
  }
  return count;

}

void updateStarWord(char starword[], char answer[], char userguess) {

  int size = strlen(answer);

  for(int i = 0; i < size; i++) { //Loops through answer to check if guess matches
    if(answer[i] == userguess){   //if guess do match then guess replaces that index in answer
      starword[i] = userguess;
    }
  }
}

void playAgain(int *play) {

  int choice;
  int i = 1;

  printf("Would you like to play another round? \n");
  while(i != 0) {
    printf("1. Yes \n");
    printf("2. No \n");
    printf("Choice: ");
    scanf("%d", &choice);
    printf("************************************************************************\n");
    if(choice == 1 || choice == 2) {
    *play = choice;
    i = 0;
    }
    else{
      printf("Invaild choice please pick 1 or 2: \n");
      i = 1;
    }
  }
}
