#include <stdio.h>

// Binary Search Trees

struct tree_node
{
  int data;
  struct tree_node *left;
  struct tree_node *right;

}

// Prototypes
struct tree_node* create_node(int val);
struct tree_node* insertNode(struct tree_node *root, struct tree_node* element);
struct tree_node* bstSearch(struct tree_node *root, int val);
tree_node *deleteWholeTree(tree_node *root);

int main()
{


  return 0;
}

struct tree_node* create_node(int val)
{
  // Allocate space for the node
  struct tree_node *newNode = (struct tree_node*)malloc(sizeof(struct tree_node));


  // Initialize the fields
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;

  // Return the pointer to created node
  return newNode;
}

struct tree_node* bstSearch(struct tree_node *root, int val)
{
    // if tree is empty or value was found in the tree
   if (root == NULL || root->data == val)
    return root;

  // If value is less than root, traverse left
  if (root->data > val)
    return bstSearch(root->left,val);54

  // If value is greater than root, traverse right
  else
    return bstSerach(root->right, val);
}


struct tree_node* insertNode(struct tree_node *root, struct tree_node* element)
{

  // Inserting into an empty tree
  if (root == NULL)
    return element;

  // (Right Node) If new value is greate than root
  if (element->data > root->data)
  {
    // if there's a right node recurse down the tree
    if (root->right != NULL)
      root->right = insert(root->right, element);

    // root->right == NULL  no right child
    else
      root->right = element;

  }

  // (Left Node) if new value is less than root
  else
    {
      // if there's a left node recurse down the tree
      if(root->left != NULL)
        root->left =  insert(root->left,element);

      // root->left == NULL no left child
      else
        root->left = element;
    }
    // return root pointer of the updated tree
    return root;
}

tree_node *deleteWholeTree(tree_node *root)
{
  if (root == NULL)
    return NULL;

    //
    while(root-> != NULL)
    {
      listNode * temp = root->head;
      root->head = root->head->next;
      free(temp);
    }

    // Freeing both children
    root->right = deleteTreeList(root->right);
    root->left = deleteTreeList(root->left);

    // Free tree root last
    free(root);

    return NULL;

}

void printPreOrder(tree_node *root)
{
  // PreOrder: node - left - right

  if (root == NULL)
    return;

  // Node
  printf("%d \n", root->value);

  // Left
  printPreOrder(root->left);

  //Right
  printPreOrder(root->right);

}

void printInOrder(tree_node *root)
{
  // InOrder : left - node - right

  if (root == NULL)
    return;

  // Left
   printInOrder(root->left);

   // Node
   printf("%d \n", root->data);

  // Right
  printInOrder(root->right);
}

void printPostOrder(tree_node *root)
{
  // Post-Order : left - right - node

  if (root == NULL)
    return;

  // Left
  printPostOrder(root->left);

  // Right
  printPostOrder(root->right);

  // Node
  printf("%d \n", root->data)

}


void *deleteWholeTree(tree_node *root)
{
  if (root == NULL)
    return NULL;



    // Freeing both children
     deleteWholeTree(root->left);
     deleteWholeTree(root->right);


    // Free tree root last
    free(root);

    return root;

}
