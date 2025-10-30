#include <stdio.h>
#include <assert.h>
#include <string.h>

void bubble_sort(int* arr, int N)
{
    int c = NULL;


     for (int i = 0; i < N; i++)
     {
         for (int j = 0; j < i; j++)
         {
             if (*(arr + i) < *(arr + j))
             {
                 c = *(arr + i);
                 *(arr + i) = *(arr+j);
                 *(arr + j) = c;
             }
         }
     }
}

int main()
{
    int arr[] = {10, 5, 6, 3, 2, 9, 11};
    bubble_sort(arr, (sizeof(arr)/ sizeof(int)));

    printf("%d \n", arr);
    return 0;
}