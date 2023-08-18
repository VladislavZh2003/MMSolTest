#include <stdio.h>

void square(int *numPtr)
{
    *numPtr = (*numPtr) * (*numPtr);
}

int main()
{
    int num = 5;
    square(&num);
    printf("%d", num);

    return 0;
}