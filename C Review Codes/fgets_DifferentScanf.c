#include <stdio.h>
#include <string.h>
//gets method is dangerous as it does not care about the size of the char array and can takes more than the size.
//there are multiple alter natives to take string input with spaces.
//one is scanf("%[^\n]s",arr);
//another one is fgets(). fgets also include '\n' you press at the end of inputing an string. So, you have to remove that '\n'
int main()
{
    char name[30];
    char name2[30];
    char c;
    int i;
    printf("Enter name: ");
    scanf("%[^\n]s",name);

    printf("Name : %s", name);
    while ((c = getchar()) != '\n' && c != EOF); //the enter you pressed can get transferred to the next input. So ignoring that \n
    printf("\nEnter another name: ");
    fgets(name, sizeof(name), stdin); //if you input and press enter, it adds '\n' at the end.
    printf("Name : %s", name);// you will see extra new line in the output. Let's remove it.
    printf("No new line in the last printf but it is showing in new line");
    name[strcspn(name, "\n")] = 0; //this line removes that \n from the string
    printf("\nName : %s", name);

    return 0;

}

/*output
Enter name: Nusair Ahmed
Name : Nusair Ahmed
Enter another name: Manha Ahmed
Name : Manha Ahmed
No new line but it is showing in new line
Name : Manha Ahmed
Process returned 0 (0x0)   execution time : 12.462 s
*/
