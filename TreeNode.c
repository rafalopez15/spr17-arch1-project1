#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

/* Method to create root of tree */
TreeNode *Tree() {
  TreeNode *root;
  root = malloc(sizeof(TreeNode));
  root->name = 0;
  root->left = NULL;
  root->right = NULL;
  return root;
}

/* Create node function */
TreeNode *createNode(char *name) {
  TreeNode *node;
  node = malloc(sizeof(TreeNode));
  node->name = name;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/* Adding an employee to the tree */
void insert(TreeNode *tp, char *name) {
  if (tp == NULL) {
    createNode(name);
  } else {
    if (compare(tp->name, name) < 0)
      insert(tp->left, name);
    else if (compare(tp-name, name) > 0)
      insert(tp->right, name);
    else if (compare(tp-name, name) == 0)
      printf("User already exists.");
  }
}

/* Fucntion to compare two strings */
int compare(char *name1, char *name2) {
  for ( ; *name1 == *name2; name1++, name2++)
    if (*s =='\0') return 0;
  return *name1 - *name2;
}
