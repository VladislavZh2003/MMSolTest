#include <stdio.h>
int main()
{
    // a = 5(00000101), b = 9(00001001)
    unsigned char a = 5, b = 9;
    // The result is 00000001
    printf("a = %d, b = %d\n", a, b);
    printf("a&b = %d\n", a & b); // AND

    // The result is 00001101
    printf("a|b = %d\n", a & b); // OR

    // The result is 00001100
    printf("a^b = %d\n", a ^ b); // XOR

    // The result is 11111010
    printf("~a = %d\n", a = ~a); // NOT

    // The result is
    printf("~b = %d\n", b = ~b); // NOT

    // The result is 00010010
    printf("b<<1 = %d\n", b << 1); // LEFT SHIFT

    // The result is 00000100
    printf("b>>1 = %d\n", b >> 1); // RIGHT SHIFT

    return 0;
}