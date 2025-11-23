//
// Created by mac on 13.11.2025.
//
#include "quick_sort.h"
#include <string.h>
#include <assert.h>

typedef struct {
    int x;
} Structs;


int int_compare(const void *a,const void *b){
    int *el1 = (int *) a;
    int *el2 = (int *) b;
    if (*el1 > *el2){
        return 1;
    } else {
        return 0;
    }
}

int double_compare(const void *a,const void *b){
    double *el1 = (double *) a;
    double *el2 = (double *) b;
    if (*el1 > *el2){
        return 1;
    } else {
        return 0;
    }
}

int char_compare(const void *a,const void *b){
    char *el1 = (char *) a;
    char *el2 = (char *) b;
    if (*el1 > *el2){
        return 1;
    } else {
        return 0;
    }
}

int struct_compare(const void *a,const void *b){
    Structs *el1 = (Structs *) a;
    Structs *el2 = (Structs *) b;
    if (el1->x > el2->x){
        return 1;
    } else {
        return 0;
    }
}


void quick_sort_test()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int sorted_arr[] = {11, 12, 22, 25, 34, 64, 90};
    quick_sort(arr, (sizeof(arr) / sizeof(arr[0])), sizeof(arr[0]), int_compare);
    assert(memcmp(arr, sorted_arr, sizeof(arr[0])) == 0);

    double arr_d[] = {3.14, 2.71, 1.41, 0.57, 9.99};
    double sorted_arr_d[] = {0.57, 1.41, 2.71, 3.14, 9.99};
    quick_sort(arr_d, (sizeof(arr_d) / sizeof(arr_d[0])), sizeof(arr_d[0]), double_compare);
    assert(memcmp(arr_d, sorted_arr_d, sizeof(arr_d[0])) == 0);

    char arr_c[] = {'a', 't', 'n', 'e', 'y'};
    char sorted_arr_c[] = {'a', 'e', 'n', 't', 'y'};
    quick_sort(arr_c, (sizeof(arr_c) / sizeof(arr_c[0])), sizeof(arr_c[0]), char_compare);
    assert(memcmp(arr_c, sorted_arr_c, sizeof(arr_c[0])) == 0);

    Structs arr_s[5] = {{5}, {2}, {9}, {1}, {6}};
    Structs sorted_arr_s[5] = {{1}, {2}, {5}, {6}, {9}};
    quick_sort(arr_s, (sizeof(arr_s) / sizeof(arr_s[0])), sizeof(arr_s[0]), struct_compare);
    assert(memcmp(arr_s, sorted_arr_s, sizeof(arr_s[0])) == 0);
};
