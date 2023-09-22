#include <stdio.h>
int main()
{
    char name[20];
    printf("Enter name: ");
    gets(name);     // read string. This can take multi word strings as input. But using gets is not recommended. See the slide for more explanation
    printf("Name: ");
    puts(name);    // display string
    return 0;
}
