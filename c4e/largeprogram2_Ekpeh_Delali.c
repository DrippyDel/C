//Delali Ekpeh
//Dr.Steinberg
//COP3223 Section 1
//Large Program 2
#include <stdio.h>
#include <ctype.h>

//Prototype
void greeting();//Greeting to user
void order(double *balance);//User wiil make a purchase
void viewHand(double *balance);//Displays current amount in hand
void transaction(double *balance, double price);
void pullMoney(double *balance);//Grab more money form the Unlimited Wallet
void displayVendingOptions();//display berage options and prices

int main() {

  double balance =0.0;
  double *ptr = &balance;

  greeting();
  order(ptr);

  return 0;
}

void greeting() {

  printf("Welcome to the Unlimited Vending Machine\n");
  printf("We have an unlimted variety of drinks. \n");
  printf("With your unlimted wallet, you will never run out of cash! \n");
  printf("What would you like to order today? \n");
  printf("***************************************************\n");

}

void order(double *balance) {


  int i =1;
  char choice;
  int choice2;
  double sprite = 2.50;
  double cocaCola = 2.50;
  double water = 2;
  double gatorade = 3;
  double dietCola = 2.55;
  double fanta = 2.55;
  double rootBeer = 1.50;
  double drPepper = 1.55;

  while (i != 0) {
    printf("Please select one of the following options. \n");
    printf("O: Order from the Unlimited Vending Machine. \n");
    printf("V: View what you have in your hand currently. \n");
    printf("D: Display what the Unlimited Vending Machine contains. \n");
    printf("G: Grab money out of unlimted wallet. \n");
    printf("E: Exit \n");
    printf("***************************************************\n");


    printf("Please select an option: ");
    scanf(" %c",&choice);
    choice = toupper(choice);//Changes input ot upper case

    if(choice == 'O') {

      int j = 1;

      printf("You have selected option: %c\n",choice);
      printf("You have selected to order something form the Unlimited Vending Machine. \n");
      printf("Here's the options!\n");
      printf("***************************************************\n");
      while(j != 0) {

        displayVendingOptions();
        printf("What would you like today? ");
        scanf("%d",&choice2);

        if(choice2 == 1) {
          printf("Sprite has been selected. Total cost is: $%.2lf \n",sprite);
          transaction(balance,sprite);
          j = 0;
        }//end of if(choice == 1)

        else if(choice2 == 2) {
          printf("Coca-Cola has been selected. Total cost is: $%.2lf \n",cocaCola);
          transaction(balance,cocaCola);
          j = 0;
        }//end of else if(choice == 2)

        else if(choice2 == 3) {
          printf("Water has been selected. Total cost is: $%.2lf \n",water);
          transaction(balance,water);
          j = 0;
        }//end of else if(choice == 3)

        else if(choice2 == 4) {
          printf("Gatorade has been selected. Total cost is: $%.2lf \n",gatorade);
          transaction(balance,gatorade);
          j = 0;
        }//end of else if(choice == 4)

        else if(choice2 == 5) {
          printf("Diet Cola has been selected. Total cost is: $%.2lf \n",dietCola);
          transaction(balance,dietCola);
          j = 0;
        }//end of else if(choice == 5)

        else if(choice2 == 6) {
          printf("Fanta has been selected. Total cost is: $%.2lf \n",fanta);
          transaction(balance,fanta);
          j = 0;
        }//end of else if(choice == 6)

        else if(choice2 == 7) {
          printf("Root Beer has been selected. Total cost is: $%.2lf \n",rootBeer);
          transaction(balance,rootBeer);
          j = 0;
        }//end of else if(choice == 7)

        else if(choice2 == 8) {
          printf("Dr.Pepper has been selected. Total cost is: $%.2lf \n",drPepper);
          transaction(balance,drPepper);
          j = 0;
        }//end of else if(choice == 8

        else {
          printf("Invalid Choice Please Choose an Option from the Menu\n");
        }//end of else
      }//end of while
    }//end of if(choice == 'O')

    else if(choice == 'V') {
      printf("You have selected option: %c\n",choice);
      printf("You have selected to see how much cash you have in your hand currently.\n");
      printf("***************************************************\n");
      viewHand(balance);//When program first runs balance would be 0
    }//end of else if(choice == 'V')

    else if(choice == 'D') {
      printf("You have selected option: %c\n",choice);
      printf("You have selected the view vending machine option.\n");
      printf("Here's the options! \n");
      printf("***************************************************\n");
      displayVendingOptions();
    }//end of else if(choice == 'D')

    else if(choice == 'G') {
      printf("You have selected option: %c\n",choice);
      printf("You have selected to pull more money out of the Unlimited Wallet. \n");
      printf("***************************************************\n");
      pullMoney(balance);
    }//end of else if(choice == 'G')

    else if(choice == 'E') {
      printf("You have selected option: %c\n",choice);
      printf("***************************************************\n");
      printf("Thank you for visiting the Unlimited Vending Machine! \n");
      printf("You have $%.2lf in your hand. Make sure to put that back into your Unlimited Wallet. \n",*balance);
      printf("Have a great day!\n");
      i = 0;//ends loop
    }//end of else if(choice == 'E')

    else{
        printf("Invalid Choice Please Choose an Option from the Menu\n");
        printf("***************************************************\n\n");

    }//end of else
  }//end of while
}

