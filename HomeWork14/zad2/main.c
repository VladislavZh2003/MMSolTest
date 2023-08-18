#include "linked_list.h"
#include "stack.h"

int main()
{
    Stack *s1 = init_stack();

    push((Data){10}, s1);
    print_stack(*s1);

    push((Data){20}, s1);
    print_stack(*s1);

    push((Data){30}, s1);
    print_stack(*s1);


    Data d1;
    pop(&d1, s1);
    print_stack(*s1);

    deinit_stack(s1);

    return 0;
}