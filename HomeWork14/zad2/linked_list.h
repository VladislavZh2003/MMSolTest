#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Data
{
    int val;
}Data;

typedef struct Node
{
    Data d;
    struct Node *next;
} Node;

typedef struct LL
{
    Node *head;
    Node *tail;
} LL;

LL* init_linked_list();
void print_linked_list(LL *ll);
void push_back(Data new_data, LL *ll);
void push_front(Data new_data,  LL *ll);
void pop_back( LL *ll, Data *result);
void pop_front( LL *ll, Data *result);
//void insert_after();
void deinit_linked_list(LL *ll);

#endif