//
// Created by mac on 13.11.2025.
//

#include <string.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t size)
{
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void bubble_sort(void* arr, size_t N, size_t size)
{
    char *base = (char*)arr;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            void *elem1 = base + j * size;
            void *elem2 = base + (j + 1) * size;
            if (elem1 < elem2)
            {
                swap(elem1, elem2, size);
            }
        }
    }
}