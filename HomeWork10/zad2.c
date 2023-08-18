#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct double_comp 
{
    unsigned long long mantissa:52;
    unsigned int exponent:11;
    unsigned int sign:1;
} double_comp;

typedef union DOUBLE 
{
    double d;
    double_comp c;
} DOUBLE;

void toBinary(unsigned num)
{
    if (num > 1)
    {
        toBinary(num >> 1);
    }    
 
    printf("%d", num & 1);
}

void printDoubleBinary(DOUBLE dd)
{
    printf("\nNUMBER: %lf\nBINARY:", dd.d);
    toBinary(dd.c.sign);
    printf(".");
    toBinary(dd.c.exponent);
    printf(".");
    toBinary(dd.c.mantissa);
    printf("\n");
}

void printDoubleDecimal(DOUBLE dd)
{
    printf("\nNUMBER: %lf\n", dd.d);
    printf("SIGN: %u\nEXPONENT: %u\nMANTISSA: %llu\n", dd.c.sign, dd.c.exponent, dd.c.mantissa);
}

int main()
{

    DOUBLE dd;
    dd.d = 3.1415; 
    
    printDoubleBinary(dd);
    printDoubleDecimal(dd);
    
    return 0;
}
