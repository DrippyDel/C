#include <stdio.h>

//Prototype
void function1(int * xptr);

int main() {
// Pointers 8 bytes //

  // Stack Memory - Used to store variables used on the inside of a function
  // Heap Memory - Where memory are allocated to store certain data times

  //Pointers stores the value of an Address
  //Hexadecimal - base 16 number
  /*
    0 1 2 3 4 5 6 7 8 9  A  B  C  D  E  F
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    * - Dereference Unmasking the value (whose stored there)
    & - Address
  */

  int x = 4; // Stack
  int y = 8;

  printf("Heres x %d \n", x);

  printf("The address of the variable x is %p \n",&x); //& a varibale displays an address

  int *ptr = NULL; // (Stack and Heap)
  int *pointer1 = &y; // pointer variable points to address of Y

  ptr = &x;//Addressing
  printf("ptr points to the address of x which is %p\n", ptr); //prints x's address. ptr points to the address of x
  printf("address of ptr is %p \n", &ptr); //ptr value is now a copy of x with its own address

  *ptr = -5; //Dereference x which was 4 to -5. The location is the same but the value is diffrent

  printf("Heres x %d \n", x); // x is now -5
  printf("After the dereference ptr still points to the address of x which is %p \n", ptr); //The int value is different But still points to x's address

  function1(ptr);//Basic function call or pass by value. Also passing the value of ptr = -5

  printf("After the fucntion the address of x is %d \n", x);// x is now 8 because we dereferenced it in the function
  return 0;
}

void function1(int * xptr) {
  printf("xptr holds the value %d \n",*xptr); //prints -5
  printf("The address of xptr is %p \n",&xptr); //Prints a new address to copy ptr
  printf("xptr points to x's orignal address value which is %p \n", xptr);//Prints the address of x

  *xptr = 8; //Dereferencing to a new value. So its not pointing to -5 anymore

}
