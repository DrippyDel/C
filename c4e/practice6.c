#include <stdio.h>

int main() {
// File IO //

  int var;
  double width,height,area;
  FILE * ptr; //File pointer
  FILE *data;
  FILE *ptrArea;

  data = fopen("data.txt","r");

  if(data == NULL) {
    printf("File did not open correctly \n");
    return 1;
  }

  ptrArea = fopen("area.txt","w");

  if(ptrArea == NULL) {
    printf("File did not open correctly \n");
    return 2;
  }

  while(fscanf(data, "%lf %lf",&width,&height) == 2) { //scanf returns how many values it reads and returns  -1 if reads nothing

    area = width * height;
    //printf("The area is %.2lf \n",area); printing regularly
    fprintf(ptrArea,"The area is %.2lf \n",area);
  }

  fclose(ptrArea);
  fclose(data);

  ptr = fopen("nums.txt","r");//Returns Null if file isn't there

  if(ptr == NULL){

    printf("File didn't open correctly \n");
    return 1;
  }

  else{
    printf("ptr points to %p \n", &ptr);// reads the first line of the file

    while(fscanf(ptr,"%d",&var) != -1 ){ //File address, data type, and variable.

      printf("var is %d \n",var);//var is 1
    }//end while
  }//end else

  fclose(ptr);// Always close a file when you open it

  FILE *ptr2 = fopen("morning.txt", "w");
  printf("ptr2 points to %p \n", &ptr2);

  fprintf(ptr2,"-----------------------\n");
  fprintf(ptr2, "Its October 19 \n");//writes to the file
  fclose(ptr2);

  return 0;
}
