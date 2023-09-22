#include <stdio.h>
#include <stdlib.h>

// Dynamic Memory Allocation
// Malloc

// Prototypes

void memory();

int main()
{
  // memory();
  int n = 0;

  printf("Enter the number of integers:");
  scanf("%d", &n);

  // Allocating the size of n integers (think of ptr as an array)
  int *ptr = (int *)malloc(n * sizeof(int));

  // Good practice to check if pointer is null
  if(ptr ==  NULL)
  {
    printf("Memory not available.\n");
    exit(1);
  }

  for (int i = 0; i < n; i++)
  {
    printf("Enter an integer: ");
    // Scanning the address of each that increases by 4 (since an int is 4 bytes)
    scanf("%d", ptr + i);
  }

  for (int i = 0; i < n; i++)
  {
    printf("Memory address\n%p \n", ptr + i);

    // Dereferencing the pointer by address
    printf("%d \n", *(ptr + i));
  }

  n = 6;
  // Deletes old memory and creates new expanded one
  ptr = realloc (ptr, n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    printf("Memory Address after Realloc\n%p \n", ptr + i);
  }

  printf("Trial run %d \n", *(ptr + 2));

  free(ptr);
  ptr = NULL;
  return 0;

}

void memory()
{
  // Practice problem from online

  int n = 4;

  // Create a pointer array
  int *ages = NULL;

  // Allocate 4 spaces for the array
  ages = (int*)malloc(n * sizeof(int));

  if (ages == NULL)
    {
      return;
    }

  // Get 4 input values for the array
  printf("Enter 4 input values:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d",ages + i);
  }

  // Print the array elements using the pointer
  printf("\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d \n", *(ages + i));
  }

  // Resize the array to store 6 elements
  n = 6;
  ages = realloc(ages, n * sizeof(int));

  // Assign 32 and 59 to 5th and 6th elements
  // *(ages + 4) = 32;
  // *(ages + 5) = 59;
  ages[4] = 32;
  ages[5] = 59;

  // Print all 6 array elements
  for (int i = 0; i < n; i++)
  {
    printf("After realloc %d\n", *(ages + i));
  }

}
