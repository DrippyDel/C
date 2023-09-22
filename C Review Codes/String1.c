#include <stdio.h>
int main()
{
    char name[20];
    char name2[20];
    printf("Enter name: ");
    //Note that scanf with %s cannot take multiple word sentences.
    scanf("%s %s", name, name2); //if you enter two strings one after another by space, first word will go to name1 and the second word will got to name2
    printf("Your name is %s and %s.", name, name2);
    return 0;
}

/*
Output:
Enter name: Nusair Ahmed
Your name is . Nusair //see it failed to keep Ahmed in the string
*/
