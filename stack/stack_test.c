//
// Created by mac on 03.12.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

static int* stack_elem(int value)
{
    int* p = malloc(sizeof(int));
    *p = value;
    return p;
}

void test_create_destroy() {
    Stack s;
    stack_create(&s);
    assert(stack_size(&s) == 0);
    stack_destroy(&s);
    assert(s.arr == NULL);
}

void test_push_size() {
    Stack s;
    stack_create(&s);

    int* a = stack_elem(10);
    int* b = stack_elem(20);

    assert(stack_size(&s) == 0);
    stack_push(&s, a);
    assert(stack_size(&s) == 1);
    stack_push(&s, b);
    assert(stack_size(&s) == 2);

    stack_destroy(&s);
}

void test_pop() {
    Stack s;
    stack_create(&s);

    int* a = stack_elem(10);
    int* b = stack_elem(20);
    stack_push(&s, a);
    stack_push(&s, b);

    assert(stack_size(&s) == 2);

    int *popped = (int*)stack_pop(&s);
    assert(*popped == 20);
    assert(stack_size(&s) == 1);
    free(popped);

    popped = (int*)stack_pop(&s);
    assert(*popped == 10);
    assert(stack_size(&s) == 0);
    free(popped);
    stack_destroy(&s);
}

void test_peek() {
    Stack s;
    stack_create(&s);

    int* a = stack_elem(99);
    int* b = stack_elem(88);

    stack_push(&s, a);
    stack_push(&s, b);

    int *top = (int*)stack_peek(&s);
    assert(*top == 88);
    assert(stack_size(&s) == 2);

    stack_destroy(&s);
}


void test_growth() {
    Stack s;
    stack_create(&s);

    const int N = 20;
    for (int i = 0; i < N; i++) {
        stack_push(&s, stack_elem(i));
    }
    assert(stack_size(&s) == N);

    for (int i = N - 1; i >= 0; i--) {
        int *val = (int*) stack_pop(&s);
        assert(*val == i);
        free(val);
    }
    assert(stack_size(&s) == 0);
    stack_destroy(&s);
}