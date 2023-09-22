//Delali Ekpeh
//Dr. Steinberg
//COP3223C Section 1
//Small Program 3
#include <stdio.h>

//Prototypes
void letters();
void greenLawyer();
void coordinates(double x, double y);
int triangle(int b, int c, int a);

int main() {

  //Declaration
  double x;
  double y;
  int a;
  int b;
  int c;
  int value;

  letters(); //Function call that checks for lower/uppercase charaters and non letters.

  greenLawyer(); //Function call that calls 1-877-SHE-HULK

  printf("Enter the x-coordinate: ");
  scanf("%lf",&x);

  printf("Enter the y-coordinate: ");
  scanf("%lf",&y);

  coordinates(x,y);

  printf("Enter three sides separated by a whitespace: "); // Ex: 1 2 3
  scanf("%d %d %d",&b,&c,&a);

  value = triangle(b,c,a); //Fucntion call that checks for a vaild triangle.

  if(value == 1) {
    printf("Triangle!\n");
  }// End of if(value == 1)

  else {
    printf("Not Triangle!\n");
  }// End of else

  return 0;
}
void letters() {
  char key;

  printf("Enter a key from the keyboard: ");
  scanf("%c",&key);

  if(key >= 'a' && key <= 'z') { //Checks btw a - z
    printf("Lower!\n");
  }//end of if(key >= 'a' && key <= 'z')

  else if(key >= 'A' && key <= 'Z') { //Checks btw A - Z
    printf("Upper!\n");
  }//end of  else if(key >= 'A' && key <= 'Z')

  else {
    printf("Not a Letter!\n");
  }//end of else

}
void greenLawyer() {

  int selection;

  printf("Hi! Thank you for calling the Superhuman Law Division at GLK&H!\n");
  printf("Our associates are currently working hard for super people like you.\n");
  printf("Please listen carefully to the options of who you would like to speak to in regards to your situation.\n");

  //Options
  printf("Option 1: Fined for thousands of dollars worth of damage to the city you were trying to protect.\n");
  printf("Option 2: Accidentally create a sentient robot who got the feels and tried to destroy the world.\n");
  printf("Option 3: You are an Asgardian god who unintentionally leaves a giant burning imprint on private\nproperty every time you visit Earth.\n");
  printf("Option 4: You just gained new superhero strength that is not recognized by the department of\ndamage control, and they are chasing you down after you performed a good deed.\n");
  printf("Option 5: Your secret identity was revealed by a notorious person and now your personal life\nis no longer the same.\n");
  printf("Option 6: Another super being issue that was not mentioned previously in the options given.\n");

  printf("Selection: ");
  scanf("%d",&selection);

  switch (selection) { //For each option a corresponding case would print
    case 1:
      printf("You have selected option 1. Do not worry! I will make sure you don't give up that green.\n");
      break;

    case 2:
      printf("You have selected option 2. Do not worry! You probably had a good intention that just didn't work out properly.\n");
      break;

    case 3:
      printf("You have selected option 3. Do not worry! I understand you like to make a grand entrance.\n");
      break;

    case 4:
      printf("You have selected option 4. Do not worry! We will talk to the department of damage control.\n");
      break;

    case 5:
      printf("You have selected option 5. Do not worry! We will make sure that you are protected. Please be cautious if you decide to seek Dr. Strange's help.\n");
      break;

    case 6:
      printf("You have selected option 6. Do not worry! I will make sure to use my superhero mind to solve your super problem!\n");
      break;

    default:
      printf("I'm sorry. I don't recognize that super being option.\n");
  }//End of switch statement

}
void coordinates(double x, double y) {

  if(x > 0 && y > 0) {// If x is positive and y is positive
    printf("(%.2lf, %.2lf) is in quadrant I.\n",x,y);
  }//End of if(x > 0 && y > 0)

  else if(x < 0 && y > 0) { // If x is negative and y is positive
    printf("(%.2lf, %.2lf) is in quadrant II.\n",x,y);
  }//End of else if(x < 0 && y > 0)

  else if(x < 0 && y < 0) {// If x is negative and y is negative
    printf("(%.2lf, %.2lf) is in quadrant III.\n",x,y);
  }//End of else if(x < 0 && y < 0)

  else if(x > 0 && y < 0) { // If x is positive and y is neagative
    printf("(%.2lf, %.2lf) is in quadrant IV.\n",x,y);
  }//End of else if(x > 0 && y < 0)

  else if(x == 0 && y == 0) {// If x and y are eqaul to 0
    printf("(%.2lf, %.2lf) is at the origin.\n",x,y);
  }//End of else if(x == 0 && y == 0)

}
int triangle(int b, int c, int a) {

  printf("Checking these logistics from the input.\n");

  printf("%d + %d > %d\n",b,c,a);
  printf("%d + %d > %d\n",b,a,c);
  printf("%d + %d > %d\n",c,a,b);

  if(b + c > a && a + b > c && a + c > b) { // If (b + c > a) and (a + b > c) and (a + c > b)
    return 1;
  }//End of if(b + c > a && a + b > c && a + c > b)

  else {
    return -1;
  }//End of else

}
