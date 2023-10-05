#include "minHeap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *p = malloc(sizeof(char) * 10);
    minHeap *h = heap_build(1);
    do
    {
        scanf("%s", p);
        if (strcmp(p, "exit") == 0)
        {
            break;
        }
        else if (strcmp(p, "add") == 0)
        {
            int toAdd = 0;
            if (scanf("%d", &toAdd) == 0)
            {
                while (getchar() != '\n')
                    continue;
                printf("Invalid input, enter integer\n");
                continue;
            }
            heap_insert(h, toAdd);
        }
        else if (strcmp(p, "top") == 0)
        {
            int *ans = heap_top(h);
            if (ans != NULL)
            {
                printf("%d\n", *ans);
                free(ans);
            }
        }
        else if (strcmp(p, "pop") == 0)
        {
            heap_pop(h);
        }
        else
        {
            printf("%s is Invalid command\n", p);
        }
    } while (1);
    free(p);
    heap_drop(h);
    return 0;
}