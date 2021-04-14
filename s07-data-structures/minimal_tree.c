// Minimal binary tree example
// adapted from geeksforgeeks.org

#include <stdlib.h>

// main data structure
struct node 
{
    //payload
    int data;
    // branching factore of 2 max
    struct node *left;
    struct node *right;
};
 
// allocates a new node 
struct node* newNode(int data)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
  if(node == NULL) { /* ... */ }
 
  // Assign data to this node
  node->data = data;
 
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
 
int main()
{
  // create root
  struct node *root = newNode(1); 

  // create 3 additional nodes 
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);

  // delete tree, free memory {...}
  return 0;
}