//
// Created by mac on 13.11.2025.
//

#ifndef STRUCTURE_PROGRAMMING_C_QUICK_SORT_H
#define STRUCTURE_PROGRAMMING_C_QUICK_SORT_H

#include "stddef.h"

void quick_sort(void* arr, size_t N, size_t size, int (*compare)(const void *, const void *));
void quick_sort_test();

#endif //STRUCTURE_PROGRAMMING_C_QUICK_SORT_H
