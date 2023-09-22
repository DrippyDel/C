#include <stdio.h>

//Prototypes
void swap(int *xPtr, int *yPtr);
void bubbleSortRecus(int arr[],int len);
void selectionSort(int arr[], int len);
void insertionSort(int arr[], int len);
void mergeSort(int arr[], low, high);
void merge(int arr[], low, mid, high);
void quickSort(int *numbers, int low, int high);
void partition(int *vals, int low, int high);

int main ()
{
  int counter = 0;
  int countPtr = &counter;

  int arr [9]= {97,16,45,63,13,22,7 ,58 ,72};
  bubbleSortRecus(arr,9);

  return 0;
}

void swap(int *xPtr, int *yPtr)
{

  int temp = *xPtr;

  *xPtr = *yPtr;

  *yPtr = temp;
}

void bubbleSortRecus(int arr[],int len)
{
  // Base Case
  if (len == 1)
    return;

  int count = 0;

  // One pass of bubble sort.
  // Then largest element is moved to end
  for (int i = 0; i < len - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(&arr[i], &arr[i+1]);
      count++;
    }

    // If recursion happened or not
    if(count == 0)
      return;

    // Largest element is fixed, goes again for rest of array
    bubbleSortRecus(arr,len-1);
    // printf("Count was %d \n",count);
  }
}

void selectionSort(int arr[], int len)
{
  int temp = 0;
  int min = 0;

  // Iterating unsorted array
  for (int i = 0; i < len-1; i++)
  {
    // Start minimum at start of array
    min = i;


    for (int j = i+1; j < len; j++)
    {
      // Find the minimum element in unsorted array
      if(arr[j] < arr[min])
        min = j;
    }

    // Swap the found minium element with the first element
    if (min != i)
      swap(&arr[i], &arr[min]);


    // Swap the found minium element with the first element
    // temp = arr[i];
    // arr[i] = arr[min];
    // arr[min] = temp;

  }
}

void mergeSort(int arr[], low, high)
{
  // Checks how many unsorted elements
  if (low < high)
  {
    // break array into two sub arrays with mid variable
    int mid = (low + high) / 2;

    // Perform a sort on the left hand side recursivly
    mergeSort(arr, low, mid);

    // Perform a sort on the Right hand side recursivly
    mergeSort(arr,mid + 1, high);

    // When the two sides are sorted merge them
    merge(arr,low,mid,high);
  }
}

void merge(int arr[], low, mid, high)
{
  // index for left side of array
  int leftIndex = 0;

  // index for right side array
  int rightIndex = 0;

  // index of combinded array
  int index = 0;

  // Size of left side of array
  int leftSize = mid  + 1;

  // Size of right side of array
  int rightSize = high - mid;

  // Create temp pointer arrays for right and left side
  int *rSide = (int*)malloc(rightSize * sizeof(int));
  int *lSide = (int*)malloc(leftSize * sizeof(int));

  // Copy left and right side array data into temp arrays
  for (int i = 0; i < rightSize; i++)
    rSide[i] = arr[low + i];

  for (int i = 0; i < leftSize; i++)
    lSide[i] = arr[mid + 1 + i];

    // While the index of Left side is less than the size of the left side
    // While the index of Right side is less than the size of the Right side
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
      // Comparing the first element of the left side
      // with the first element of the right
      // Smallest element gets populated into new "merged" array
      if (lSide[leftIndex] <= rSide[rightIndex])
      {
          arr[index] = lSide[leftIndex];
          leftIndex++;
      }
      // lSide[leftIndex] >= rSide[rightIndex]
      else
      {
        arr[index] = rSide[rightIndex];
        rightIndex++;
      }

      index++;
    }

    // It's bound that one side of the array would be longer than the other
    // Copy remaining elements of left side if any
    while (leftIndex < leftSize)
    {
      arr[index] = lSide[leftIndex];
      leftIndex++;
      index++;
    }

    // Copy remaining elements of right side if any
    while (rightIndex < rightSize)
    {
      arr[index] = rSide[rightIndex];
      rightIndex++;
      index++;
    }

    free(lSide);
    free(rSide);
}

void insertionSort(int arr[], int len)
{
  int key = 0;
  int j = 0;

  // Iterate array
  // i starts at 1 so we can compare it with key at 0;
  for (int i = 1; i < len; i++)
  {

    key = arr[i];

    // Move elements that are greater than key to the right
    for (j = i - 1; j >= 0; j--)
    {
      // Shifts element
      if (arr[j] > key)
        arr[j+1] = arr[j];

      else
        break;
    }
    // Once for loop fails key replaces new spot
    arr[j+1] = key;
  }
}

void quickSort(int *numbers, int low, int high)
{
  // Base case
  if (low > high)
    return;

  // index of partition is return to part
  int part = partition(numbers, low, high);

  // Left side of partition
  quickSort(numbers, low, part - 1);

  // Right side of partition
  quickSort(numbers, part + 1, high);



}

void partition(int * vals, int low, int high)
{
  // high = last index
  // low =  first index

  // Set pivot to low index
  int pivotIndex = low + rand() % (high - low + 1);
  int pivot = vals[pivotIndex];
  swap(&vals[low], &vals[pivotIndex]);

  // itemFromLeft that is larger than pivot
  itemFromLeft = low;

  // itemFromRight that is smaller than pivot
  itemFromRight = high;

  // Since the pivot starts at beginning we must move over one
   itemFromLeft++;

  // Run the partition so long as the low and high counters don't cross
  while (itemFromLeft <= itemFromRight)
  {
    // Move low counter til we find number smaller than our pivot
    while (vals[itemFromLeft] <= pivot)
      itemFromLeft++;

    // Move high counter til we find number bigger than our pivot
    while (vals[itemFromRight] > pivot)
      itemFromRight--;

  // Now that we've identified two values on the wrong side, swap them
    if (itemFromLeft < itemFromRight)
      swap(&vals[itemFromLeft], &vals[itemFromRight]);
  }
   // Swap the partition element into it's correct location
   swap(&vals[pivotIndex], &vals[itemFromRight]);

   // return index of the partition element;
   return itemFromRight;

}
