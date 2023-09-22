#include <stdio.h> //Preprocessor directive
#include <math.h> // Allows more complex math functions like trig.

//Prototype
void whatDayisIt(); //example of a function prototype
int favNum();

int main() {

  whatDayisIt(); //Function call
  int num;

  num = favNum(); //prints function not number
  printf("Favorite number is %d \n",num ); //prints number

  double x = 9.0;

  double result = sqrt(x);
  printf("%.1lf \n",result );

  double y = 2.0;

  printf("pow(%.lf,%.lf)= %.lf \n",x,y, pow(x,y));

  //Quadratic formula
  double a;
  double b;
  double c;

  printf("Enter the values for a, b, and c: ");
  scanf("%lf %lf %lf",&a,&b,&c);

  double InsideSquare =(b * b) - (4 * a * c);
  double postive = -b + sqrt(InsideSquare);
  double negative = -b - sqrt(InsideSquare);

  double result1 = postive /(2*a);
  double result2 = negative /(2*a);

  printf("If postive %lf \n",result1 );
  printf("If negative %lf \n",result2 );


    return 0;
}

void whatDayisIt() { //user define function
  printf("It's Friday\n");
}

int favNum() {
  int num = 8;
  printf("Sending back Favorite number...\n");
  return num;
}