void viewHand(double *balance) {
  printf("You have $%.2lf in your hand currently \n",*balance);
  printf("***************************************************\n\n");
}

void transaction(double *balance, double price) {

  int i = 1;

  printf("Beginning Transaction Process. \n");

  while(i != 0) { // Loop to make user keep pulling money till they have enough for the drink
     if(price > *balance) {
       printf("***************************************************\n");
       printf("ERROR!!! You don't have enough money in your account. \n");
       printf("Please pull more money from the Unlimited Wallet. \n");
       printf("***************************************************\n");
       pullMoney(balance);
     }//end of if(total < 0)

     else {
       printf("You have $%.2lf in your hand before transaction. \n",*balance);
       printf("Putting in $%.2lf into the vending machine. \n",price);

       double total = *balance - price;// The transaction process
       *balance = total;

       printf("Transaction was successful! \n");
       printf("Your balance is now $%.2lf \n",*balance);
       i=0;//ends loop
       printf("***************************************************\n");
     }//end of else
   }//end of while
}

void pullMoney(double *balance){

  int choice;
  int i;
  double dollar = 1.00;
  double fiveDollars = 5.00;
  double twentyDollars = 20.00;

  while(i != 0) {
    printf("How much would you like to pull from the Unlimited Wallet? \n");
    printf("1: %.2lf \n",dollar);
    printf("2: %.2lf \n",fiveDollars);
    printf("3: %.2lf \n",twentyDollars);
    printf("Option Selected: ");
    scanf("%d",&choice);

    printf("You have selected Option: %d \n",choice);
    printf("***************************************************\n");

    if(choice == 1) {
      printf("$%.2lf has been added to your hand successfully! \n",dollar);
      printf("***************************************************\n");

      *balance = *balance + dollar;//User balance is updated to how much money user pulled
      printf("Balance is now $%.2lf \n",*balance);
      printf("***************************************************\n");
      i = 0;
    }//end of if(choice == 1)

    else if (choice == 2) {
      printf("$%.2lf has been added to your hand successfully! \n",fiveDollars);
      printf("***************************************************\n");

      *balance = *balance + fiveDollars;//User balance is updated to how much money user pulled
      printf("Balance is now $%.2lf \n",*balance);
      printf("***************************************************\n");
      i = 0;
    }//end of else if (choice == 2)

    else if (choice == 3) {
      printf("$%.2lf has been added to your hand successfully! \n",twentyDollars);
      printf("***************************************************\n");

      *balance = *balance + twentyDollars;//User balance is updated to how much money user pulled
      printf("Balance is now $%.2lf \n",*balance);
      printf("***************************************************\n");
      i = 0;
    }//end of else if (choice == 3)

    else {
      printf("Invalid Choice Please Choose an Option from the Menu\n");
      printf("***************************************************\n\n");
    }//end of else
  }//end of while

}

void displayVendingOptions() {
  printf("1. Sprite        $2.50\n");
  printf("2. Coca-Cola     $2.50\n");
  printf("3. Water         $2.00\n");
  printf("4. Gatorade      $3.00\n");
  printf("5. Diet Cola     $2.55\n");
  printf("6. Fanta         $2.55\n");
  printf("7. Root Beer     $1.50\n");
  printf("8. Dr. Pepper    $1.55\n");
  printf("***************************************************\n\n");
}
