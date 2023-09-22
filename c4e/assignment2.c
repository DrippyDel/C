// Delali Ekpeh
// de770238
#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;

}node;

// Prototypes
void insertAfterN(node* head, int M, int N);
int isPalindrome(char *str);
void initialize(stack* s); // initializes an empty stack.
int push(stack* s, char value); //pushes the char value to the stack
int isEmpty(stack* s); // Returns 1 if the stack is empty, 0 otherwise.
char pop(stack* s); // pops and returns character at the top of the stack.
char peek(stack* s); // returns character at the top of the stack

int main ()
{


  return 0;
}

void insertAfterN(node *head, int M, int N)
{
  // Base case or when we reach the end of the linkedList
  if (head == NULL)
    return;

  node *temp = head;

  if (temp->data == N)
  {
    node *newNode = malloc(sizeof(node));

    newNode->data = M;
    newNode->next = temp->next;

    head->next = newNode;
    // temp = newNode;

    insertAfterN(newNode->next,M,N);
  }

    // Traverses the linked List recursively
    insertAfterN(temp->next, M, N);

  // while (temp != NULL)
  // {
  //   node *newNode = (node*)malloc(sizeof(node));
  //   newNode->data = M;
  //   newNode->next = NULL;
  //
  //   // Each time N is found M is inserted after
  //   if(temp->data == N && curr->data == N)
  //   {
  //     temp->next->data = newNode->data;
  //     newNode->next = curr->next;
  //
  //   }
  //   // Traversing LinkedList
  //   temp = temp->next;
  //   curr = curr->next;
  // }
}

int isPalindrome(char *str)
{
  struct stack s;
  initialize(&s);

  int len = strlen(str);

  if (str == NULL)
    return 1;

    if(len % 2 == 0)
    {
      int firsthalf = (len / 2);
      int secondHalf = (len / 2);
    }
    else
    {
      int firsthalf = (len / 2) - 1;
      int secondHalf = (len / 2) + 1
    }

  // Populates Stack with first half
  for (int i = 0;; i < firstHalf; i++)
  {
    push(&s,str[i]);
  }


  // Compares first have of the string to second half
  // for (secondHalf; secondHalf >= (len/2) ; secondHalf--)
  for (int i = secondHalf; i < len; i++)
  {
    // Is Palindrome if true
    if (pop(&s) != str[secondHalf])
      return 0;
  }

  return 1
}
