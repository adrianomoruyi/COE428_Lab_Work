#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    if (argc == 3 || argc > 4) {
        fprintf(stderr, "Error! Only 1 argument or 3 arguments are allowed!");
        exit(1);
    }

    if (argc <= 0) {
        fprintf(stderr, "Error! Must be greater than 0");
        exit(1);
    }

   if (argc == 4) {
    if ((atoi(argv[3]) > 3 || atoi(argv[3]) < 1) || (atoi(argv[2]) > 3 || atoi(argv[2]) < 1)) {
        fprintf(stderr, "Error! Towers of Hanoi must have 3 towers!");
        exit(1);
    }
        from = atoi(argv[2]);
        dest = atoi(argv[3]);
    }
    
    towers(n, from, dest);
    exit(0);
}

