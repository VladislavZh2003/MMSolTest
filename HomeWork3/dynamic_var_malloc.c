#include <stdio.h>

void createDynamicArray()
{
    int *arr = malloc(5 * sizeof(int));
    free(arr);
}

int main()
{
    createDynamicArray();
    return 0;
}