#include  <stdio.h>
#include <stdlib.h>

// Queues   


#define SIZE 10

struct queue
{
  int *elements;
  int front;
  int numElements;
  int capacity = SIZE;
};

typedef struct {
  node *head;
  node *tail;
} Queue;

// Prototypes
void init(struct queue *qPtr);
int enQueue(struct queue *qPtr, int value);
int deQueue(struct queue *qPtr);


int main ()
{

  return 0;
}

// Initializes a Queue
void init(struct queue *qPtr)
{
  // Allocates a pointer array
  qPtr->elements = (int*) malloc(sizeof(int) * SIZE);

  qPtr->front = 0;
  qPtr->numElements = 0;
}

// Inserting into a Queue (Array)
int enQueue(struct queue *qPtr, int value)
{
  // Checks whether queue is full
  if (qPtr->numElements == qPtr->capacity)
    return 0;

  // Front stays the same and size of queue updates.
  // (Front + Number of elements) % Max size
  qPtr->elements[(qPtr->front + qPtr->numElements) % qPtr->capacity] = value;

  qPtr->numElements++;

  return 1;
}

// Value is deleted from Queue
int deQueue(struct queue *qPtr)
{
  // Checks if queue is empty
  if (qPtr->numElements == 0)
    return 0;

  int value = qPtr->elements[qPtr->front];

  // Front moves to next index. Formula allows for circular
  qPtr->front = (qPtr->front + 1) % qPtr->capacity;

  qPtr->numElements--;

  return value;

}
