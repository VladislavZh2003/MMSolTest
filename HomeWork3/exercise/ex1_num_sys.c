#include <stdio.h>
#include <math.h>

int main()
{
    int num_in_dec;
    scanf("%d", &num_in_dec);

    char bin_num[20];

    int i = 0;
    while (num_in_dec >= 1)
    {
        bin_num[i] = num_in_dec % 2;
        num_in_dec /= 2;
        i++;
    }
    i--;
    for (; i >= 0; i--)
    {
        printf("%d", bin_num[i]);
    }

    int count_octal = 1;
    int result_oct;
    for (int j = 0; j < sizeof(bin_num) - 1; j++)
    {
        if (count_octal == 3)
        {
            count_octal = 0;
            printf("%d", result_oct);
        }
        result_oct += bin_num[j] + (int)pow(2, count_octal);
        count_octal++;
    }

    return 0;
}