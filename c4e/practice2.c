#include <stdio.h>


//Prototype
int sum(int num1, int num2);
void func(int r, double l, char w);

int global = 20; //Global variable

int main() {
  //Declaration
  int x;
  int a ;
  int b;
  double l = 9.2;
  char w = 'd';

  //Assigment Statment
  printf("Enter two Intergers please: ");
  scanf("%d %d",&a,&b);
  x = sum(a,b);// Pass by value of a and b to num1 and num2


  printf("The sum of %d and %d is = %d \n",a,b,x);
  func(a,l, w);
  /*
  Precondition: num1 and num2 are defined in function sum
  Postcondition: num1= user input num2=user input x=sum of num1 and num2
  */

  {
    int y = 3;
    printf("%lf \n",l); // l is still defined since it's in the same control structure.
  }

  // {} - Control Structure
  //Compound Statment - Two or more statments in a control structure

  return 0;
}

int sum(int num1, int num2) {
  int result = num1 + num2;
  return result;
}
void func(int r, double l, char w) {
  printf("r = %d , l = %.1f , w = %c \n",r,l,w);
}
