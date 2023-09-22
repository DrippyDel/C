//Delali Ekpeh
//Dr.Steinberg
//COP3223 Section 1
//Large Program 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Macro Constant
#define ROUNDS 3

//Prototypes
void greeting(); //display welcome message to user
int playRound(int round); //play one round
int humanPick(); //retrieve the user's guess
int computerPick(int choice, int leftover); //computer makes its pick
int leftOnTable(int toothpicks, int taken); //calculate number of toothpicks left
void winnerAnnouncment(int user); //overall winner of round announcement

int main() {

  greeting();
  for(int x = 0; x < ROUNDS; ++x) {
    int result = playRound(x +1); //calls playRound and assigns result the value function returns

    if(result == 5){
      winnerAnnouncment(5);
    }//end of if(result == 5)

    else if(result == 6) {
      winnerAnnouncment(6);
    }//end of else if(result == 6)

  }//end of for(int x = 0; x < ROUNDS; ++x)

  printf("********************************************************\n");
  printf("Thank you for playing! \n");

  return 0;
}

void greeting() {
  printf("********************************************************\n");

  printf("Welcome to Toothpick Game!\n");
  printf("Here are the rules.\n");
  printf("There are currently 31 toothpicks on the table.\n");
  printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n");
  printf("The player that gets to pick the last toothpicks loses the game!\n");
  printf("Sounds easy right? Well lets see if you can beat me!\n");
  printf("Ready to play?...Here we go!\n");

  printf("********************************************************\n");

}

int playRound(int round) {

  int picksLeft;
  int humChoice;

  printf("Welcome to a new round. Round %d!\n", round);
  printf("You may go first!\n");
  int toothpicks = 31; //number of toothpicks to start with
      picksLeft = 31; //Restarts number of picksLeft tracker

  //loop that keeps track of toothpicks until respective no more toothpicks
  //left. we will learn about conditional loops soon :)
  while(toothpicks != 0)
    {

      int comChoice;

      printf("********************************************************\n");
      printf("There are %d toothpick(s) left on the table.\n",toothpicks);
      humChoice = humanPick();//User's turn

      if(humChoice > 3 || humChoice < 1) {
        printf("Invaild Choice. Please Choose a number 1-3. \n");
      }//end of if(humChoice > 3 && humChoice < 1)

      else if(humChoice > toothpicks) {
        printf("Invaild Choice. Please Choose from remaining tookpick(s) \n");
        printf("There are %d toothpick(s) left on the table.\n",toothpicks);
      }//end of else if(humChoice > toothpicks)

      else {//else 1
        if(humChoice == picksLeft) {
          return 5;//Random number to send that user lost
        }//end of if(humChoice == picksLeft)

        else if(comChoice==picksLeft) {//Catches if computer chooses 2 or 3 at the end
          return 6;// Random number to send that user has won
        }//end of else if(comChoice==picksLeft)

        else {//else 2

          picksLeft = leftOnTable(toothpicks, humChoice);//calculates how many toothpicks are left after user's turn

          comChoice =  computerPick(humChoice, picksLeft);//Computer's turn
          printf("I am taking %d toothpick(s)\n",comChoice);

          if(comChoice==picksLeft) {//Catches if computer chooses 1
            return 6;
          }//end of if(comChoice==picksLeft)

          else {//else 3
          picksLeft = leftOnTable(picksLeft, comChoice);//calculates how many toothpicks are left after computer's turn
          printf("********************************************************\n");
          toothpicks = picksLeft;
          }//end of else 3
        }//end of else 2
      }//end of else 1

    }//end of while

  return 1;

}

int humanPick() {

  int choice;

  printf("How many toothpicks would you like to take?\n");
  printf("(You can only pick 1-3 toothpick(s)): ");
  scanf("%d",&choice);
  printf("Alright... You have chosen %d \n",choice);

  return choice;
}

int computerPick(int choice, int leftover) {

  int computerChoice;

  printf("I'm making my decision now...\n");
  if(leftover > 4) {
    computerChoice = 4 - choice;
    return computerChoice;
  }// end of if(leftover >= 4)

  else if(leftover == 4) {
    computerChoice = 3;
    return computerChoice;
  }//end of else if(leftover == 4)

  else if(leftover == 3) {
    computerChoice = 2;
    return computerChoice;
  }//end of else if(leftover == 3)

  else if(leftover == 2) {
    computerChoice = 1;
    return computerChoice;
  }//end of  else if(leftover == 2)

  else if(leftover == 1) {
    computerChoice = 1; //The last tookpick
    return computerChoice;
  }//end of else if(leftover == 1)

  else {
    printf("Error something went wrong\n");
    return 0;
  }// end of else
}

int leftOnTable(int toothpicks, int taken) {

  int left;
  left = toothpicks - taken;
  return left;
}

void winnerAnnouncment(int user) {

  if(user == 5) {
    printf("This is my PERFECT VICTORY! Thats right I WIN!\n");//Light Yagami quote to show that the computer has won
  }//end of if(user == 5)

  else if(user == 6) {
    printf("You won! I'll let you have this one...\n");//User has won
  }//end of else if(user ==6)

}
