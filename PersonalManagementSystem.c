#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeNode.h"

void userInterface();
/*
int gets_n(char *s, int buff) {
  char *p = s;
  char c;

  if (fgets(s, buff, stdin)) {
    while ((c = *p) && c != '\n')
      p++;
    if (c =='\n')
      *p = 0;
  }
  return (p - s);
}
*/
int main() {
  char buff[25];
  struct TreeNode *root;
  
  root = NULL;

  int options = 0;
  do {
    userInterface();
    
    scanf("%d", &options);
    
    switch(options) {
    case 1:
      printf("Enter the employee name\n");
      scanf(" %s", buff);
      printf("Inserting: %s\n", buff);
      root = insertEmployee(root, buff);
      break;
      
    case 2:
      printf("Enter employee to delete\n");
      scanf(" %s", buff);
      root = removeEmployee(root, buff);
      break;
      
    case 3:
      printf("Printing tree: \n");
      printTree(root);
      break;

    case 4:
      printf("Making Tree...\n");
      root = makeTreeFromFile(root);
      break;
      
    default:
      break;
    }
  } while (options != 5);
  /*
  while (gets_n(buff, 25)) {
    printf("Inserting: %s\n", buff);
    root = insertEmployee(root, buff);
  }

  insertEmployee(root, "Jose");
  insertEmployee(root, "Omar");
  insertEmployee(root, "Joey");

  root = removeEmployee(root, "Michael");

  printf("Printing Tree in order\n");
  printTree(root);
  */
  
  return 0;
}

void userInterface() {
  printf("\tPERSONNEL MANAGEMENT SYSTEM\n");
  printf("1 - Add an employee\n");
  printf("2 - Remove an employee\n");
  printf("3 - List all employees\n");
  printf("4 - Make Tree from text file..\n");
  printf("5 - Exit\n");
}
