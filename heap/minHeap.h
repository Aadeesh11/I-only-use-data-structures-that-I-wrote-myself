#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdlib.h>

typedef struct minHeap
{
    int *heap;
    int capacity;
    int heap_size;
} minHeap;

// Path: minHeap.c
minHeap *heap_build(int initialCapacity);
void heap_insert(minHeap *h, int key);
int *heap_top(minHeap *h);
void heap_pop(minHeap *h);
void heap_drop(minHeap *h);

#endif
