#include <stdio.h>
#include <string.h>

int main() {
//Strings     - arrray of character
//%s String placeholder

  //char word [] = {'C','A','T','/0'};//The last character in a string is null. Null character is also a stop sign for the complier
  char string1[30];//declaration
  char string2[] = "Strings are fun!"; // declaration and initialization
  char animal [] = "Birds";

  printf("String2 = %s \n", string2);

  char class[30];

  printf("Enter Course: ");
  scanf("%s", class);//one word
  printf("The class is %s \n", class);

  //ways to collect string input plus scanf
   puts(class); // prints like printf
   fgets(class, sizeof(class), stdin);//mutliple words

  //strcpy copys a string into another string variable ------------

  char str [30] = "Frog";
  char str2 [30] = "Chicken";
  printf("str is %s \n", str);
  strcpy(str, "Dog"); // strcpy(Destination, source) DS
  printf("str is %s \n", str ); // Final Draw out how 'Birds \0' become 'Dog \0 s \n'

  strncpy(str,str2,sizeof(str)- 1);//str copys how many elements in
                                    // the third peramater into str2
  printf("str at the end  is %s \n", str);
  //-------------------


  //strcat combines two strings together ----------
  char word3[10] = "Ant";

  char word4[] = "Man";

  strcat(word3,word4);
  strcat(word3, " "); //Manually put in a space to build words
  printf("word3 is now %s\n", word3);

  //strncat(word3, word4, 4);//Only 4 elements would be catnated to the end of word3
  //--------------------

  //strlen returns the length of a string ---------
  char pharse [100] = "Agatha Coven of Chaos";
  int size = strlen(pharse);

  printf("%s contains %d characters \n", pharse, size);
  //-----------

  //strcmp compares string 1 and string 2
  char s1 [30] = "agatha";
  char s2 [30] = "agatha";
  char s3 [30] = "cgatha";
  char s4 [30] = "bgatha";

  int result = strcmp(s1,s2);
  printf(" strcmp(%s, %s) = %d \n", s1, s2, result );

  result =  strcmp(s1,s3);
  printf(" strcmp(%s, %s) = %d \n", s1, s3, result );

  result = strcmp(s3,s1);
  printf(" strcmp(%s, %s) = %d \n", s3, s1, result );

  result = strcmp(s4,s2);
  printf(" strcmp(%s, %s) = %d \n", s4, s2, result );

    return 0;
}
