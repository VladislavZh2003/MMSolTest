#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    LL *ll = init_linked_list();

    push_back((Data){1}, ll);
    print_linked_list(ll);

    push_back((Data){2}, ll);
    print_linked_list(ll);

    push_back((Data){3}, ll);
    print_linked_list(ll);

    Data d;
    pop_back(ll, &d);
    print_linked_list(ll);

    pop_front(ll, NULL);
    print_linked_list(ll);

    pop_front(ll, NULL);
    print_linked_list(ll);

    push_front((Data){6}, ll);
    print_linked_list(ll);

    //deinit_linked_list(ll);

    return 0;
}