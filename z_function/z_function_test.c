//
// Created by mac on 23.11.2025.
//
#include <assert.h>
#include "z_function.h"

void z_function_test()
{
    const char* text1 =  "ababcabacbaababa";
    const char* substring1 = "aba";
    assert(z_function(substring1, text1) == 4);

    const char* text2 = "";
    const char* substring2 = "aba";
    assert(z_function(substring2, text2) == 0);

    const char* text3 = "ab";
    const char* substring3 = "";
    assert(z_function(substring3, text3) == 1);

    const char* text4 = "aaaaaaa";
    const char* substring4 = "a";
    assert(z_function(substring4, text4) == 7);
}