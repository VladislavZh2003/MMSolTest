#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

int clearBit(uint32_t mask, size_t index)
{
    return (mask & ~(1 << index));
}

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index)
{
    for (size_t i = 0; i < nitems; i++)
    {
        maskArr[i] = clearBit(maskArr[i], bit_index) ; 
    }
    
    return 0; 
}

int setBit(uint32_t mask, size_t index)
{
    return (mask | (1 << index));
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index)
{
    for (size_t i = 0; i < nitems; i++)
    {
        maskArr[i] = setBit(maskArr[i], bit_index) ; 
    }
    
    return 0; 
}

int checkBit(uint32_t mask, size_t index)
{
    return mask & (1 << index) ? 1 : 0; 
}

int checkBits(uint32_t* maskArr, size_t nitems, size_t bit_index)
{
    int countSets = 0;
    int countZeros = 0;

    for (size_t i = 0; i < nitems; i++)
    {
        if (checkBit(maskArr[i], bit_index) == 1)
        {
            ++countSets;
        }
        else
        {
            ++countZeros; 
        }
    }

    if (countSets == nitems)
    {
        return 1;
    }
    else if (countZeros == nitems)
    {
        return 0; 
    }
    
    return -1; 
}

void printBit(uint32_t mask)
{
    while (mask) 
    {
        printf("%d", mask & 1);
        mask >>= 1;
    }
}

void printBits(uint32_t* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printBit(arr[i]);
        printf("\n");
    }
}

int main() 
{
	uint32_t arr[3] = {41, 42, 43};

    printBits(arr, 3);
    printf("\n");
    printBits(arr, 3);

    printf("\n");
    printf("RES: %d\n",checkBits(arr, 3, 1)); 
    printf("RES: %d\n",checkBits(arr, 3, 2)); 
    printf("RES: %d\n",checkBits(arr, 3, 3)); 

    setBits(arr, 3, 1);
    printf("\n");
    printBits(arr, 3);

    clearBits(arr, 3, 1);
    printf("\n");
    printBits(arr, 3);

	return 0;
}