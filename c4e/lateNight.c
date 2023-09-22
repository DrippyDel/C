#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macro Constants
#define MAX_LENGTH 5
#define MAX_LENGTHII 10


// Prototype
double find_max(double array[], int length);
double find_min(double array[], int length);
void print_array(double array[], int length);
void combine_arrays(double src1[], int length1, double src2[], int length2, double dest[]);
void sort_array(double array[], int length);

int main()
{
  int  low = 9.0;
  int  high = 16.0;
  double menArray[5];
  double womenArray[5];
  double raceArray[10];

  // Set seed of rand function
   srand(time(0));

   // Men Array
  for (int i = 0; i < MAX_LENGTH; i++)
  {
    double ranNum = ((double)rand() * ( high - low )) / (double)RAND_MAX + low;
    menArray[i] = ranNum;
     //printf("arr[%d] = %lf \n", i, menArray[i]);
  }

  //printf("\n");

  // Women Array
  for (int i = 0; i < MAX_LENGTH; i++)
  {
    double ranNum = ((double)rand() * ( high - low )) / (double)RAND_MAX + low;
    womenArray[i] = ranNum;
     //printf("arr[%d] = %lf \n", i, womenArray[i]);
  }

  double menMax = find_max(menArray, MAX_LENGTH);
  double menMin = find_min(menArray, MAX_LENGTH);

  double womenMax = find_max(womenArray, MAX_LENGTH);
  double womenMin = find_min(womenArray, MAX_LENGTH);

  printf("\n");
  printf("The fastest time among the men's race was %.2lf \n", menMin);
  printf("The slowest time among the men's race was %.2lf \n \n", menMax);

  printf("The fastest time among the women's race was %.2lf \n", womenMin);
  printf("The slowest time among the women's race was %.2lf \n \n", womenMax);

  printf("Men's Data: \n");
  print_array(menArray, MAX_LENGTH);
  printf("Women's Data: \n");
  print_array(womenArray, MAX_LENGTH);

  combine_arrays(menArray, MAX_LENGTH, womenArray, MAX_LENGTHII, raceArray);
}

double find_max(double array[], int length)
{
  double max = array[0];
  for (int i = 0; i < length; i++)
  {
    if(array[i] > max)
    {
      max = array[i];
    }
  }

  return max;
}

double find_min(double array[], int length)
{
  double min = array[0];
  for (int i = 0; i < length; i++)
  {
    if(array[i] < min)
    {
      min = array[i];
    }
  }
  return min;
}

void print_array(double array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%.2lf, ", array[i]);
  }
  printf("\n\n");
}

void combine_arrays(double src1[], int length1, double src2[], int length2, double dest[])
{
  int count = 0;
  for (int i = 0; i < length2; i++)
  {
    // Puts Men's array into new array
    if(i < length1 )
    {
      dest[i] = src1[count];
    }

    // resets count
    if(count == length1 )
    {
      count = 0;
    }

    if (i >= length1)
    {
      dest[i] = src2[count];
    }
    //printf("%d \n",count);
    count++;
  }
  sort_array(dest,length2);
}

void sort_array(double array[], int length)
{
  double temp = 0;
  double min = 0;

  for (int i = 0; i < length; i++)
  {
    for(int j = i + 1; j < length; j++)
    {
      if(array[i] > array[j])
      {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  printf("Sorted Combined Dataset: \n");
  print_array(array, length);
}
