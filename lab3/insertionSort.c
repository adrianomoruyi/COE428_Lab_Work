#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
int key, i;
for (int j = 1; j < last + 1; j++) 
    {
        myCopy(&array[j],&key);
        i = j - 1;
        while (i >= 0 && myCompare(array[i],key) > 0) 
        {
                mySwap(&array[i],&array[i+1]);
                i = i - 1;
        }
    }
}
