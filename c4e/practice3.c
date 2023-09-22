#include <stdio.h>

void noise();

int main() {
  /*
  Boolean - True or False
  < - Less than (relational)
  > - Greater than (relational)
  <= - Less than or equal to (relational)
  >=  - Greater than or equal to (relational)
  == - Equal to (equallity)
  != - Not equal to (equallity)

  Logical Operators
  && - And
  || - Or
  ! - Not
  */
  int a = 1;
  int b = 4;
  char letter ='A';
  double c = 6;
  double x = 1 / (double) b * c;
  printf("x = %.1lf\n", x);

  noise();

  int num1;
  int num2;

  printf("Enter two values: ");
  scanf("%d %d",&num1,&num2);

  //without Curly braces aka Control Structures
  if(num1 < num2)
      printf("%d is smaller than %d. \n",num1,num2);//If True
  else
      printf("%d is smaller than %d. \n",num2,num1);//If false

  //With Curly braces aka Control Structures
  if(num1 > num2) {
    printf("%d is greater than %d\n",num1,num2);
  }
  else if(num1 < num2) {
    printf("%d is smaller than %d \n",num1,num2);
  }
  else {
    printf("%d is equal to %d \n",num1,num2 );
  }

  switch (num1) { // Switch cases are normally used to check equallity of value
    case 3:
      printf("num1 = 3\n");
      break;

    case 4:
      printf("num1 = 4\n");
      break;

    default:
      printf("num1 is not 3 or 4\n");
      break;
  }

  switch (letter) {
    case 'A': // If letter = A or letter = a. Like an or statment
    case 'a':
      printf("A!\n");
      break;

    case 'B':
      printf("B!\n");
      break;

    default:
      printf("letter is not A or B\n");
  }
  // You can cast letters as a int to get the letter's Acsi key value. 'a' = 97
  //check powerpoint for grouping/precendece 9/19/22

  return 0;
}
void noise() {
  int lvl;

  printf("Enter noise level: ");
  scanf("%d",&lvl);

  if (lvl < 50) {
    printf("Noise level is quite \n");
  }
  else if (lvl >= 51 && lvl <= 70) {
    printf("Noise level is intrusive\n");
  }
  else if (lvl >=71 && lvl <=90) {
    printf("Noise level is annoying\n");
  }
  else if (lvl >= 91 && lvl <=110) {
    printf(" Noise level is very annoying\n");
  }
  else {
    printf("Nosie level is uncomfortable\n");
  }
  /*
  Nested statments that mimic the && operator
    if(lvl < 50)
      if(lvl >= 51 && lvl <= 70)
        if(lvl >=71 && lvl <=90)
          if(lvl >= 91 && lvl <=110)
            else
  */
}
