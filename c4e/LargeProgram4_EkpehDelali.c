//Delali Ekpeh
//Dr. Steinberg
//COP3223C Section 1
// Large Program 4
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 30

typedef struct {

  int id;
  char firstName [MAX_SIZE];
  char lastName [MAX_SIZE];
  char house [MAX_SIZE];
  double gpa;

}student_t;

//Prototypes
void greeting(); //Greets User with welcome message
void menu(); //User interface menu to interact with database
void createStudent(student_t *student, int *i); //Creates new student
void displayStudent(student_t *student,int *record); //Displays all student(s) in the database
void populateStudent(student_t *student, int *i); //Hardcodes 6 students into database
void searchStudent(student_t *student, int *record); //Searches student by ID
void removeStudent(student_t *student, int *record); //Removes student by ID
void printDatabase(student_t *student, int *record); //Prints all students into a text file

int main() {

  greeting();
  menu();

  return 0;
}

void greeting() {

  printf("---------------------------------------\n");
  printf("Welcome to Cookman Student Database!\n");
  printf("Check Menu for desired action: \n");
  printf("---------------------------------------\n");
}

void menu() {

  int x = 1;
  char choice;
  student_t student;
  student_t *ptr = &student; //Declared ptr to hold the address of the struct student
  int y = 0;
  int *iptr = &y;

  populateStudent(ptr,iptr);

  while(x != 0) {
    printf("Please select one of the following options. \n");
    printf("I: Insert a new student's data. \n");
    printf("R: Remove an existing studnet. \n");
    printf("S: Search if student record is exists. \n");
    printf("D: Displays all student record. \n");
    printf("E: Exits database and prints record. \n");
    printf("---------------------------------------\n");

    printf("Please select an option: ");
    scanf(" %c", &choice);
    choice = toupper(choice); //Make sure choice is uppercased

    //Catches if input isn't 'I', 'R', 'S', 'D', or 'E'
    if(choice != 'I' && choice != 'R' && choice != 'S' && choice != 'D' && choice != 'E') {
      printf("Invalid Choice Please Choose an Option from the Menu\n");
      printf("---------------------------------------\n");
    }

    else if(choice == 'I') {
      printf("Please Enter New Student Info: \n");
      printf("---------------------------------------\n");
      createStudent(ptr,iptr);
    }

    else if(choice == 'R') {
      printf("Removing Student \n");
      printf("---------------------------------------\n");
      removeStudent(ptr,iptr);
    }

    else if(choice == 'S') {
      printf("Seraching for Student \n");
      printf("---------------------------------------\n");
      searchStudent(ptr,iptr);
    }

    else if(choice == 'D') {
      printf("Displaying Student(s) \n");
      printf("---------------------------------------\n");
      displayStudent(ptr,iptr);
    }

    else if(choice == 'E') {
      printf("Exiting database \n");
      printDatabase(ptr,iptr);
      x = 0; //Exits while loop
    }
  }
}

void createStudent(student_t *student, int *i) {

  int x;

  x = *i + 1;
  student[*i].id = x; //A new student's Id is always set to the
                      //amount of students in the database + 1

  printf("------Creating new Student ID---------\n");
  printf("Student ID is: %d \n", student[*i].id);

  printf("Enter the First Name of the student: ");
  scanf("%s", student[*i].firstName);

  printf("Enter the Last Name of the student: ");
  scanf("%s", student[*i].lastName);

  printf("Enter name of what house the student is from: ");
  scanf("%s", student[*i].house);

  printf("Enter student's GPA: ");
  scanf("%lf", &student[*i].gpa);
  printf("---------------------------------------\n");

  *i = *i + 1; //Adds one to the counter. To count for adding one new student
}

void displayStudent(student_t *student, int *record) {

  for(int i = 0; i < *record; i++ ) { //record holds how many students are in the struct array
    printf("ID: %d \n", student[i].id);

    printf("First Name: ");
    puts(student[i].firstName);

    printf("Last Name: ");
    puts(student[i].lastName);

    printf("House: ");
    puts(student[i].house);

    printf("GPA: %.2lf \n", student[i].gpa);
    printf("---------------------------------------\n");
  }
}

