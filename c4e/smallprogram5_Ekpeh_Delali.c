//Delali Ekpeh
//Dr.Steinberg
//COP3223 Section 1
//Small Program 5
#include <stdio.h>

//Prototype
void change(double *paid,double *due);//Returns how much change is owed in dollars and coins
void resterauntReceipt();//Takes User's order at Bob's Burgers Restaurant and prints receipt to 'myreceipt.txt' file
void gradeDistribution();//Reads file full of letter grades and prints out the grade distribution.
int incrementUpdate(int *val);//Updates 'val' per user's discretion

int main() {

  int val = 0;
  int *ptrVal = &val;//Assigning 'ptrVal' to point to the address of 'val'
  double due;
  double *ptr = &due;//Assigning 'ptr' to point to the address of  'due'
  double paid;
  double *ptr2 = &paid;//Assigning 'ptr2' to point to the address of 'paid'

  printf("Amount Due: ");
  scanf("%lf",&due);

  printf("Amount Paid: ");
  scanf("%lf",&paid);
  change(ptr2,ptr);//'ptr2' holds the value of variable 'paid'
                  //'ptr' holds the value of variable 'due'
  resterauntReceipt();
  gradeDistribution();

  printf("Before calling incrementUpdate \n");
  printf("val = %d \n",val);
  val = incrementUpdate(ptrVal);//'ptrVal holds the value of 'val' and function returns int value back into 'val'
  printf("After calling incrementUpdate \n");
  printf("val = %d \n",val);

  return 0;
}

void change(double *paid,double *due) {

  double change;
  int i = 1;
  double dollars;
  double quarters;
  double dimes;
  double nickels;
  double pennies;

  change = *paid -  *due;

  while(i != 0) {

    if(change >= 1) { //Calculates how much dollars are owed
      ++dollars;
      change = change - 1;
    }//end of if(change >= 1)

    else if(change >= .25) {// Calculates how much quarters are owed
      ++quarters;
      change = change - .25;
    }//end of else if(change >= .25)

    else if(change >= .10) {// Calculates how much dimes are owed
      ++dimes;
      change = change - .10;
    }//end of else if(change >= .10)

    else if(change >= .05) { //Calculates how much nickels are owed
      ++nickels;
      change = change - .05;
    }//end of else if(change >= .05)

    else if(change > 0.0) {// Calculates how much pennies are owed
      pennies = change * 100;//convert decimal to whole number
      i = 0;
    }//end of else if(change > 0)

    else {
      i =0;//ends loop
    }//end of else
  }//end while

  printf("Change \n");
  printf("%.0lf dollars  \n",dollars);
  printf("%.0lf quarters \n",quarters);
  printf("%.0lf dimes    \n",dimes);
  printf("%.0lf nickels  \n",nickels);
  printf("%.0lf pennies  \n",pennies);

}

