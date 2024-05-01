/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
#include <stdio.h>

static int size = 0;
static int heap[1000];

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify (int i)
{
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < size && heap[left] > heap[largest])
  {
    largest = left;
  }
  if (right < size && heap[right] > heap[largest])
  {
    largest = right;
  }
  if (largest != i)
  {
    swap(&heap[i], &heap[largest]);
    heapify(largest);
  }
}

void printXML (int i)
{
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (i < size)
  {
    printf("<node id=\"%d\">", heap[i]);
    printXML(left);
    printXML(right);
    printf("</node>");
  }
}

void heapBuild()
{
  for (int i = size / 2-1; i >= 0; i--)
  {
    heapify (i);
  }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
  if (size == 0)
  {
    return -1;
  }

  int root = heap[0];
  heap[0] = heap[size-1];
  heap[size-1] = 0;
  size--;
  heapify(0);

  return root;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  heap[size] = thing2add;
  size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  //A dummy return statement
}
