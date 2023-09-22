#include <stdio.h>

//Prototype
void hello();
void loop();
void update();

int main() {
// Loops //


  int p = 0;

  //Look into compound operators !!!
  loop();
  int count = 10;

//The while loop would run at least zero times
  while(count < 10) {
    hello();
    printf("Again i guess \n");

    count = count + 1;
  }// end of while(count < 10)

//The Do while would run at least once
//The Do while keeps me in the loop til vaild input is provided
  int input = 0;
  do{
      printf("Enter a value: ");
      scanf("%d",&input);

      if(input < 0) {
          p = 1;
      }

  }while(p == 0);

  return 0;
}

void hello() {
  printf("Okay day\n");
}

void loop() {

  for(int x = 0; x < 10; ++x) { // or x +=1 or x = x + 1
    printf("x = %d \n",x);
  }//end of for(int x = 0; x < 10; x = x + 1)
}

void update() {

  int x = 0;
  printf("x = %d \n",x);

  x++; //Post increment operator

  printf("x = %d \n",x);

  x--; // Post decrement operator

  printf("x = %d \n",x);

  ++x; //Pre increment operator increases by one
  --x; //Pre decrement operator decreases by one
}
