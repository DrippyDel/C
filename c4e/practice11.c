#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{

  int data;
  struct node_s * nextptr;//Struct node_s referencing to itself

}node_t;

struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

//Prototypes
void insertBeginning (struct Node **ppHead, int value); // Insert data into beginning of node (doubly)
void tailInsert (struct Node **ppHead, int value); // Insert data into end of node (doubly)

node_t * insert(node_t **head,int value); //Insert data into node (single)
void removeList(node_t **head); //Deletes Node
void displayList(node_t * head); // Displays Nodes

int main() {
// Linked Lists----------------

  node_t *head = NULL;

  head = insert(&head,8);
  head = insert(&head,9);
  head = insert(&head,200);
  head = insert(&head,10);
  displayList(head);
  removeList(&head);

  return 0;
}

node_t * insert(node_t **head, int value) {

  struct node_s *newNode = (node_t *)malloc(sizeof(node_t));

  //check to see if empty
  if(head == NULL)
  {
    return NULL;
  }

  newNode->data = value;
  newNode->nextptr = NULL;
  newNode->nextptr = *head;

  *head = newNode;

  return *head;

}

// Deletes all nodes in the linkedList
void removeList(node_t **head) {

  struct node_s *temp = *head;

  // Traverse linkedList
  while(temp != NULL)
  {
    *head = temp->nextptr;
    free(temp);
    temp = *head;
  }

  *head = NULL;

}

void displayList(node_t * head) {

  node_t * temp = head;

  while(temp != NULL) {

    printf("----------------------------------------\n");
    printf("Address of Current Node is %p\n", &temp);
    printf("THe data stored at node is %d\n", temp->data);
    printf("The Address of nextptr points to %p\n", temp->nextptr);
    printf("----------------------------------------\n");
    temp = temp->nextptr;

  }
}

void insertBeginning (struct Node **ppHead, int value)
{
  // Allocate memory for new node
  struct Node *newNode = malloc(sizeof(struct Node));

  if (newNode == NULL)
    return;

  // Setting up node values
  newNode -> data = value;
  newNode -> prev = NULL;
  newNode -> next = NULL;

  // Update pointers
  newNode -> next = *ppHead;

  struct Node *temp = NULL;

  // Change prev of head node to new node
  if(*ppHead != NULL)
  {
    // (*ppHead) -> prev = newNode;

    // Temp holds the value of ppHead and doesn't update the head of the linked list
    struct Node *temp = *ppHead;
    temp -> prev = newNode;
  }

  *ppHead = newNode;

}
