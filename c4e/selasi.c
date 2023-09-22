#include <stdio.h>
#include <stdlib.h>

// Macro Constants
#define MAX_SIZE 100
#define SWAP (x,y,t) t = x; x = y; y = t;
#define WEEKS 5
#define DAYS 7

//Prototype
void printTriangle(int numRow);
void ran(int n);
void selSort(int arr[],int n);
void meanValue();

int main()
{
  int x = 0;
  int n = 0;

  // Calling the funtion where the triangle will be printed
  printTriangle(4);
  printTriangle(8);

// Loop to make sure User input is valid
  while(x == 0)
  {
    printf("Enter size of the Array: ");
    scanf("%d",&n);
    if (n < 0 || n > MAX_SIZE)
    {
      fprintf(stdout, "Error the size can't be less than zero, or greater than 100 \n");
    }
    else
    {
// Calling the function where I generate random numbers
      ran(n);
      x = 1;
    }
  }

// Calling the function where I take the mean of days in a week
  meanValue();

  return 0;
}

void printTriangle(int numRow)
{
  int i;
  int star = 1;
  int k = 1;
  int space = 1;

  for (i = 1;i <= numRow; i++)
  {
// A nested loop that would print the correct ammount of spaces
    for (space = 1;space <= numRow - i; space++)
    {
      printf(" ");
    }
// A nested loop that would print the correct ammount of stars
      for(star = 1;star <= k; star++)
      {
        printf("*");
      }
// Rows increacing by two
  k=k+2;
  printf("\n");
  }
  printf("\n");
}

void ran(int n)
{
  int arr[n];

  printf("Array before sorting: \n");
  // Loop to produce User's amount of random numbers
  for (int i = 0; i < n; i++)
  {
  // Creating the random numbers and putting the numbers into an array
    int r = rand() % 1000;
    arr[i] = r;
    printf("arr[%d] = %d \n",i,arr[i]);
  }
// Calling the function where I take the random numbers and sort them.
  selSort(arr,n);
}

void selSort(int arr[],int n)
{
  int temp = 0;
  int min = 0;
  printf("\n");
  for (int i = 0; i < n; i++)
  {
// Loop where I sort the random numbers from smallest to largest
    for (int j = i + 1; j < n; j++)
    {
      if(arr[i] > arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
    printf("Array After sorting: \n");
    for (int i = 0; i < n; i++)
    {
      printf("arr[%d] = %d \n",i,arr[i]);
    }
}

void meanValue()
{
  int weekTotalOne = 0;
  int weekTotalTwo = 0;
  int weekTotalThree = 0;
  int weekTotalFour = 0;
  int weekTotalFive= 0;
  int weekTotalSix = 0;
  int weekTotalSeven = 0;
  int total = 0;

// 2D Array of all the values for each day in each week
  int arr[WEEKS][DAYS] = {
    {367, 654, 545, 556, 565, 526, 437},
    {389, 689, 554, 526, 625, 537, 468},
    {429, 644, 586, 626, 652, 546, 493},
    {449, 689, 597, 679, 696, 568, 522},
    {489, 729, 627, 729, 737, 598, 552}
  };

    // Calculates Day 1 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for (int j = 0; j < DAYS; i++)
      {
        weekTotalOne = weekTotalOne + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

    // Calculates Day 2 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for(int j = 1; j < DAYS; i++)
      {
        weekTotalTwo = weekTotalTwo + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

    // Calculates Day 3 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for(int j = 2; j < DAYS; i++)
      {
        weekTotalThree = weekTotalThree + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

    // Calculates Day 4 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for(int j = 3; j < DAYS; i++)
      {
        weekTotalFour = weekTotalFour + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

    // Calculates Day 5 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for(int j = 4; j < DAYS; i++)
      {
        weekTotalFive = weekTotalFive + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

    // Calculates Day 6 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for(int j = 5; j < DAYS; i++)
      {
        weekTotalSix = weekTotalSix + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

    // Calculates Day 7 + Week 1-5
    for (int i = 0; i < WEEKS; i++)
    {
      for(int j = 6; j < DAYS; i++)
      {
        weekTotalSeven = weekTotalSeven + arr[i][j];
        if (i == 4)
        {
          break;
        }
      }
    }

// Prints the mean value of the days of each week
    printf("\n");
    printf("Day    Week Mean hit \n");
    printf("--------------------\n");
    printf("1        %.2lf\n",(double)weekTotalOne/WEEKS);
    printf("2        %.2lf\n",(double)weekTotalTwo/WEEKS);
    printf("3        %.2lf\n",(double)weekTotalThree/WEEKS);
    printf("4        %.2lf\n",(double)weekTotalFour/WEEKS);
    printf("5        %.2lf\n",(double)weekTotalFive/WEEKS);
    printf("6        %.2lf\n",(double)weekTotalSix/WEEKS);
    printf("7        %.2lf\n",(double)weekTotalSeven/WEEKS);
}
