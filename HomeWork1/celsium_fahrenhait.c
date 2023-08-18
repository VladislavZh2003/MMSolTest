#include <stdio.h>

int main()
{
    double fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2lf°F is equal to %.2lf°C\n", fahrenheit, celsius);
    return 0;
}