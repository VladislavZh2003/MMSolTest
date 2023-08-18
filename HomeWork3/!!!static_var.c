#include <stdio.h>

void countCalls()
{
    static int counter = 0;
    counter++;
    printf("Function called %d times\n", counter);
}

int main()
{
    countCalls(); // Function called 1 times
    countCalls(); // Function called 2 times
    countCalls(); // Function called 3 times
    return 0;
}