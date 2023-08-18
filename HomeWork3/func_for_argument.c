#include <stdio.h>

void process(int data, int (*callback)(int))
{
    int result = callback(data);
    printf("Result: %d\n", result);
}
int doubleNumber(int num)
{
    return num * 2;
}
int main()
{
    process(5, doubleNumber); // Calling process and passing doubleNumber as a callback
    return 0;
}
