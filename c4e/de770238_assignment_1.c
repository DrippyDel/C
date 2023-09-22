#include <stdio.h>
#include <stdlib.h>

struct present
{
  char *present_name;
  float price;
};

//Prototypes
struct present *delete_present_list(struct present *present_list,int num);

struct present *delete_present_list(struct present *present_list,int num)
{
  // Incase array passed was NULL
  if (present_list == NULL)
    {
      return NULL;
    }

  // Iterates over each present and frees each string for each present
  for (int i = 0; i < num; i++)
  {
    free(present_list[i].present_name);
  }

  // Free present_list array
  free(present_list);

  return present_list;
}

// head -> 1-> 4 -> 2 -> 3 -> 5 -> 6 -> 7

//
// int whatDoesItDo (node* head)
// {
//    struct node * current = head;
//    struct node * other, *temp;
//
//    if (current == NULL)
//     return head;
//
//     other = current->next;
//
//   if (other == NULL)
//     return head;
//
//   other = other->next;
//   temp = current->next;
//
//   current->next = other->next;
//   current = other->next;
//
//   if (current == NULL)
//   {
//     head->next = temp;
//     return head;
//   }
//
//   other->next = current->next;
//   current->next = temp;
//
//   return head;
// }
