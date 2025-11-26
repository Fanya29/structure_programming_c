//
// Created by mac on 23.11.2025.
//
#include <assert.h>
#include "z_function.h"

int z_function_test()
{
    char text1 = "ababcabacbaababa";
    char substring1 = "aba";
    assert(z_function_test(substring1, text1) == 4);


    char text2 = "";
    char substring2 = "aba";
    assert(z_function_test(substring2, text2) == 0);

    char text3 = "ab";
    char substring3 = "aba";
    assert(z_function_test(substring3, text3) == 0);

    char text4 = "aaaaaaa";
    char substring4 = "a";
    assert(z_function_test(substring4, text4) == 7);
}