#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0

// Node struct
typedef struct Node
{
  int value;
  struct Node *next;
} Node;

// Linked List struct that holds head and tail
typedef struct LL
{
  Node *head;
  Node *tail;
} LL;

// Prints a linked list
void printLLHead(Node *head)
{
	Node *temp = head;

	printf("\n");

	while (temp != NULL)
	{
		printf("%d -> ", temp->value);
		temp = temp->next;
	}

	printf("NULL\n");
}

// Creates an empty linked list and returns the address
LL * createLL()
{
	// LL *newNode = (LL*) malloc(sizeof(LL));
  LL *newNode = NULL;

  return newNode;
}

// Initializes values inside an empty linked list to NULL
void initLL(LL *ll)
{
  ll->head = NULL;
  ll->tail = NULL;

}

// Creates an empty node and returns the address
Node * createNode()
{
    //Node *newNode = (Node *)malloc(sizeof(Node));
	 Node *newNode = NULL;

  return newNode;
}

// Creates a node that holds a value and returns the address
Node * createNodeWithValue(int val)
{
	//Node *newNode = (Node *)malloc(sizeof(Node));
  Node *newNode = NULL;

  newNode->value = val;

  return newNode;
}

// Return 1 if a node with a specific value exists within the linked list
// Otherwise, return 0
int containsNode(Node *head, int specificValue)
{
	Node *newNode = head;

  if (newNode->value == specificValue)
  {
    return 1;
  }

  return 0;
}

// /*
//  * NOTE:
//  * 	The following functions are meant to explore the different
//  * 	ways one could insert or remove nodes from a linked list.
//  *
//  * 	There are functions that do the same thing; however, they
//  * 	are slightly different due to way they have to be implemented.
//  *
//  * 	Make sure to read the comments carefully since they all explain
//  * 	the purpose of each function.
//  *
//  * 	You could approach each function with a different solution;
//  * 	however, in order to stay consistent, the function descriptions
//  * 	are written to guide you toward a specific solution.
//  *
//  * 	Feel free to play around with the functions in order to implement
//  * 	different solutions, but do keep in mind that the function
//  * 	descriptions are written to reflect the consistency that I usually
//  * 	aim to achieve whenever I write code (and which is something you
//  * 	should keep in mind whenever you write code in order to write cleaner,
//  * 	easier to understand code).
//  */
//
// // Inserts an empty node to the head of a linked list and returns the new head
// ??? insertEmptyNodeToHead(Node *head)
// {
// 	// your code goes here
// }
//
// // Inserts a node with a value to the head of a linked list and returns the new head
// ??? insertNodeWithValueToHead(Node *head, int val)
// {
// 	// your code goes here
// }
//
// // Inserts an empty node to the head of a linked list
// ??? insertNodeToListHead(LL *list)
// {
// 	// your code goes here
// }
//
// // Inserts a node with a value to the head of a linked list
// ??? insertNodeWithValueToListHead(LL *list, int val)
// {
// 	// your code goes here
// }
//
//
//
// // Inserts an empty node to the tail of a linked list and returns the head
// ??? insertEmptyNodeToTail(Node *head)
// {
// 	// your code goes here
// }
//
// // Inserts a node with a value to the tail of a linked list and returns the head
// ??? insertNodeWithValueToTail(Node *head, int val)
// {
// 	// your code goes here
// }
//
// // Inserts an empty node to the tail of a linked list
// ??? insertNodeToListTail(LL *list)
// {
// 	// your code goes here
// }
//
// // Inserts a node with a value to the tail of a linked list
// ??? insertNodeWithValueToListTail(LL *list, int val)
// {
// 	// your code goes here
// }
//
// /*
//  * NOTE:
//  * 	The following functions are meant to give you practice inserting a node
//  *  into the middle of a linked list or removing a node from the middle of
//  *  a linked list at some arbitrary index.
//  *
//  *  The index can start at 0 or 1 (that is up to you to decide).
//  *
//  *  Just make sure to stay consistent so you don't cause any errors
//  *  or confusion later on!
//  */
//
// // Inserts an empty node to a specific index in the linked list and returns the head
// ??? insertEmptyNodeToLLHead(Node *head, int index)
// {
// 	// your code goes here
// }
//
// // Inserts a node with a value to a specific index in the linked list and returns the head
// ??? insertNodeWithValueToLLHead(Node *head, int val, int index)
// {
// 	// your code goes here
// }
//
// // Inserts an empty node to a specific index in the linked list
// ??? insertEmptyNodeToLL(LL *list, int index)
// {
// 	// your code goes here
// }
//
// // Inserts a node with a value to a specific index in the linked list
// ??? insertNodeWithValueToLL(LL *list, int val, int index)
// {
// 	// your code goes here
// }
//
// // Takes in the head of a linked list and inserts a node with value val in between every node
// ??? insertBetweenAllNodesLLHead(Node *head, int val)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and inserts a node with value val in between every node
// ??? insertBetweenAllNodesLL(LL *list, int val)
// {
// 	// your code goes here
// }
//
//
//
// // Takes in the head of a linked list, removes a node from the head, and returns the new head
// ??? removeNodeFromHead(???)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and removes a node from the head
// ??? removeNodeFromListHead(???)
// {
// 	// your code goes here
// }
//
// // Takes in the head of a linked list, removes a node from the tail, and returns the head
// ??? removeNodeFromTail(???)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and removes a node from the tail
// ??? removeNodeFromListTail(???)
// {
// 	// your code goes here
// }
//
// // Takes in the head of a linked list and a value, removes the first instance of a node
// // with that value, and returns the head of the linked list
// ??? removeNodeWithValueFromLLHead(???)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and a value and removes the first instance of a node
// // with that value
// ??? removeNodeWithValueFromLL(???)
// {
// 	// your code goes here
// }
//
// // Takes in the head of a linked list and an index, removes the node
// // at that index, and returns the head of the linked list
// ??? removeNodeInIndexFromLLHead(???)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and an index and removes the node at that index
// ??? removeNodeInIndexFromLL(???)
// {
// 	// your code goes here
// }
//
// // Takes in the head of a linked list and removes all nodes with the value val
// ??? removeAllValuesFromLLHead(???)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and removes all nodes with the value val
// ??? removeAllValuesFromLL(???)
// {
// 	// your code goes here
// }
//
// // Takes in the head of a linked list and frees all nodes in the linked list
// ??? freeLLHead(???)
// {
// 	// your code goes here
// }
//
// // Takes in a linked list and frees the entire linked list
// ??? freeLL(???)
// {
// 	// your code goes here
// }
//


int main()
{
	/*
	 * Questions to consider:
	 *
	 * - What is the Big-O runtime if you add a node to the head? What if you added it to the tail?
	 * - What changes do you need to make if you were to use a circular linked list?
	 * - Can you add a node to the middle of a linked list if you only had access to the tail?
	 * - What are the benefits and drawbacks to using a doubly linked list?
	 * - What are the benefits and drawbacks to storing a tail pointer?
	 * - What are the differences between arrays and linked lists?
	 * - Why would a linked list be better to use than an array?
	 * - Why would an array be better to use than a linked list?
	 * - What are the differences/similarities between the Big-O runtimes for arrays and linked lists for:
	 *   > Insertion
	 *   > Deletion
	 *   > Search by index
	 *   > Search by value in a sorted list
	 *   > Search by value in an unsorted list
	 * - What considerations do you need to make when writing functions for linked lists and what is the
	 *   error that you need to always look out for and try to avoid as you write these functions?
	 */

	// your code goes here

	return 0;
}
