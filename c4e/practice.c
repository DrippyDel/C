#include <stdio.h>
// Macro Constant - A Constant that the whole file can use. (Normally All Caps)
#define PI 3.1415

int main() {

  printf("Notes From Class\n");

  // <-- how to do a single line comment
  /*   <---
      Multi line comment
  */
  
  //Declaration Statments
  int a; // 4 bytes of ram
  double b; // 8 bytes of ram
  float c; // 4 bytes of ram
  char d; // 1 byte of ram
  const double pi =3.14;
  //Assigment Statments
  a= 10; //Intergers
  b=0.5; //Float
  c=0.3; // Double
  d='H'; // Char
  /*Place Holders
  %d - Display Intergers (d - decimal)
  %lf - Display Double (lf - long float)
  %f - Display Float   (f - float)
  %c - Display Character (c - character)
  */

  /* Escape Characters
  /n - New line
  /t - Tab
  /a - Alert with sound
  */

  //Implicit Casing = (9 * 0.5) C casts the 9 to be a double (double dominates)
  //Explicit Casting = (int)(9 * 0.5) I cast the whole formula to be a int

  /* Potential Test questions
    double n;
    n = (int) (9 * 0.5)
    n = 4.0 a double

    double close = 0.564;
    printf("%.1lf \n",close );
    Displays = 0.6         C rounds when it displays
  */

  printf("%d , %f , %c \n",a,b,d);

  printf("Enter a value: ");
  scanf("%d", &a);
  printf("%d\n",a );


    return 0;
}
