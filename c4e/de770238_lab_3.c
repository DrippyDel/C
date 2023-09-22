#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node* next;
} node;

//Prototypes
void markEven(node *head);
void deallocateList(node **head);
int insertList(node **head, int data);
void printList(node *head);

void markEven(node* head)
{
  node *temp = head;
  // Traversing through linked list
  while (temp != NULL)
  {
    // if node data is even
    if (temp->data % 2 == 0)
      {
        node *newNode = (node*) malloc(sizeof(node));
        newNode->data = -1;
        // Link the new node to the current node's next node
        newNode->next = temp->next;

        // Link the current node to the new node
        temp->next = newNode;
        
        // Move the current pointer to the newly created node
        temp = temp->next;
        //printf("%d \n", temp->data);
      }
      // Goes to the next node
      temp = temp->next;
  }
}

void deallocateList(node** head)
{
  node* tmp = *head;
  while (tmp != NULL)
  {
    *head = tmp->next;
    free(tmp);
    tmp = *head;
  }
  *head = NULL;
}

int insertList(node** head, int data)
{
  node* newNode = (node*) malloc(sizeof(node));

  if (newNode == NULL)
    return -1;

  newNode->data = data;
  newNode->next = NULL;
  newNode->next = *head;

  *head = newNode;

  return 1;
}

void printList(node* head)
{
  node* tmp = head;
  while (tmp != NULL)
  {
    printf("%d",tmp->data);

    if (tmp->next != NULL)
    {
      printf(", ");
    }
    else
    {
      printf(".\n");
    }
    tmp = tmp->next;
  }
}

int main(void)
{
  node* head = NULL;
  insertList(&head, 8);
  insertList(&head, 3);
  insertList(&head, 1);
  insertList(&head, 7);
  insertList(&head, 6);
  insertList(&head, 2);

  printf("Initial List:\n");

  printList(head);
  markEven(head);

  printf("Marked List:\n");

  printList(head);
  deallocateList(&head);
}
