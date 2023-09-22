#include <stdio.h>

// Prototypes
int binarySearch(int list[], int item, int len);
int binSearchRecursive(int *values, int low, int high, int searchVal);

// Binary Search - to make the search space smaller
// Only works if array is sorted
int main()
{



  return 0;
}

// O(n)
int binarySearch(int list[], int item, int len)
{
  int low = 0
  int high = len -1;
  int mid;

  while (low <= high)
  {
    mid = (low + high)/2;

    // Check if item is present at mid
    if (list[mid] == item)
      return mid;

    // If item is greater, ignore left
    if (list[mid] < item)
      low = mid + 1;

    // If item is smaller, ignore right
    else
      high = mid - 1;
  }
  // Element was not present
  return 0;
}

// O(log n)
// T(n) = 2T(n/2) + c
int binSearchRecursive(int *values, int low, int high, int searchVal)
{
  int mid = 0;

  // Base case
  if (low > high)
    return 0;

  mid = (low + high)/2;

  // If item is present at mid
  if (values[mid] == searchVal)
    return mid;

  // If item is smaller, ignore right side
  else if (searchVal < values[mid])
    return binSearchRecursive(values, low, mid - 1, searchVal);

  // If item is bigger, ignore left side
  else if (searchVal > values[mid])
    return binSearchRecursive(values, mid + 1, high, searchVal);

  // Element was not present
  else
    return -1;
}
