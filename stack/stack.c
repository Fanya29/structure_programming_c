//
// Created by mac on 04.12.2025.
//
#include "stack.h"
#include <stdlib.h>
#include <assert.h>

void stack_create(Stack *s) {
    assert(s != NULL);
    s->buffer = 10;
    s->size = 0;
    s->arr = malloc(s-> buffer * sizeof(void*));
    assert(s->arr != NULL);
}

void stack_destroy(Stack *s) {
    assert(s != NULL);
    free(s->arr);
    s->arr = NULL;
    s->buffer = 0;
    s->size = 0;
}

size_t stack_size(Stack *s) {
    assert(s != NULL);
    return s->size;
}

static void stack_resize(Stack *s) {
    if (s->size * 2 > s->buffer)
    {
        s->buffer = s->buffer * 2;
    } else if (s->size * 2 < s->buffer && s->buffer > 10) {
        s->buffer = s->buffer / 2;
    }
    void **new_arr = realloc(s->arr, s->buffer * sizeof(void*));
    assert(new_arr != NULL);
    s->arr = new_arr;
}

void stack_push(Stack *s, void* elem) {
    assert(s != NULL);
    if (s->size * 2 > s->buffer)
    {
        stack_resize(s);
    }
    s->arr[s->size] = elem;
    s->size++;
}

Pointer stack_pop(Stack *s) {
    assert(s != NULL);
    assert(s->size > 0);
    s->size--;
    if (s->size * 2 <= s->buffer)
    {
        stack_resize(s);
    }
    return s->arr[s->size];
}

Pointer stack_peek(Stack *s) {
    assert(s != NULL);
    assert(s->size > 0);
    return s->arr[s->size - 1];
}