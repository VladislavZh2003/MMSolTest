#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sum_commandLine_num(char *arr[], int size);

int main(int argc, char *argv[])
{
    double sum = sum_commandLine_num(argv, argc);

    printf("sum = %lf\n", sum);

    return 0;
}

double sum_commandLine_num(char *arr[], int size)
{
    double sum = 0;

    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < strlen(arr[i]); j++)
        {
            if (arr[i][j] == '.')
            {
                sum += atof(arr[i]);
                break;
            }
            else if(arr[i][0] == '0')
            {
                sum += (int)strtol(arr[i], NULL, 16);
                break;
            }
            else if (j == strlen(arr[i]) - 1)
            {
                sum += atoi(arr[i]);
                break;
            }
        }
    }

    return sum;
}