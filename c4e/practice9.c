#include <stdio.h>

struct book_s { //User defined data type

  //Components of the struct book
  int numpages; // number of pages in the book
  char author [30]; // who wrote the book
  char title [30]; // name of book
  int year; //publish year
};

typedef struct {

  int time;
  char title [30];
  //struct book_s book;

}movie_t;

//Prototypes
void printStruct(struct book_s *myBook);
void printTypedef(movie_t myMovie);
movie_t createMovie();

int main() {
//Structures and Typedef Structs

  int x; // Data type: int.
        // Name: x
  struct book_s book1; //Data type: struct book_s
                      // Name: book1

  struct book_s *ptr;
  ptr = &book1;

  //How to get user input and scan it into struct.
  // printf("Enter the Author of the book lastname: ");
  // scanf("%s", book1.author);//Remember strings are 'pointers' so no & in the scan
  //
  // printf("Enter the Title of the book: ");
  // scanf("%s", book1.title);
  //
  // printf("Enter the books publish year: ");
  // scanf("%d", &book1.year);

  book1.numpages = 123;//Simple declaration
  printStruct(&book1);

  (*ptr).numpages = 5000;
  // ptr->numpages = 5000; also can be used like this
  printStruct(&book1);

  printf("book1.author = %s \n", book1.author);
  printf("book1.title = %s \n", book1.title);
  printf("book1.year = %d \n", book1.year);
  printf("book1.numpages = %d \n", book1.numpages);


  movie_t movie1 = createMovie();//Data type: movie_t
                                //Name: movie1 = the fucntion 'createMovie()'
  printTypedef(movie1);//movie1 contains components of the struct filed out.



  //Arrays and Structures--------------------
  int arr[5];
  movie_t lib[5]; //Data type: movie_t
                  // Name: lib but declared as an array
  printf("Population the array Struct of Movies \n");
  printf("Enter the 1st movie title: ");
  scanf("%s", lib[0].title);
  //
  // printf("Enter %s length: ", lib[0].title);
  // scanf("%s", lib[0].time);



  return 0;
}

void printStruct(struct book_s *myBook) {

  printf("\nInside the Print Struct fucntion: \n");
  printf("book1.author = %s \n", myBook->author);//Indirect operator to point to a component inside a pointer struct
  printf("book1.title = %s \n", myBook->title);
  printf("book1.year = %d \n", myBook->year);
  printf("book1.numpages = %d \n", myBook->numpages);
}

movie_t createMovie(){

  movie_t movie1;

  printf("\nCreating Movie for you! \n");

  printf("Address of movie1 is %p \n", &movie1);

  printf("Enter the movie title: ");
  scanf("%s", movie1.title);

  printf("Enter the movie length: ");
  scanf("%d", &movie1.time);

  printf("Done creating the Movie \n");

  return movie1;
}

void printTypedef(movie_t myMovie) {

  printf("\nInside the Print TypeDef fucntion: \n");
  printf("myMovie.title = %s \n", myMovie.title);
  printf("myMovie.time = %d \n", myMovie.time);
  printf("Address of myMovie is %p \n", &myMovie);
}
