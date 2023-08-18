#include <stdio.h>

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int firstNumber = numbers[0];

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += numbers[i];
    }

    int *ptr = numbers;

    int secondNumber = *(ptr + 1);
}