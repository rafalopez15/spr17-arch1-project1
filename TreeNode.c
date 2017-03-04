#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

/* Method to create a tree node */
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

/* Removing an employee from the Tree */
TreeNode *removeEmployee(TreeNode *tp, char *s) {
  if (tp == NULL){
    printf("Employee not found.\n");
    return tp;
  }
  if (compare(tp->name, s) > 0)
    tp->left = removeEmployee(tp->left, s);
  else if (compare(tp->name, s) < 0)
    tp->right = removeEmployee(tp->right, s);
  else {
    if (tp->left == NULL){
      TreeNode *temp = tp->right;
      free(tp);
      return temp;
    } else if (tp->right == NULL) {
      TreeNode *temp = tp->left;
      free(tp);
      return temp;
    }
    TreeNode *temp = findMin(tp->right);
    tp->name = temp->name;
    tp->right = removeEmployee(tp->right, temp->name);
    
  }
  return tp;
}

/* Make Tree from a file */
TreeNode *makeTreeFromFile(TreeNode *tp) {
  FILE *file;
  char buffer[25];

  file = fopen("EmployeeNames.txt", "r");
  if (!file) {
    printf("No file found.\n");
    return tp;
  }

  while (fgets(buffer,25, file) != NULL)
    tp = insertEmployee(tp, buffer);

  fclose(file);
  printf("Tree Constructed!\n");
  return tp;
}

/* Find the min val in the tree */
TreeNode *findMin(TreeNode *tp) {
  TreeNode *current = tp;

  while (current->left != NULL)
    current = current->left;

  return current;
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
