#include <stdio.h>
#include <stdlib.h>

// Stacks

struct stack
{
  int data;
  struct stack *next;
};
// Starts stack as empty
struct stack *top = NULL;

// Prototypes
void push(int value);
int pop();
int peek();
int isEmpty();
void print();

int main ()
{
  int choice = 0;
  int data = 0;

  while(1)
  {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Print\n");
    printf("5. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        printf("Enter the element to be pushed: ");
        scanf("%d", &data);
        push(data);
        break;

      case 2:
        data = pop();
        printf("Deleted element is %d \n",data);

      case 3:
        printf("The element at the top of the stack is %d\n",peek());
        break;

      case 4:
        print();
        break;

      case 5:
        exit(1);

      default:
        printf("Wrong Choice \n");
        break;
    }
  }
  return 0;
}

void push(int value)
{
  // Create new node
  struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));

  // when requested memeory can't ve allocated
  if (newNode == NULL)
  {
    printf("Stack OverFlow. ");
    exit(1);
  }

  newNode->data = value;
  newNode->next = NULL;

  // The next node would be under the top of node of stack
  newNode->next = top;

  // Top will always point to the last inserted data
  top = newNode;
}

int pop()
{
  int value = 0;

  struct stack *temp;
  // Temp now points to the top of stack
  temp = top;

  // Storing the value at the top of the slack
  value = temp->data;

  // Update the top pointer so it can point to the next node of stack
  top = top->next;

  free(temp);
  temp = NULL;

  return value;
}

int peek()
{
  if(isEmpty())
  {
    printf("Stack Underflow.");
    exit(1);
  }

  // Just return whatever top holds
  return top->data;
}

int isEmpty()
{
  // Stack is empty if top is NULL
  if (top == NULL)
  {
    return 1;
  }
  else
    return 0;
}

void print()
{
  struct stack *temp;
  temp = top;
  printf("The stack elements are: ");

  // Traversing the stack
  while(temp != NULL)
  {
    printf("%d ", temp->data);

    // Goes down the stack
    temp = temp->next;
  }
  printf("\n");
}
