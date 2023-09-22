#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	struct node *newNode = (node *)malloc(sizeof(struct node));

	newNode = head;

	while (newNode != NULL)
	{
		newNode = newNode->next;
		count++;
	}

	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{

	int cLength = length(head);

	char* str = (char*)malloc(sizeof(char));
	struct node *temp = head;

	int i = 0;

	while (temp != NULL)
	{
		sprintf(str + i, "%c ", temp->letter);
		temp = temp->next;
		i = i + strlen(str + i);
	}

	// newNode = head;

	// while (newNode != NULL)
	// {
	// 	//printf("%c \n", newNode->letter);
	// 	newNode = newNode->next;
	//
	// }

	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	 struct node *newNode = (node *)malloc(sizeof(struct node));

	if (newNode == NULL)
		return;

		newNode->letter = c;
		newNode->next = NULL;
		newNode->next = *pHead;

		*pHead = newNode;
		//printf("%c \n ", newNode->letter);

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node *temp = *pHead;
	while (temp != NULL)
	{
		*pHead = temp->next;
		free(temp);
		temp = *pHead;
	}

	*pHead = NULL;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		int cLength = length(head);

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
