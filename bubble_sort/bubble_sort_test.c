//
// Created by mac on 13.11.2025.
//
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"
#include "bubble_sort.h"

void bubble_sort_test()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int sorted_arr[] = {11, 12, 22, 25, 34, 64, 90};
    bubble_sort_test(arr, (size_t)(sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]));
    assert(arr == sorted_arr);


    double arr_d[] = {3.14, 2.71, 1.41, 0.57, 9.99};
    double sorted_arr_d[] = {0.57, 1.41, 2.71, 3.14, 9.99};
    bubble_sort_test(arr_d, (size_t)(sizeof(arr_d) / sizeof(arr_d[0]), sizeof(arr_d[0]));
    assert(arr_d == sorted_arr_d);

    char arr_c[] = {'a', 't', 'n', 'e', 'y'};
    char sorted_arr_c[] = {'a', 'e', 'n', 't', 'y'};
    bubble_sort_test(arr_c, (size_t)(sizeof(arr_c) / sizeof(arr_c[0]), sizeof(arr_c[0]));
    assert(arr_c == sorted_arr_c);

    return 0;
};