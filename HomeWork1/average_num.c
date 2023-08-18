#include <stdio.h>

int main()
{
    double num1, num2, num3, average;
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Enter the third number: ");
    scanf("%lf", &num3);
    average = (num1 + num2 + num3) / 3;
    printf("The average of %lf, %lf and %lf is %lf\n", num1, num2, num3, average);

    return 0;
}