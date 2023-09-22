#include <stdio.h>
#include <stdlib.h> // malloc location
#include <string.h>

typedef struct {

  int year;
  char * title; //Dynamic component
  char * author;

}movie_t;

//Prototypes

int main() {
  //Dynamic Memory - memory that we change in size during the program run.

  //Static Memory - Provided memory to utilize for our program in the stack space. Given from compliler.
  //Heap space - Where we get our extra memory from (Program run).


  int x = 4;//Stored in the stack space
  int *ptr = (int *) malloc(sizeof(int));//Allocating 4 bytes of memory in the deep space.

  if(ptr == NULL) {

    printf("Malloc didn't find enough space in the heap space \n");
  }
  else {

    *ptr = 3; //3 is now stored in the heap sp

    printf("The address of the pointer ptr  is %p \n", &ptr);
    printf("ptr is pointing to %p \n", ptr);
    printf("ptr's value is %d \n", *ptr);

    free(ptr);//Gave back space to the system. Similar to fclose
    ptr = NULL;
  }

  //Dynamic arrays -----------------------

  int size;

  printf("Sent the size of the Dynamic Array: ");
  scanf("%d", &size);

  int *dynArr = (int *) malloc(sizeof(int) * size); //Dynamic array

  for(int x = 0; x < size; x++) {
    dynArr[x] = 100 + x;
    printf("Array[%d] = %d \n", x ,dynArr[x]);
  }

  //Pointer version which shares the same address as the regular version
  for(int x = 0; x < size; x++) {
    *(dynArr + x) = 100 + x;
    printf("Pointer Array[%d] = %d \n", x ,dynArr[x]);
  }

  size = size * 2;

  int *temp = (int *) malloc(sizeof(int) * size);//Reallocated more space

  for(int x = 0; x < size / 2; x++) {
    temp[x] = dynArr[x]; // copy former array into temp
  }

  free(dynArr);
  dynArr = temp;//switching pointers
  free(dynArr);

  //Dynamic Memory with Structs --------------------------------

  movie_t *mymovie = (movie_t *) malloc(sizeof(movie_t)); //Allocates memory for a struct

  mymovie->title = (char *) malloc(sizeof(char)* 30);

  mymovie->year = 2022; //indirectly assign the year component in the mymovie struct to year

  strcpy(mymovie->title, "Avatar");

  printf("%d \n", mymovie->year);
  printf("%s \n", mymovie->title);

  free(mymovie->year);//Call free for each malloc call
  free(mymovie);

  //Createing  a dynamic struct array
  movie_t *movie = (movie_t *) malloc(sizeof(movie_t) * 10); //10 represents the size of the struct array

  free(movie);

  //Dynamic Memory with 2D Arrays -------------------------

  int rows = 2;
  int columns = 3;

  int *arr2D = (int *)malloc(sizeof(int) * rows * columns);

   for(int x = 0; x < 2; ++x){
     for(int y = 0; y < 3; ++y) {
       *(arr2D + x * columns + y) = x * y;
       printf("%p[%d] = %d \n", arr2D, x, arr2D[x]);
     }
   }
   free(arr2D);

  return 0;
}
