#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern int pop();
extern void push(int);
extern void addHeap(int);
extern int heapDelete();
extern int heapSize();
extern int heapBuild();
extern int printXML();

int main(int argc, char * argv[]) {
  int value;
  char input[100];
  int looper = 1;

  while (1 == looper) {

    if (scanf("%s", input) != 1)
    {
      fprintf(stderr, "Error reading input!\n");
    }
    
    for (int i = 0; input[i]; i++)
    {
      input[i] = tolower(input[i]);
    }

    if (strcmp(input, "build") == 0)
    {
      break;
    }
    
    int val = atoi(input);
    addHeap(val);
  }
  printf("XML Output:\n");

  heapBuild();

  printXML(0);
  
  printf("\nSorted numbers:\n");

  int s = heapSize();

  for (int i = 0; i < s; i++)
  {
    value = heapDelete();
    printf("%d\n", value);
    push(value);
  }
  printf("Popping the stack:\n");
  for (int i = 0; i < s; i++)
  {
    printf("%d\n", pop());
  }
  exit(0);
}