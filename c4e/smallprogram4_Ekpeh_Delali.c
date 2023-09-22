//Delali Ekpeh
//Dr. Steinberg
//COP3223C Section 1
//Small Program 4
#include <stdio.h>


//Prototype
void perfectSquare();//Function that prints a square based on the user's input
void elevator();//Function that User choses which floor to go on
void pyramid();//Function that prints a pyramid based on the user's input
double classAvg(int students);//Fucntion that calculates class average on exam

int main() {

  int i;
  int students;
  double x;

  perfectSquare();
  elevator();
  pyramid();

  while(i != 0) {
  printf("How many students are in the class: ");
  scanf("%d",&students);

  if(students <= 0 ){
    printf("Invalid input. Please try again. \n");
  }//end if(steps <= 0)

    else {
    x = classAvg(students);
      i = 0;//end loop
    }//end else
  }//end while

  printf("The class average on the field trip exam was a %.4lf%% \n",x);
  return 0;
}

void perfectSquare() {

  int number;
  int count;
  int countTwo;
  int i;

  while(i != 0) {
  printf("How big would you like the square to be?: ");
  scanf("%d",&number);

    if(number <= 0) {

      printf("Invalid Input. Please try again. \n");
    }//end of if(number <= 0)

    else {
      i = 0;//ends loop
    }
  }//end while

  for(count = 1; count <= number; count++){

    for(countTwo = 1; countTwo <= number; countTwo++){

      if(count == 1 || count == number || countTwo == 1 || countTwo == number) { //Printing the * depending on what the value "number" holds
        printf("*");
      }//end of if(count == 1 || count == number || countTwo == 1 || countTwo == number)

      else {
         printf(" ");
      }//end of else

    }//end of for(countTwo = 1; countTwo <= number; countTwo++)
    printf("\n");
  }//end of for(count = 1; count <= number; count++)
}

void elevator() {

  int floor;
  int count =1;

  printf("Welcome to the Elevator Ride. \n");

  while(count != 0) {

      printf("Which floor would you like to go to? ");
      scanf("%d",&floor);

      if(floor == 1) {
        printf("Welcome to the first floor. \n");
      }//end of if(floor == 1)

      else if(floor == 2){
        printf("Welcome to the second floor. \n");
      }//end of else if(floor == 2)

      else if(floor == 3) {
        printf("Welcome to the third floor. \n");
      }//end of else if(floor == 3)

      else if(floor == 4) {
        printf("Welcome to the fourth floor. \n");
      }//end of else if(floor == 4)

      else if(floor == 5) {
        printf("Elevator door is now open. Please exit now.\n");
        count = 0;//ends loop
      }//end of else if(floor == 5)

      else if(floor == 6) {
        printf("Welcome to the sixth floor. \n");
      }//end of else if(floor == 6)

      else if(floor == 7) {
        printf("Welcome to the seventh floor. \n");
      }//end of else if(floor == 7)

      else if(floor == 8) {
        printf("Welcome to the eighth floor. \n");
      }//end of else if(floor == 8)

      else if(floor == 9) {
        printf("Welcome to the ninth floor. \n");
      }//end of else if(floor == 9)

      else if(floor == 10) {
        printf("Welcome to the tenth floor. \n");
      }//end of else if(floor == 10)

      else if(floor == 11) {
        printf("Welcome to the eleventh floor. \n");
      }//end of else if(floor == 11)

      else if(floor == 12) {
        printf("Welcome to the twelfth floor. \n");
      }// end of else if(floor == 12)

      else {
        printf("That is not a valid option. \n");
      }//end of else

  }// end of while
}

void pyramid() {

  int steps;
  int i = 1;
  int count;
  int countTwo;

  while(i != 0) {
  printf("How many steps would you like in the pyramid? ");
  scanf("%d",&steps);

  if(steps <= 0 ){
    printf("Invalid Input. Please try again. \n");
  }//end if(steps <= 0)

    else {
      i = 0;
    }//end else
  }//end while

  for(count = 1; count <= steps; count++){
    printf("-");
    for(countTwo = 1; countTwo < count; countTwo++){ //Builds up the pyramid
      printf("-");
    }//end of for(countTwo = 1; countTwo < count; countTwo++)
    printf("\n");
  }//end of for(count = 1; count <= steps, count++)

  for(count = steps - 1; count >= 1; count--){ //Builds down the pyramid

    for(countTwo = 1; countTwo <= count; countTwo++){
      printf("-");
    }//end of or(countTwo = 1; countTwo <= count; countTwo++)
    printf("\n");
  }//end of for(count = steps - 1; count >= 1; count--)

}

double classAvg(int students){

  double sum;
  double score;
  double avg;
  int x;
  int class;
  class = students;//Keeps track of total students

  for(x = 0; x < students; x++) {

    while(students) {
      printf("Enter the student's test score: ");
      scanf("%lf",&score);

      if(score > 100 || score < 0) {
        printf("Invalid Student Score. Please try again. \n");
      }//end of if(score > 100 || score < 0)

      else {
        sum = sum + score; //Adds each existing score per loop
        students--; //Post decrement of students
      }//end of else

    }//end of while
  }//end of or(x = 0; x < students; x++)
  avg = sum / class;
  return avg;

}
