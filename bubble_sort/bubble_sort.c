//
// Created by mac on 13.11.2025.
//

#include "assert.h"
#include <string.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t size)
{
    void *temp = malloc(size);

    assert(temp);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void bubble_sort(void* arr, size_t N, size_t size, int (compare)(const void *,const void *))
{
    char *base = (char*)arr;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            void *elem1 = base + j * size;
            void *elem2 = base + (j + 1) * size;
            if (compare(elem1, elem2) == 1)
            {
                swap(elem1, elem2, size);
            }
        }
    }
}