void searchStudent(student_t *student, int *record) {

  int searchID;
  int x = 0;

  while(x != 1) {
    printf("Please Enter the ID of the Student you're looking for : ");
    scanf("%d", &searchID);

    if(searchID > *record) { //User can't search outside the bounds of the array struct
      printf("Student ID doesn't exist \n");
      printf("---------------------------------------\n");
      x = 1;
    }

    else if(searchID <= *record) {

      for(int i = 0; i < *record; i++ ) {

        if(student[i].id == searchID) { //Searches student by ID
          printf("---------------------------------------\n");
          printf("Student Found! Here's their info: \n");
          printf("---------------------------------------\n");
          printf("ID: %d \n", student[i].id);

          printf("First Name: ");
          puts(student[i].firstName);

          printf("Last Name: ");
          puts(student[i].lastName);

          printf("House: ");
          puts(student[i].house);

          printf("GPA: %.2lf \n", student[i].gpa);
          printf("---------------------------------------\n");
          x = 1; //Ends Loop
          break;
        }
      }
    }
  }
}

void removeStudent(student_t *student, int *record) {

  int searchID;
  int x = 0;
  int size = *record;

  while(x != 1) {
    printf("Please Enter the ID of the Student you would like to remove: ");
    scanf("%d", &searchID);

    if(searchID > *record) {
      printf("Student ID doesn't exist \n");
      printf("---------------------------------------\n");
      x = 1; //Ends loop
      break;
    }

    else if(searchID <= *record) {
      for(int i = 0; i < *record; i++ ) {
        if(student[i].id == searchID) {
          printf("Student %s has been deleted from database \n", student[i].firstName);
          printf("---------------------------------------\n");
          for(int j = i; j < size - 1; j++) {
            student[j+1].id = j + 1; //Updates student's id
            student[j] = student[j + 1]; //Updates student's index by
                                        //replacing the student the user wants to remove
            x = 1;
            }
        }
      }
      *record = *record - 1; //Minues the student from the total array count
    }
  }
}

void printDatabase(student_t *student, int *record) {

  FILE *fptr = fopen("studentDatabase.txt","w");//Opens file
  //What is written to the file:
  fprintf(fptr,"Cookman School Student Records \n");
  fprintf(fptr,"---------------------------------------\n");

  for(int i = 0; i < *record; i++ ) {
    fprintf(fptr,"ID: %d \n", student[i].id);

    fprintf(fptr,"First Name: %s\n", student[i].firstName);

    fprintf(fptr,"Last Name: %s \n", student[i].lastName);

    fprintf(fptr,"House: %s\n", student[i].house);

    fprintf(fptr,"GPA: %.2lf \n", student[i].gpa);
    fprintf(fptr,"---------------------------------------\n");
  }
  fclose(fptr);
}

void populateStudent(student_t *student, int *i) {

  //Hardcoded students into strtut

  student[0].id = 1;
  strcpy(student[0].firstName, "Randy");
  strcpy(student[0].lastName, "Orton");
  strcpy(student[0].house, "Florida");
  student[0].gpa = 2.87;

  student[1].id = 2;
  strcpy(student[1].firstName, "Abby");
  strcpy(student[1].lastName, "Jones");
  strcpy(student[1].house, "Darnell");
  student[1].gpa = 3.5;

  student[2].id = 3;
  strcpy(student[2].firstName, "Chris");
  strcpy(student[2].lastName, "Pairs");
  strcpy(student[2].house, "Darnell");
  student[2].gpa = 3.63;

  student[3].id = 4;
  strcpy(student[3].firstName, "Daniel");
  strcpy(student[3].lastName, "Davis");
  strcpy(student[3].house, "Darnell");
  student[3].gpa = 2.9;

  student[4].id = 5;
  strcpy(student[4].firstName, "Esinam");
  strcpy(student[4].lastName, "Ekpeh");
  strcpy(student[4].house, "Stanton");
  student[4].gpa = 3.87;

  student[5].id = 6;
  strcpy(student[5].firstName, "Joe");
  strcpy(student[5].lastName, "Momma");
  strcpy(student[5].house, "Ravenclaw");
  student[5].gpa = 1.53;

  *i = 6; //Sets counter to 6
}
