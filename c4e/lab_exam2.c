#include <stdio.h>
#include <stdlib.h>

// Do not change this part of the code
int memoryAllocated = 0;

struct DataItem {
	int *pArr;
	int sz;
};

void *allocateMemory(int sz)
{
	memoryAllocated += sz;
	return malloc(sz);
}

void freeMemory(void* pMem,int sz)
{
	free(pMem);
	memoryAllocated -= sz;
}

void freeDataItem(struct DataItem *pQi)
{
	freeMemory(pQi->pArr, pQi->sz * sizeof(int));
	pQi->pArr = NULL;
}

struct Stack {
	struct DataItem *pStack;
	int top;
	int capacity;
};

struct Stack createStack(int capacity){
	struct Stack myStack;
	myStack.pStack = allocateMemory(sizeof(struct DataItem)*capacity);
	myStack.top = 0;
	myStack.capacity = capacity;

	return (myStack);
}

int sizeStack(struct Stack stack) {
	return stack.top;
}

int isEmptyStack(struct Stack stack) {
	return (stack.top == 0);
}

int isFullStack(struct Stack stack) {
	return (stack.top == stack.capacity);
}

void push(struct Stack *pStack, struct DataItem dataItem)
{
   if (isFullStack(*pStack))
		return;
	else{
		pStack->pStack[pStack->top] = dataItem;
		pStack->top++;
	}

}

struct DataItem pop(struct Stack *pStack)
{
	struct DataItem qi;
	qi.pArr = NULL;
	qi.sz = 0;

	if (isEmptyStack(*pStack))
		return qi;

	pStack->top--;
	qi = pStack->pStack[pStack->top];

	return qi;
}

struct Queue {
	struct DataItem *pQueue;
	int front;
	int rear;
	int count;
	int capacity;
};

struct Queue createQueue(int capacity) {
	struct Queue myQueue;
	myQueue.pQueue = allocateMemory(sizeof(struct DataItem)*capacity);
	myQueue.front = 0;
	myQueue.rear = 0;
	myQueue.count = 0;
	myQueue.capacity = capacity;

	return (myQueue);
}

int sizeQueue(struct Queue queue) {
	return queue.count;
}

int isEmptyQueue(struct Queue queue) {
	return (queue.count == 0);
}

void enqueue(struct Queue *pQueue, struct DataItem item)
{
	if (sizeQueue(*pQueue) == pQueue->capacity)
		return;

	pQueue->pQueue[pQueue->rear] = item;
	pQueue->rear = (pQueue->rear + 1) % pQueue->capacity;
	pQueue->count++;
}

struct DataItem dequeue(struct Queue *pQueue)
{
	struct DataItem qi;
	qi.pArr = NULL;
	qi.sz = 0;

	if (isEmptyQueue(*pQueue))
		return qi;

	qi = pQueue->pQueue[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->capacity;
	pQueue->count--;

	return qi;
}

void printArr(int arr[], int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Debugging Print Functions
void printQueue(struct Queue queue)
{
	printf("Queue is (%d)\n",queue.count);
	for (int i=0;i<queue.count;++i)
	{
		int index = (queue.front + i) % queue.capacity;
		printf("%d: ",i);
		printArr(queue.pQueue[index].pArr, queue.pQueue[index].sz);
	}
}

void printStack(struct Stack stack)
{
	printf("Stack is (%d)\n", sizeStack(stack));
	int top = stack.top-1;
	for (int i = 0; i < sizeStack(stack); ++i, top--)
	{
		printf("%d: ", i);
		printArr(stack.pStack[top].pArr, stack.pStack[top].sz);
	}
}

// You are going to implement body of functions merge and mergeSort
// Do not change the signature of the functions, but just the body

// Merges 2 data arrays in the DataItems pItem1 and pItem2 respectively.
struct DataItem merge(struct DataItem *pItem1, struct DataItem *pItem2)
{
	// Implement this function's body
	struct DataItem *newDataItem = allocateMemory(pItem1->sz + pItem2->sz);

	int itemOneIndex = 0;
	int itemTwoIndex = 0;
	int index = 0;

	while (itemOneIndex < pItem1->sz && itemTwoIndex < pItem2->sz)
	{
		if (pItem1->pArr[itemOneIndex] <= pItem2->pArr[itemTwoIndex])
		{
			newDataItem->pArr[index] = pItem1->pArr[itemOneIndex];
			itemOneIndex++;
		}

		// (pItem1->pArr[itemOneIndex] >= pItem2->pArr[itemTwoIndex])
		else
		{
			newDataItem->pArr[index] = pItem2->pArr[itemTwoIndex];
			itemTwoIndex++;
		}
		index++;
	}

	while (itemOneIndex < pItem1->sz)
	{
		newDataItem->pArr[index] = pItem1->pArr[itemOneIndex];
		itemOneIndex++;
		index++;
	}

	while (itemTwoIndex < pItem2->sz)
	{
		newDataItem->pArr[index] = pItem2->pArr[itemTwoIndex];
		itemTwoIndex++;
		index++;
	}

	return *newDataItem;
}

// Iterative mergeSort using stack or queue
struct DataItem mergeSort(int arr[], int sz)
{
	// Implement this function's body

	int count = sz - 1;

	struct Queue *newQueue = allocateMemory(sz);
	struct DataItem *newArray = allocateMemory(sz);

	// struct DataItem *itemOne = allocateMemory();
	// struct DataItem *itemTwo = allocateMemory();


	for (int i = 0; i < sz; i++)
	{
		newArray->pArr[i] = arr[i];
		enqueue(newQueue,newArray->pArr[i]);
	}

	while (count != 0)
	{
		int *itemOne = dequeue(&newQueue);
		int *itemTwo = dequeue(&newQueue);

		enqueue(newQueue,merge(itemOne,itemTwo));

		count--;
	}

	struct DataItem *temp = allocateMemory(sz);
	temp->pArr = *newQueue;
	temp->sz += 1;

	freeMemory(&newArray,sz);

	return *temp;

}
// End of mergeFunction implementation

// Do not change the main function
int main(void)
{
	int i, numInputs, countOfItems, value;

	FILE* inFile = fopen("input.txt","r");
	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		printf("1. Memory Allocated : %d\n", memoryAllocated);
		fscanf(inFile, " %d\n", &countOfItems);
		int *pArr = allocateMemory(sizeof(int)*countOfItems);
		for (i = 0; i < countOfItems; i++)
		{
			fscanf(inFile," %d", &value);
			pArr[i] = value;
		}

		printf("2. Memory Allocated : %d\n", memoryAllocated);

		printf("Input Data:\n");
		printArr(pArr, countOfItems);
		struct DataItem merged = mergeSort(pArr, countOfItems);
		printf("Sorted Data:\n");
		printArr(merged.pArr, merged.sz);

		printf("3. Memory Allocated : %d\n", memoryAllocated);

		freeDataItem(&merged);
		freeMemory(pArr, countOfItems * sizeof(int));
		pArr = NULL;
		printf("4. Memory Allocated : %d\n", memoryAllocated);
		printf("----------------------------------------------------\n");
	}

	fclose(inFile);
}
