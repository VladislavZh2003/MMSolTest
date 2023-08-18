#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

char* convert(int number)
{
    int copy = number;
    int count = 0;
    char arr2[100] ;
    int i;
    int index = 0;

    while (copy) 
    {
        count++;
        copy /= 10;
    }

    char* arr = (char*)malloc(count);
 
    while (number > 0) 
    {
        arr2[index++] = number % 10 + '0';
        number /= 10;
    }

    for (i = 0; i < count; i++) 
    {
        arr[i] = arr2[index - i - 1];
    }
 
    arr[i] = '\0';

    return arr;
}

int prInt(int num)
{
    if (num == 0)
    {
        putc('0', stdout);
        return 1;
    }

    int count = 0;

    if (num < 0)
    {
        putc('-', stdout);
        count++;
        num = -num;
    }

    char* buffer = convert(num);

    while (*buffer)
    {
        putc(*buffer, stdout);
        count++;
        *buffer++; 
    }
    
    return count; 
}

int my_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int countPrinted = 0;
    int num = 0; double numDouble = 0; char c; 

    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;

            switch (*fmt)
            {
            case 'c':
                c = (char)va_arg(args, int);
                putc(c, stdout);
                countPrinted += 1;
                break;
            case 'd':
                num = va_arg(args, int);
                countPrinted += prInt(num);
                break;
            default:
                putc(*fmt, stdout);
                countPrinted += 1;
                break;
            }
        }
        else
        {
            putc(*fmt, stdout);
            countPrinted += 1; 
        }

        fmt++;
    }

    va_end(args);
    return countPrinted;
}

int main()
{
    int n1 = my_printf("fjdsifhdsdihsf\n");
    printf("%d\n",n1);
    int n2 = my_printf("%d\n", 345);
    printf("%d\n",n2);
    int n3 = my_printf("%c\n", 91);
    printf("%d\n",n3);
    
    return 0; 
}