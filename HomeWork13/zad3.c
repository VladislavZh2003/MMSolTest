#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

#define MAX2(x, y) ((x) > (y) ? (x) : (y))
#define MAX(x, y, z) (MAX2(x, y) > (z) ? MAX2(x, y) : (z))
#define MIN2(x, y) ((x) < (y) ? (x) : (y))
#define MIN(x, y, z) (MIN2(x, y) < (z) ? MIN2(x, y) : (z))
#define SETBIT(mask, bit) (mask |=  (1 << bit))
#define CLEARBIT(mask, bit) (mask &= ~(1 << bit))
#define INVERSEBIT(mask, bit) (mask ^=  (1 << bit))
#define CHECKBIT(mask, bit) (mask & (1 << bit) == 1 ? (1) : (0))

int main()
{
    printf("%d\n", MAX(4, 3, 5));
    printf("%d\n", MIN(4, 3, 5));

    int mask = 11; 
    SETBIT(mask, 2);
    printf("%d\n", mask);
    CLEARBIT(mask, 2);
    printf("%d\n", mask);
    INVERSEBIT(mask, 2);
    printf("%d\n", mask);
    INVERSEBIT(mask, 3);
    printf("%d\n", mask);
    printf("%d\n", CHECKBIT(mask, 3));

    return 0; 
}