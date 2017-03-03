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

/* Adding a new employee to the tree */
TreeNode *insertEmployee(TreeNode *tp, char *s);

/* Removing an emloyee from the tree */
void removeEmployee(TreeNode *tp);

/* Printing the tree inorder */
void printTree(TreeNode *tp);

/* comparing two names to each other using the method in the book */
int compare(char *name1, char *name2);

/* Makeing a copy of string */
char *stringCopy(char *s);

#endif /* Included */



