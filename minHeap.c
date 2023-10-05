#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int ar[], int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

void getFromHeap(int ar[], int *n, int *cur, int **ans, bool pop)
{
    if ((*cur) == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    (*ans) = (int *)malloc(sizeof(int));
    **ans = ar[0];
    if (!pop)
        return;
    ar[0] = ar[(*cur) - 1];
    (*cur)--;
    int i = 0;
    while (i < (*cur))
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >= (*cur))
        {
            break;
        }
        if (right < (*cur))
        {
            if (ar[i] < ar[left] && ar[i] < ar[right])
                break;
            if (ar[left] <= ar[right])
            {
                swap(ar, i, left);
                i = left;
            }
            else if (ar[left] > ar[right])
            {
                swap(ar, right, i);
                i = right;
            }
        }
        else
        {
            if (ar[i] < ar[left])
                break;
            swap(ar, i, left);
            i = left;
        }
    }
    // resize heap
    if ((*cur) < (*n) / 2)
    {
        int *newArray = realloc(ar, (sizeof(int) * (*n)) / 2);
        if (newArray == NULL)
        {
            printf("Weird shouldnt have occured!\n");
            return;
        }
        ar = newArray;
        (*n) /= 2;
    }
}

void addToHeap(int **ar, int *n, int *cur)
{
    int toAdd;
    if (0 == scanf("%d", &toAdd))
        return;
    if ((*cur) == (*n)) // heap is full
    {

        int *newArray = realloc((*ar), sizeof(int) * (*n) * 2);
        if (newArray == NULL)
        {
            printf("Maximum heap size reached!\n");
            return;
        }
        (*ar) = newArray;
        (*n) *= 2;
    }
    (*ar)[(*cur)] = toAdd;
    int i = (*cur);
    (*cur)++;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if ((*ar)[i] >= (*ar)[parent])
            break;

        swap((*ar), i, parent);

        i = parent;
    }
}

int main(void)
{
    int n = 1;
    int cur = 0;
    int *ar = malloc(sizeof(int) * n);
    char *p = malloc(sizeof(char) * 10);
    do
    {
        scanf("%s", p);
        if (strcmp(p, "exit") == 0)
        {
            break;
        }
        else if (strcmp(p, "add") == 0)
        {
            addToHeap(&ar, &n, &cur);
        }
        else if (strcmp(p, "top") == 0)
        {
            int *ans = NULL;
            getFromHeap(ar, &n, &cur, &ans, false);
            if (ans != NULL)
            {
                printf("%d\n", *ans);
                free(ans);
            }
        }
        else if (strcmp(p, "pop") == 0)
        {
            int *ans = NULL;
            getFromHeap(ar, &n, &cur, &ans, true);
            if (ans != NULL)
            {
                free(ans);
            }
        }
        else
        {
            printf("%s is Invalid command\n", p);
        }
    } while (1);
    free(p);
    free(ar);
    return 0;
}