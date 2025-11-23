//
// Created by mac on 13.11.2025.
//
#include "string.h"
#include "stdlib.h"
#include <assert.h>


void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    assert(temp != NULL);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void quick_sort_partition(void* arr, int low, int high, size_t size, int (*compare)(const void*, const void*))
{
    if (low >= high) return;

    char* base = (char*) arr;
    void* pivot = base + high * size;
    int wall = low;

    for (int i = low; i < high; i++)
    {
        void* current = base + i * size;
        if (compare(pivot, current))
        {
            swap(current, base + wall * size, size);
            wall++;
        }
    }

    swap(pivot, base + wall * size, size);

    quick_sort_partition(arr, low, wall - 1, size, compare);
    quick_sort_partition(arr, wall + 1, high, size, compare);

}


void quick_sort(void *arr, size_t N, size_t size, int (compare)(const void*, const void*))
{
    if (N < 1) return;

    quick_sort_partition(arr, 0, N - 1, size, compare);
}