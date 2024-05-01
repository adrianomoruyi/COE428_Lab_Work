#include "mySort.h"

void merge (int array[], unsigned int first, unsigned int mid, unsigned int last)
    {
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 = last - mid;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        myCopy(&array[first + i],&L[i]);
    for (j = 0; j < n2; j++)
        myCopy(&array[mid + 1 + j],&R[j]);
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = first;
    while (i < n1 && j < n2) {
        if (myCompare(L[i],R[j]) <= 0) {
            myCopy(&L[i],&array[k]);
            i++;
        }
        else {
            myCopy(&R[j],&array[k]);
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        myCopy(&L[i],&array[k]);
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        myCopy(&R[j],&array[k]);
        j++;
        k++;
    }
    }

void mySort(int array[], unsigned int first, unsigned int last)
    {
        if (first < last)
        {
            int mid = ((first+last)/2);
            mySort(array, first, mid);
            mySort(array, mid + 1, last);
            merge(array, first, mid, last);
        }
    }


