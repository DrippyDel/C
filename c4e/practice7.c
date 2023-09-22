#include <stdio.h>

//Prototype
void reverse_array(int array[], int size); //[1,2,3,4] to [4,3,2,1]
void print_array(int array[], int size); // Fancy way to print an array
void d2Array();

int main() {
// Arrays // Are adjacent cells in memory

  int arr[4];
  arr[0] = 12;
  arr[1] = 2;
  arr[2] = 4;
  arr[3] = 22;

  //How to print an array regularly
  for(int x=0; x<4; ++x) {
    printf("arr[%d] = %d \n",x,arr[x]);
  }

  printf("&arr[1] = %p \n", &arr[1]);
  int *ptr = &arr[1];// now we have a ptr that can point exactly to arr[1]
  printf("ptr is %p \n", ptr);

  int arr2[] = {1,3,2,5,3,5}; //initializer list

  int x = 1;
  arr2[x] = arr2[x + 1];

  for(int x = 0; x < 6; ++x) {
    printf("arr2[%d] = %d \n",x,arr2[x]);
  }

  int result = sizeof(arr);//returns how much bits of memory a variable holds.
            //You can put array names to find out how elements are in the array.

  int arraysize = sizeof(arr)/sizeof(arr[0]);

  printf("arr has %d elements \n",arraysize);

  //DO NOT DO THIS !!!! IT MESSES WITH STATIC MEMORY
  /*
  int size;
  printf("Enter the class size: ");
  scanf("%d",&size);
  int students[size];//VLA Variable Length Array DON'T USED THIS!!!
    */

    int arr3[] = {1,3,2,5,3,5,7};
    print_array(arr3,7);
    reverse_array(arr3,7);
    print_array(arr3,7);
    d2Array();


  return 0;
}

void reverse_array(int array[], int size) {

  int temp;

  for(int i = 0; i < size / 2; i++) { // if the array size was even i < size / 2 - 1 would be needed

    temp = array[i];
    array[i] = array[size - 1 -i];
    array[size - 1 - i] = temp;

  }//end of for(int i = 0; i < size / 2; i++)

}

void print_array(int array[], int size) { //Fancy way to printf array elements

  printf("[");
  for(int i = 0; i < size; i++) {

    printf("%d", array[i]);

    if(i < size - 1) {
      printf(", ");
    }

  }
  printf("]\n");
}
void d2Array() {
//        R  C      R-Rows C-Column   each cell is 4 bits of memory
  int arr[3][4]; //Declaration of a 2D array;
  for(int row = 0; row < 3; ++row) { // row traversal

    for(int column = 0; column < 4; ++column) {
      arr[row][column] = row * column;

      printf("%d \t", arr[row][column]);
    }//end of for(int column = 0; column < 4; ++column)
    printf("\n");
  }//end of   for(int row = 0; row < 3; ++row)

}
