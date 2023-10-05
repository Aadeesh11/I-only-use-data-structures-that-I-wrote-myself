#include "minHeap.h"

void swap(int ar[], int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

void heap_drop(minHeap *h)
{
    if (h->heap != NULL)
        free(h->heap);
    if (h != NULL)
        free(h);
}

minHeap *heap_build(int intialCapacity)
{
    minHeap *heap = (minHeap *)malloc(sizeof(minHeap));
    heap->heap = (int *)malloc(sizeof(int) * intialCapacity);
    heap->capacity = intialCapacity;
    heap->heap_size = 0;
    return heap;
}

void heap_insert(minHeap *h, int key)
{
    if (h->heap_size == h->capacity)
    {
        int *temp = (int *)realloc(h->heap, sizeof(int) * h->capacity * 2);
        if (temp == NULL)
        {
            return;
        }
        h->heap = temp;
        h->capacity *= 2;
    }
    h->heap[h->heap_size] = key;
    int i = h->heap_size;
    h->heap_size++;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (h->heap[parent] <= h->heap[i])
            break;
        swap(h->heap, parent, i);
        i = parent;
    }
}

int *heap_top(minHeap *h)
{
    if (h->heap_size == 0)
    {
        return NULL;
    }
    int *ans = (int *)malloc(sizeof(int));
    *ans = h->heap[0];
    return ans;
}

void heap_pop(minHeap *h)
{
    if (h->heap_size == 0)
    {
        return;
    }
    h->heap[0] = h->heap[h->heap_size - 1];
    h->heap_size--;
    int i = 0;
    while (i < h->heap_size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >= h->heap_size)
        {
            break;
        }
        if (right < h->heap_size)
        {
            if (h->heap[i] < h->heap[left] && h->heap[i] < h->heap[right])
                break;
            if (h->heap[left] <= h->heap[right])
            {
                swap(h->heap, i, left);
                i = left;
            }
            else if (h->heap[left] > h->heap[right])
            {
                swap(h->heap, right, i);
                i = right;
            }
        }
        else
        {
            if (h->heap[i] < h->heap[left])
                break;
            swap(h->heap, i, left);
            i = left;
        }
    }
    // resize heap to save memory
    if (h->heap_size < h->capacity / 2)
    {
        int *newArray = realloc(h->heap, (sizeof(int) * h->capacity) / 2);
        if (newArray == NULL)
        {
            return;
        }
        h->heap = newArray;
        h->capacity /= 2;
    }
}