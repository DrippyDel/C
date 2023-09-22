//Delali Ekpeh
//Dr. Steinberg
//COP3223C Section 1
//Small Program1
#include <stdio.h>

int main() {

  //Declaration Statements
  double a;
  double b;
  double c;
  double d;
  double rate;
  float wip;
  float hIi;
  double bmi;
  double radius;
  double height;
  double volume;
  //Assigment Statments
  const double pi =3.14159;
  c=7.0;
  rate = 2.61;
  d= c * 2.61; // Formula for given rate per mile
  //

  printf(" VV          VV\n");
  printf("  VV        VV\n");
  printf("   VV      VV\n");
  printf("    VV    VV\n");
  printf("     VV  VV\n");
  printf("      VVVV\n");
  printf("       VV\n");

  printf("Mileage Reimbursement Calculator\n");
  printf("Enter beginning odometer reading=> ");
  scanf("%lf",&a);

  printf("Enter ending odometer reading=> ");
  scanf("%lf",&b);

  printf("You traveled %0.1f miles. \n",c );
  printf("At $%.02f per mile, your reimbursement is $%0.2f \n",rate,d);

  printf("Enter the weight in pounds: ");
  scanf("%f",&wip);

  printf("Enter the total height in inches: ");
  scanf("%f",&hIi);

  //Assigment Statements
  bmi = (wip * 703) / (hIi * hIi); //Formula to Calculate Body Mass Index
  //

  printf("BMI = %0.3f \n",bmi);

  printf("Enter the radius: ");
  scanf("%lf",&radius);

  printf("Enter the height: ");
  scanf("%lf",&height);

  //Assigment Statements
  volume = ((double) 1/3) * pi * (radius*radius) * height; // Formula to Calculate Volume
  // (double 1/3) to return double arithmetric value
  //

  printf("The volume of the cone is %0.4f \n",volume);
  return 0;
}
