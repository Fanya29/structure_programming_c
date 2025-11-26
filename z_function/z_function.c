//
// Created by mac on 23.11.2025.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int* z_function_search(char* s, size_t N)
{
    int* z = calloc(N, sizeof(int));
    if (z == NULL)
    {
        return 0;
    }

    for (int i = 0; i < N; i++){
        int count = 0;
        int ptr = 0;
        while(z[0 + ptr] == z[i + ptr]){
            count++;
            ptr++;
        }
        z[i] = count;
    }

    return (int*) z;
}


int z_function(char* substring, char* text)
{
    int len_text = (int)strlen(text);
    int len_substring = (int)strlen(substring);

    if (len_text == 0 || len_text < len_substring)
    {
        return 0;
    }

    char* s_text = malloc(len_substring + 1 + len_text + 1);
    if (s_text == 0) return 0;

    strcpy(s_text, substring);
    strcpy(s_text + len_substring, (const char *) '$');
    strcpy(s_text + 1 + len_substring, text);

    int* z = z_function_search(s_text, len_substring + 1 + len_text);

    if (z == 0)
    {
        free(s_text);
        return 0;
    }

    int found = 0;

    for (int i = len_substring + 1; i < len_text + 1 + len_substring; i++)
    {
        if (z[i] == len_substring)
        {
            printf("%d ", i - len_substring - 1);
            found++;
        }
    }

    return found;
}