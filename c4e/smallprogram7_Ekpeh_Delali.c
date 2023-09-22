//Delali Ekpeh
//Dr. Steinberg
//COP3223C Section 1
//Small Program 7
#include <stdio.h>
#include <string.h>

//Prototypes
void deblank(char *input, char *output); //Removes any white spaces from a string.
void pluralize(char *noun);//Pluralizes string input
void fact(char *str);//Determines how many letters, digits, and punctuation a string contains
char *substring(char *string, char *substr);// Checks if a string is a substring of the first string

int main() {

  char input [20];
  char output [20];
  char noun [20];
  char str [20];
  char string[20];
  char substr[20];


  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin); //Scans user entered string even if there's a space
  deblank(input,output);
  printf("Output String with no blanks: %s",output);

  printf("Enter string to be pluralize: ");
  fgets(noun, sizeof(noun), stdin);
  pluralize(noun);
  printf("Word pluralize: %s\n",noun);

  printf("Enter a string with no spaces: ");
  scanf("%s", str);
  fact(str);

  printf("Enter the string: ");
  scanf("%s", string);
  printf("Enter the substring you would like to look for: ");
  scanf("%s", substr);
  char *result = substring(string,substr);

  if(result == NULL) {
    printf("Substring %s doesn't exist! \n", substr);
  }

  else{
    printf("Substring %s exists! \n ", substr);
  }
  return 0;
}

void deblank(char *input, char *output) {

  int count = 0;

  for(int i = 0; input[i]; i++) {
    if(input[i] != ' ') {           // Builds a new string by excluding
      output[count++] = input[i];  // space character from the array
    }
  }
  output[count] = '\0'; //Sets the last index + 1 as the null character
}

void pluralize(char *noun) {

  int len = 0;
  len = strlen(noun); // Returns length of the string

    //Changes index in a string to a certain letter or adds letters to string
    if(noun[len - 2] == 'y') {//Strings that end with y
      noun[len - 2] = 'i';
      noun[len - 1 ] = 'e';
      noun[len] = 's';
      noun[len + 1] = '\0';
    }

    else if(noun[len - 2] == 's') {//Strings that end with s
      noun[len - 1] = 'e';
      noun[len] = 's';
      noun[len + 1] = '\0';
    }

    else if(noun[len - 3] == 'c' && noun[len - 2] == 'h') {//Strings that end with ch
      noun[len - 1] = 'e';
      noun[len] = 's';
      noun[len + 1] = '\0';
    }

    else if(noun[len - 3] == 's' && noun[len - 2] == 'h') {//Strings that end with sh
      noun[len - 1] = 'e';
      noun[len] = 's';
      noun[len + 1] = '\0';
    }

    else {//Other cases
      noun[len - 1] = 's';
    }
}

void fact(char *str) {

  int i = 0;
  int letter = 0;
  int num = 0;
  int punc = 0;

  while(str[i] != '\0') {

    if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) { //Anything a - z and  A - Z
      letter++;
    }

    else if(str[i] >= '0' && str[i] <= '9') {//Any numbers
      num++;
    }

    else{//what ever is left on the keyboard
      punc++;

    }
    i++;
  }
  printf("%s has \n", str);
  printf("%d letters \n", letter);
  printf("%d digits \n", num);
  printf("%d punctuation characters \n", punc);
}

char *substring(char *string, char *substr) {

  int lenStr = strlen(string);
  int lenSub = strlen(substr);

  int endStr = lenStr - lenSub + 1; //Checks up to the length of the string
                                    //and the also substring
  for(int i = 0; i < endStr; i++) {

    for(int x = 0; x < lenSub; x++){

      if(substr[x] != string[i + x]){
        return NULL;
        break;
      }

      else {
        return &substr[i];
      }

    }

  }
  return NULL;
}
