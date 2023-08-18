#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


void swapBytes(uint16_t* word)
{
    uint16_t leftmostByte = (*word & 0x00FF) >> 0;
    uint16_t rightmostByte = (*word & 0xFF00) >> 8;
    leftmostByte <<= 8; 

    *word = leftmostByte | rightmostByte; 
}

int main()
{
    uint16_t word = 0xCAFE;
    swapBytes(&word);
    printf("CAFE: %02x\n", word);

    return 0;
}
