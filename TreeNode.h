#ifndef TreeNode_included
#define TreeNode_included

/* The Tree node with left and write children inluding the first and last name */
typedef struct TreeNode {
  char *name;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

/* Creating the root to the tree */
TreeNode *Tree();

/* Creating a Node */
TreeNode *createNode(char *name);

/* Adding a new employee to the tree */
void insert(TreeNode *tp, char *name);

/* Removing an emloyee from the tree */
void remove(TreeNode *tp);

/* Printing the tree inorder */
void print(TreeNode *tp);

/* comparing two names to each other using the method in the book */
int compare(char *name1, char *name2);

#endif /* Included */



