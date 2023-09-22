#include <stdio.h>

// Recursive

// Prototypes
int sum(int n);
int fractorial(int n);

int main ()
{
  int number = 0;
  int result = 0;

  printf("Enter a positive integer: ");
  scanf("%d", &number);

  result = fractorial(number);

  printf("fractorial of %d = %d \n", number, result);
  return 0;
}

int sum(int n)
{
  // controls loop
  if (n == 0)
  {
    return 0;
  }
  else
  {
    return n + sum(n-1);
  }

  /*
    if n is 4
    4 + sum(4-1)
    3 + sum(3-1)
    2 + sum(2-1)
    1 + sum(1-1)

    In the end sum = 10;
  */

}

int fractorial(int n)
{
  if (n == 1)
  {
    return 1;
  }
  else
  {
    return n * fractorial(n-1);
  }

  /*
    if n is 4
    4 * fractorial(4-1)
    3 + fractorial(3-1)
    2 + fractorial(2-1)
    1 + fractorial(1-1)

    In the end fractorial = 24;
  */
}
