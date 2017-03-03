#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

/* Method to create root of tree */
TreeNode *Tree(void) {
  return (TreeNode *)malloc(sizeof(TreeNode));
}

/* Adding an employee to the tree */
TreeNode *insertEmployee(TreeNode *tp, char *s) {
  if (tp == NULL) {
    tp = Tree();
    tp->name = stringCopy(s);
    tp->left = tp->right = NULL;
  } else {
    if (compare(tp->name, s) > 0) {
      //  printf("GOING LEFT\n");
      tp->left = insertEmployee(tp->left, s);
    } else if (compare(tp->name, s) < 0) {
      // printf("GOING RIGHT\n");
      tp->right = insertEmployee(tp->right, s);
    } else
      printf("User already exists.\n");
  }
  return tp;
}

/* Printing the Tree in order */
void printTree(TreeNode *tp) {
  if (tp != NULL) {  
    printTree(tp->left);
    printf("%s\n", tp->name);
    printTree(tp->right);
  }
}

/* Fucntion to compare two strings */
int compare(char *name1, char *name2) {
  for ( ; *name1 == *name2; name1++, name2++)
    if (*name1 =='\0') return 0;
  return *name1 - *name2;
}

/* Function to make a copy of a string */
char *stringCopy(char *s) {
  char *nameCopy;
  int len;
  
  for (len = 0; s[len]; len++)
    ;
  
  nameCopy = (char *)malloc(sizeof(len + 1));
  
  for (len = 0; s[len]; len++)
    nameCopy[len] = s[len];
  
  nameCopy[len] = 0;
  return nameCopy;
}
