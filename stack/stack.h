//
// Created by mac on 03.12.2025.
//

#ifndef STRUCTURE_PROGRAMMING_C_STACK_H
#define STRUCTURE_PROGRAMMING_C_STACK_H

#include <stdlib.h>
typedef void* Pointer;

typedef struct {
    void ** arr;
    size_t buffer;
    size_t size;
} Stack;

void stack_create(Stack *s);

void stack_destroy(Stack *s);

size_t stack_size(Stack *s);

void stack_push(Stack *s, void *elem);

Pointer stack_pop(Stack *s);

Pointer stack_peek(Stack *s);

#endif //STRUCTURE_PROGRAMMING_C_STACK_H
