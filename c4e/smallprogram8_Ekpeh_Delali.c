//Delali Ekpeh
//Dr.Steinberg
//COP3223 Section 1
//Small Program 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 50

typedef struct {

  char *fname; //First name
  char *lname; //Last name
  char *show; // Favorite show

}record_t;

//Prototypes
record_t * createArray(int maxsize); //Create array as a pointer
record_t * insert(record_t *myarray, int *maxsize, int *currentsize); //Allows to create elements in the struct
void display(record_t *myarray, int currentsize); //Displays all elements in the struct
record_t *doubleIt(record_t *arr, int size); //Doubles the size of the struct array when full
int removeRecord(record_t *arr, int size, int index); //Removes an element from the struct array
void freeRecords(record_t *arr, int size); //Frees memory of the elements in struct array

int main() {

  int maxsize;

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);


	record_t *myarray = createArray(maxsize);

	int currentsize = 0;
	int option = -1;

	while(option != 0)
    {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2:
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                if(index > currentsize) { // Checks if user input is in bounds of the struct array
                  printf("Remove Unsuccessful! The index %d is out of bounds of the array \n", index);
                  break;
                }
                currentsize = removeRecord(myarray,currentsize,index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
				break;

            default:
                printf("Invalid Selection...\n");


        }

    }

	freeRecords(myarray, currentsize);//When program ends frees memory all elements in the struct
	free(myarray);

	myarray = NULL;


  return 0;
}

record_t * createArray(int maxsize)
{
	record_t * arr = (record_t *) malloc(maxsize * sizeof(record_t));

	if(arr == NULL)
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}

	return arr;
}

void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");

	for(int x = 0; x < currentsize; ++x)
	{ //Displays using dot notation
	   printf("myarray[%d].fname = %s\n", x, myarray[x].fname); //try it with myarray[x].name
		printf("myarray[%d].lname = %s\n", x, myarray[x].lname); //try it with myarray[x].name
		printf("myarray[%d].show = %s\n", x, myarray[x].show); //try it with myarray[x].show
	}

	printf("---------------------------------\n");
}

record_t * insert(record_t *myarray, int *maxsize, int *currentsize) {

  fgetc(stdin);// Clears the keyboard from any random input from scanf

   if(*currentsize + 1 > *maxsize) { //Since currentsize is updated at the end of the function currentsize + 1 here

     printf("Array is full...Need to doubleIt....\n");
      myarray = doubleIt(myarray,*maxsize); //the old struct array is now the new struct array with more memory
      *maxsize = *maxsize + *maxsize; //updates maxsize
   }

  printf("---------------------------------\n");

  //Collecting First Name
  myarray[*currentsize].fname = (char*)malloc(*maxsize); //Allocates space in struct for a char*

  if( myarray[*currentsize].fname== NULL) { // If Malloc fails
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}

  printf("Enter the first name: ");
  fgets(myarray[*currentsize].fname, LIMIT, stdin);
  myarray[*currentsize].fname[strcspn(myarray[*currentsize].fname, "\n")] = '\0'; //Removes extra new line


  //Collecting Last Name
  myarray[*currentsize].lname = (char*)malloc(*maxsize);//Allocates space in struct for a char*

  if( myarray[*currentsize].lname== NULL) { // If Malloc fails
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}

  printf("Enter the last name: ");
  fgets(myarray[*currentsize].lname, LIMIT, stdin);
  myarray[*currentsize].lname[strcspn(myarray[*currentsize].lname, "\n")] = '\0'; //Removes extra new line


  //Collecting Show
  myarray[*currentsize].show = (char*)malloc(*maxsize);//Allocates space in struct for a char*

  if( myarray[*currentsize].fname== NULL) { // If Malloc fails
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}

  printf("Enter favorite show: ");
  fgets(myarray[*currentsize].show, LIMIT, stdin);


  printf("---------------------------------\n");
  *currentsize = *currentsize + 1; //updates currentsize

  return myarray;
}

record_t *doubleIt(record_t *arr, int size) {

  int i = 0;
  size = size + size; //Doubles size

  record_t *arrayTwo = (record_t *) malloc(size * sizeof(record_t));

  arrayTwo[i].fname = (char*)malloc(size);//Allocates space for new needed elements in struct array
  arrayTwo[i].fname = (char*)malloc(size);
  arrayTwo[i].show = (char*)malloc(size);

  for(i = 0; i < size; i++) { //populates new sturct array with elements from old struct array

    arrayTwo[i].fname = arr[i].fname;
    arrayTwo[i].lname = arr[i].lname;
    arrayTwo[i].show = arr[i].show;
  }

  freeRecords(arr,size);// Frees memory of old struct array
  free(arr);

	if(arrayTwo == NULL)
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}

	return arrayTwo; //new struct array is returned
}

int removeRecord(record_t *arr, int size, int index) {

  for(int i = 0; i < size -1; i++) {
    if(i == index) {
      printf("Removing student at %d \n", i);
      for(int j = i; j < size - 1;) {
        arr[j] = arr[j + 1]; //shifts elements in struct array to remove the element at the desired index
        break;
      }
    }
  }
  //Frees memory of removed element
   free(arr[size-1].fname);
   free(arr[size-1].lname);
   free(arr[size-1].show);

  size = size - 1; //size is updated 
  return size;
}
void freeRecords(record_t *arr, int size) {

  for(int i = 0; i < size; i++) {//Frees memory of whole struct array
    free(arr[i].fname);
    free(arr[i].lname);
    free(arr[i].show);
  }

}
