#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define TINT 1
#define TDOUBLE 2
#define TCHAR 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void *valuePtr, uint8_t flag);

int main()
{
    int var1 = 23;
    double var2 = 4.67;
    char var3 = 'A';
    float var4 = 35.678;
    uint8_t var5 = 56;
    uint16_t var6 = 4;
    uint32_t var7 = 12;
    uint64_t var8 = 678;

    printValue(&var1, TINT);
    printValue(&var2, TDOUBLE);
    printValue(&var3, TCHAR);
    printValue(&var4, TFLOAT);
    printValue(&var5, TUINT8_T);
    printValue(&var6, TUINT16_T);
    printValue(&var7, TUINT32_T);
    printValue(&var8, TUINT64_T);

    return 0;
}

void printValue(const void *valuePtr, uint8_t flag)
{
    if (flag == 1)
    {
        int *t = (int *)valuePtr;
        printf("%d\n", *t);
    }
    else if (flag == 2)
    {
        double *t = (double *)valuePtr;
        printf("%lf\n", *t);
    }
    else if (flag == 3)
    {
        char *t = (char *)valuePtr;
        printf("%c\n", *t);
    }
    else if (flag == 4)
    {
        float *t = (float *)valuePtr;
        printf("%f\n", *t);
    }
    else if (flag == 5)
    {
        uint8_t *t = (uint8_t *)valuePtr;
        printf("%d\n", *t);
    }
    else if (flag == 6)
    {
        uint16_t *t = (uint16_t *)valuePtr;
        printf("%d\n", *t);
    }
    else if (flag == 7)
    {
        uint32_t *t = (uint32_t *)valuePtr;
        printf("%d\n", *t);
    }
    else
    {
        uint64_t *t = (uint64_t *)valuePtr;
        printf("%ld\n", *t);
    }
}