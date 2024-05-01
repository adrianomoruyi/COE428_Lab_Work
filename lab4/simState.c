#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*  A E F
    B A D
    C G B
    D F C
    E C B
    F D G
    G G H
    H E A
    Start at B
*/

//1 or 0 command
char nextState(int input, char currentState, char states[8][3])
{
   for (int i = 0; i < 8; i++)
    {
        if (states[i][0] == currentState)
        {
            if (input == 0)
            {
                return states[i][1];
            }
            else if (input == 1)
            {
                return states[i][2];
            }
        }
    }
}

//Change command
void changeState(char input[100], char currentState, char states[8][3])
{

    for (int i = 0; i < 8; i++)
    {
        if (states[i][0] == currentState)
        {
            if (input[2] == '0')
            {
                states[i][1] = input[4];
            }
            else if (input[2] == '1')
            {
                states[i][2] = input[4];
            }
        }
    }
}

//Print command
void printMachine(char states[8][3])
{
    for (int i = 0; i < 8; i++)
    {
           printf("%c: %c %c \n", states[i][0], states[i][1], states[i][2]);
    }
}

//Garbage identify command
void unreachableStates(char states[][3], int numStates, char isGarb[8])
{
    int count = 0, reference = 0, g = 0;        

    //Counting unreachable states
    for (int i = 0; i < 8; i++)
    {
        if (states[i][1] == states[i][2])
        {
            for (int j = 0; j < 8; j++)
            {
                if (j != i)
                {
                    isGarb[j] = states[j][0];
                    count++;
                }
            }
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((states[i][0] == states[j][1]) || (states[i][0] == states[j][2]))
            {
                reference++;
            }
        }

        // If there are no references, mark as unreachable
        if (reference == 0)
        {
            isGarb[g] = states[i][0];
            g++;
            count++;
        }
        reference = 0;
    }

    if (count == 0)
    {
        printf("No Garbage Detected");
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (isGarb[i] >= 'A' && isGarb[i] <= 'H')
            {
                printf("Garbage: %c\n", isGarb[i]);
            }
        }
    }
}

//Delete command
void deleteStates(char states[][3], int numStates, char isGarb[8])
{
    int count = 0;

    for (int i = 0; i < numStates; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (isGarb[i] == states[j][0])
            {
                printf("Deleted: %c\n", states[j][0]);
                states[j][0] = '*';
                states[j][1] = '*';
                states[j][2] = '*';
                count++;
            }
        }
    }

    numStates = numStates - count;

    if (count == 0)
    {
        printf("No garbage.");
    }
}

// Function to delete a specific state based on user input
void manualDelete(char states[][3], int numStates, char stringInput, char isGarb[8])
{
    int count = 0;

    for (int i = 0; i < numStates; i++)
    {
        if (isGarb[i] == stringInput)
        {
            for (int index = 0; index < 8; index++)
            {
                if (isGarb[i] == states[index][0])
                {
                    states[index][0] = '-';
                    states[index][1] = '-';
                    states[index][2] = '-';
                    printf("Deleted: %c\n", stringInput);
                }
            }
            count++;
        }
    }

    numStates = numStates - count;

    if (count == 0)
    {
        printf("Not Deleted.");
    }
}

int main(int argc, char *argv[])
{
    char startState = 'B';
    char currentState = startState;

    char states[8][3] = {
        {'A', 'E', 'F'},
        {'B', 'A', 'D'},
        {'C', 'G', 'B'},
        {'D', 'F', 'C'},
        {'E', 'C', 'B'},
        {'F', 'D', 'G'},
        {'G', 'G', 'H'},
        {'H', 'E', 'A'}};

    char isGarb[8];
    int intInput;
    char stringInput[100];
    int numStates = 8;

    printf("Initial state:  %c \n", startState);

 while (1)
    {
        intInput = 5;
        stringInput[0] = '-';
        stringInput[1] = '-';
        stringInput[2] = '-';
        stringInput[3] = '-';
        stringInput[4] = '-';
        stringInput[5] = '-';
        while (1)
        {
            printf("\nPlease enter a input:");
            fgets(stringInput, 100, stdin);
       
            //Breaking while loop if any of the proper commands are chosen 
            if (stringInput[0] == '1' && strlen(stringInput) == 2)
            {
                intInput = 1;
                break;
            }
            else if (stringInput[0] == '0' && strlen(stringInput) == 2)
            {
                intInput = 0;
                break;
            }
            else if (stringInput[0] == 'c' && (stringInput[2] == '0' || stringInput[2] == '1') && stringInput[4] >= 'A' && stringInput[4] <= 'H')
            {
                break;
            }
            else if (stringInput[0] == 'p' && strlen(stringInput) == 2)
            {
                break;
            }
            else if (stringInput[0] == 'd' && (strlen(stringInput) == 2 || strlen(stringInput) == 4))
            {
                break;
            }
            else if (stringInput[0] == 'g' && strlen(stringInput) == 2)
            {
                break;
            }
            else if (stringInput[0] == 'e' && stringInput[1] == 'n' && stringInput[2] == 'd')
            {
                printf("simState has ended\n");
                exit(0);
            }
            else
            {
                printf("\nInvalid input, please try again\n");
            }
        }
        
        if (intInput == 1)
        {
            currentState = nextState(1, currentState, states);
            printf("current state is: < %c >\n", currentState);
        }
        else if (intInput == 0)
        {
           currentState = nextState(0, currentState, states);
           printf("current state is: < %c >\n", currentState);
        }
        else if (stringInput[0] == 'c')
        {
            changeState(stringInput, currentState, states);
        }
        else if (stringInput[0] == 'p')
        {
            printMachine(states);
        }
        else if (stringInput[0] == 'd')
        {
            if (strlen(stringInput) == 2)
            {
                deleteStates(states, numStates, isGarb);
            }
            else if (strlen(stringInput) == 4)
            {
                manualDelete(states, numStates, stringInput[2], isGarb);
                numStates--;
            }
        }
        else if (stringInput[0] == 'g')
        {
            unreachableStates(states, numStates, isGarb);
        }
    }
    
    exit(0);
}
