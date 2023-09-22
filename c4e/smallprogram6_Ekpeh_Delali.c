//Delali Ekpeh
//Dr.Steinberg
//COP3223 Section 1
//Small Program 6

#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

//Prototypes
void display(int arr[]);//Displays Array
void MinMax(int arr[]);//Finds the lowest, highest, and the average of the elements in an array.
void mySort(int arr[]);//Sorts the elements in an array to increasing order.
void doubleShift(int arr[]);//Shifts values in an array over by 2 indexes.
void reverse(int arr[]);//Flips the position of the values in reverse order.

int main() {

  int arr[SIZE];
	int seed;
	printf("Enter a seed: ");

	scanf("%d", &seed);
	srand(seed);

	//generate numbers for the array
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1; //1-1000
	}

	//call your functions for small program 6
   MinMax(arr);
   mySort(arr);
   display(arr);
   doubleShift(arr);
   display(arr);
   reverse(arr);
   display(arr);


  return 0;
}

void display(int arr[])
{
	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);

	printf("\n");
}

void MinMax(int arr[]) {

  double avg = 0;
  double sum = 0;
  int max = 0;
  int min = 0;


  for(int x = 0; x < SIZE; x++) {
    //Adds all the values in the array
    sum += arr[x];
  }//end of for(int x = 0; x < SIZE; x++)

  avg = sum / (double) SIZE;

  // Calculate the min and max in the array
  for(int x = 0; x < SIZE; x++) {
    if(arr[x] > max) {
      max = arr[x];//Max would hold the biggest number found in the array. Then update if a bigger one was found
    }//end of if(arr[x] > max)

    if(arr[x] < min) {
      min = arr[x];//Min would hold the lowest number found in the array. Then update if a lowest one was found
    }//end of if(arr[x] < min)

  }//end of for(x = 0; x < SIZE; x++)

  printf("Average: %.6lf \n",avg);
  printf("Max: %d \n",max); //If python scripts keeps failling here add extra new line!!
  printf("Min: %d \n",min);

}

void mySort(int arr[]) {

  int i;
  int temp;

  for(int x = 0; x < SIZE; ++x) {
    for(i = x + 1; i < SIZE; ++i) {
      if(arr[x] > arr[i]) {//Each time the value of arr[x] is greater than the value of arr[i]
                          //the index of arr[x] would increases by one till the array
                          //ends or until arr[x] is less than arr[i]
        temp = arr[x];
        arr[x] = arr[i];
        arr[i] = temp;
      }// end of if(arr[x] > arr[i])
    }//end of for(i = x + 1; i < SIZE; ++i)
  }//end of for(int x = 0; x < SIZE; ++x)
}

void doubleShift(int arr[]) {

  int temp;
  int i;
  temp = arr[i-1]; //

  for(int x = i - 1; x > 0; x--) {

    arr[x] = arr[x - 2]; //Shifting by 2 indexes so its - 2
  }//end of for(int x = i - 1; x > 0; x--)

  arr[0] = temp; //Temp saves the orginal index

}

void reverse(int arr[]) {

  int temp;

  for(int x = 0; x < SIZE / 2; x++) {// SIZE / 2 since were dividing the array into two halves and one half swaps with the other one.

    temp = arr[x];//Temp saves orginal index
    arr[x] = arr[SIZE - 1 - x];
    arr[SIZE - 1 - x] = temp;

  }//end of for(int x = 0; x < SIZE / 2; x++)


}
