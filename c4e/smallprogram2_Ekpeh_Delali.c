//Delali Ekpeh
//Dr. Steinberg
//COP3223C Section 1
//Small Program 2
#include <stdio.h>
#include <math.h>// Library that allows for more complex math functions

//Prototypes
double coneSurfaceArea(double radius, double height, double pi);
void parkingCharge();
void wakandaPopulation(int year);
double factorialApprox(int n);

//Macro Constant
#define PI 3.14

int main() {

  //Declarations
  double a;
  double b;
  double total;
  int d;
  int n;
  double facN;

  printf("Enter the radius: ");
  scanf("%lf",&a);
  printf("Enter the height: ");
  scanf("%lf",&b);
  total = coneSurfaceArea(a,b,PI); //Function call that calculates the surface area of a cone

  printf("The total surface area of the cone is %.2lf \n",total);

  parkingCharge(); //Function call that calculates the cost to park a customer's car for x amount of hours

  printf("Enter a year after 2016: ");
  scanf("%d",&d);
  wakandaPopulation(d); //Function call that calculates Wakanda's predicted population

  printf("Enter the value for n: ");
  scanf("%d",&n);
  facN = factorialApprox(n); // Function call that caluclates R.W. Gosper approximation formula
  printf("%d! is approximately %.4lf\n",n,facN);



  return 0;
}
double coneSurfaceArea(double radius, double height, double pi) {
  double sa = pi * radius * (radius + sqrt((height*height)+(radius * radius))); //sqrt does the square root of parameter argument. Thanks to math.h library
  return sa;
}
void parkingCharge() {

  int hours;
  double rate = 4.21;

  printf("Welcome to the Parking Garage!\n");
  printf("How many hours will you keep your car parked here> ");
  scanf("%d",&hours);

  double cost = hours * rate;

  printf("Car will be parked for %d hours and will be charged $%.2lf.\n",hours,cost);
}
void wakandaPopulation(int year) {
    int after = (2016 - year) * -1;
    double totalPop = 51.451 + (4.239 * after);
    printf("Predicted Wakanda's population for 2022 (in thousands): %.3lf\n",totalPop);
}
double factorialApprox(int n) {
  double rootPart;
  double rootSolved;

  rootPart = (1.0/3.0) + (2 * n);
  rootSolved = sqrt(rootPart * PI);
  double facN = (pow(n,n) * exp(-n)) *rootSolved; //pow takes the power of two parameters and exp takes the e of a parameter
  return facN;
}