void resterauntReceipt() {

  int choice;
  int i =1;
  double regular = 5.00;
  double special = 5.95;
  double cheese = 5.50;
  double fries = 2.00;
  double salad = 2.50;
  double softDrink = 2.00;

  //Setting menu choice values to be assigned to pointers
  int one = 0 ;// 1 = Regular
  int *ptr4 = &one;

  int two = 0;// 2 = Special
  int *ptr5 = &two;

  int three = 0;// 3 = Cheese
  int *ptr6 = &three;

  int four = 0;// 4 = Fries
  int *ptr7 = &four;

  int five = 0;// 5 = Salad
  int *ptr8 = &five;

  int six = 0;// 6 = Soft Drink
  int *ptr9 = &six;

  double total = 0;// Collects Total
  double *ptrTotal = &total;

  printf("Welcome to Bob's Burgers! Our burger of the day is Say Cheese Burger!\n");

  while(i != 0) {
    printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
    printf("-----------------------\n");
    printf("1: Regular    $5.00\n");
    printf("2: Special    $5.95\n");
    printf("3: Cheese     $5.50\n");
    printf("4: Fries      $2.00\n");
    printf("5: Salad      $2.50\n");
    printf("6: Soft Drink $2.00\n");
    printf("-----------------------\n");
    printf("What will you add to your order: ");
    scanf("%d ",&choice);

    if(choice == 1) {//Collects that the user wanted 1 regualr along with price
      printf("Adding regular to your order. \n");
      one++;
      total = regular + total;
    }//end of if(choice == 1)

    else if(choice == 2) {//Collects that the user wanted 1 special along with price
      printf("Adding special to your order. \n");
      two++;
      total =  special + total;
    }//end of else if(choice == 2)

    else if(choice == 3) {//Collects that the user wanted 1 cheese along with price
      printf("Adding cheese to your order. \n");
      three++;
      total = cheese + total;
    }//end of else if(choice == 3)

    else if(choice == 4) {//Collects that the user wanted 1 fries along with price
      printf("Adding fries to your order. \n");
      four++;
      total = fries + total;
    }//end of else if(choice == 4)

    else if(choice == 5) {//Collects that the user wanted 1 salad along with price
      printf("Adding salad to your order. \n");
      five++;
      total = salad + total;
    }//end of else if(choice == 5)

    else if(choice == 6) {//Collects that the user wanted 1 soft drink along with price
      printf("Adding soft drink to your order. \n");
      six++;
      total = softDrink + total;
    }//end of else if(choice == 6)

    else if(choice == 0) {//Send total order and price to 'myreceipt.txt' file
      printf("Order is now placed. Printing receipt. \n");

      FILE *ptr3 = fopen("myreceipt.txt","w");//pointer set to open file
      //What is written to the file:
      fprintf(ptr3,"Bob's Burgers Restaurant Receipt Order \n");
      fprintf(ptr3,"-----------------------\n");
      fprintf(ptr3,"%d Regular(s)    \n", *ptr4);
      fprintf(ptr3,"%d Special(s)    \n", *ptr5);
      fprintf(ptr3,"%d Cheese(s)     \n", *ptr6);
      fprintf(ptr3,"%d Fries         \n", *ptr7);
      fprintf(ptr3,"%d Salad(s)      \n", *ptr8);
      fprintf(ptr3,"%d Soft Drink(s) \n", *ptr9);
      fprintf(ptr3,"-----------------------\n");
      fprintf(ptr3,"Total: $%.2lf \n", *ptrTotal);
      fprintf(ptr3,"Thank you and come again! \n");
      fclose(ptr3);// closes file
      i = 0; //ends loop
    }//end of else if(choice == 0)

    else {
      printf("Invaild input \n");
    }//end of else
  }//end of while

}

void gradeDistribution() {

  char var = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int f = 0;
  FILE *fptr;

  fptr = fopen("grades.txt","r");//Reading file "r"

  if(fptr == NULL){// Checks if file exits
    printf("File didn't open correctly \n");
  }

  else {
    while(fscanf(fptr,"%c",&var) != -1) { //Scans each line in file. If file reaches the end fscanf would return -1 ending the while loop
      if(var == 'A') {
        ++a;
      }//end of if(var == 'A')

      else if(var == 'B') {
        ++b;
      }//end of else if(var == 'B')

      else if(var == 'C') {
        ++c;
      }//end of else if(var == 'C')

      else if(var == 'D') {
        ++d;
      }//end of else if(var == 'D')

      else if(var == 'F') {
        ++f;
      }//end of else if(var == 'F')
    }//end of while

    printf("Here is the grade distribution. \n");
    printf("A: %d \n",a);
    printf("B: %d \n",b);
    printf("C: %d \n",c);
    printf("D: %d \n",d);
    printf("F: %d \n",f);
    fclose(fptr);
  }//end of else
}

int incrementUpdate(int *val) {

  int i = 1;
  int total;
  int option;

  while( i != 0) {
    printf("Updating val now... \n");
    printf("Would you like to update ... \n");
    printf("Enter 0 if you would like to update again. Anything else will exit the update. \n");
    printf("Option: ");
    scanf("%d",&option);

    if(option == 0) {
      ++*val; //Pre increment of pointer 'val' which also points to the address of int 'val' in main
    }//end of if(option == 0)

    else {
      printf("val is now done updating... \n");
      ++*val;
      i = 0;//ends loop
    }//end of else
  }//end of while

  total = *val;
  return(total);
}
