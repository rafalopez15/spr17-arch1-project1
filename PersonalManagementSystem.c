#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeNode.h"

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

int main() {
  //  printf("Main\n");
  char buff[25];
  struct TreeNode *root;

  /*
  insertEmployee(root, "Rafa");
  insertEmployee(root, "Kevin");
  insertEmployee(root, "Marco");
  */

  root = NULL;
  while (gets_n(buff, 25)) {
    printf("Inserting: %s\n", buff);
    root = insertEmployee(root, buff);
  }
  
  printTree(root);

  return 0;
}


