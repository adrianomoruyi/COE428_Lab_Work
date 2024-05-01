#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char *argv[])
{
  int ch;
  int last_ch;
 // char theTop;
  int i = 0;
  int j = 0;
  char temp[100];
  char tag[100]; // stores tags
  while ((ch = getchar()) != '\n')
  {
    if (isdigit(ch))
    {
      fprintf(stderr, "Input should only be characters\n");
      exit(1);
    }
    if (last_ch == '<' && ch != '/')
    {
      i = 0;
      while (isalpha(ch))
      {
        tag[i] = ch;
        i++;
        ch = getchar();
        printf("Got char!\n");
      }

      tag[i] = '\0';
      if (ch != '>')
      {
        fprintf(stderr, "Invalid start tag!\n");
        exit(1);
      }
      push(strdup(tag));
     
      printf("Pushed!\n");
      j++;
    }

    // Exits program if the closing identifier is not found.
    if (ch == EOF)
    {
      fprintf(stderr, "Cannot find closing identifier.\n");
      exit(1);
    }
    // If the closing tag is found
    if (last_ch == '<' && ch == '/')
    {
      //i = 0;
      i++;
      ch = getchar();
      while (isalpha(ch))
      {
        tag[i] = ch;
        //printf("Tag: %c\n", tag[i]);
        i++;
        ch = getchar();
        printf("Got char!\n");
      }

      tag[i] = '\0';
       temp[j] = tag[i];
      if (ch != '>')
      {
        fprintf(stderr, "Invalid end tag!\n");
        exit(1);
      }
      
      if (isEmpty())
      {
        fprintf(stderr, "The stack is empty!");
        exit(1);
      }

      char theTop = *pop();
      //theTop = pop();
      printf("Popped!\n");
      printf("Top of stack: %c\n", theTop);
      printf("Tag: %c\n", tag[i - 1]);

      if (theTop != tag[i - 1])
      {
        fprintf(stderr, "Top of the stack and the popped tag are not the same!");
        printf("Top of stack: %c\n", theTop);
        printf("Tag: %c\n", tag[i - 1]);
        exit(1);
      }
      j--;
      
    }
    last_ch = ch;
  }

  if (isEmpty())
  {
    printf("It is valid!\n");
    exit(0);
  }
  
  else
  {
    printf("It is invalid!");
    exit(1);
  }
}
