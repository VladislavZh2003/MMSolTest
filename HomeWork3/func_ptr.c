#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*addPtr)(int, int); // Pointer to a function that returns an int and takes two int parameters
    addPtr = add;            // Assigning the address of the function add/без скоби/ to addPtr

    int result = (*addPtr)(3, 5); // Calling the function add using the function pointer

    result = addPtr(3, 5); // Shorthand notation to call the function add using the function pointer

    return 0;
}
