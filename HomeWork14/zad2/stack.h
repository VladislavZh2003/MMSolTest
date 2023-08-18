#include "linked_list.h"

#ifndef STACK_H
#define STACK_H 1

typedef LL Stack;

Stack* init_stack()
{
    return init_linked_list();
}

void push(Data new_elem, Stack *s)
{
    push_front(new_elem, s);
}

void pop(Data *result, Stack *s)
{
    pop_front(s, result);
}

void print_stack(Stack s)
{
    print_linked_list(&s);
}

void deinit_stack(Stack *s)
{
    deinit_linked_list(s);
}

#endif
