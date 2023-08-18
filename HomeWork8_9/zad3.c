#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

typedef struct Point 
{
    double x;
    double y;
    double z;
} Point;

typedef struct Human 
{
    double weight_kg;
    uint16_t height_cm;
} Human;

typedef union F2
{
    float f;
    int n; 
} F2; 


unsigned countSetBits(F2* a)
{
    unsigned count = 0;
    int num = a->n;

    while (num) 
    {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int cmpFloat(const void* a, const void* b)
{
    return countSetBits((F2*)a) > countSetBits((F2*)b) ? -1 : 1; 
}

int distPoint(Point* a)
{
    return sqrt(a->x*a->x + a->y*a->y + a->z*a->z);
}

int bodyMassIndex(Human* a)
{
    return a->weight_kg / (a->height_cm*a->height_cm);
}

int cmpHuman(const void* a, const void* b)
{
    return bodyMassIndex((Human*)a) > bodyMassIndex((Human*)b) ? -1 : 1; 
}

int cmpPoint(const void* a, const void* b) 
{
    return distPoint((Point*)a) > distPoint((Point*)b) ? -1 : 1; 
}

int cmpInt(const void* a, const void* b) 
{
	return *(int*)a > *(int*)b ? -1 : 1;
}

int cmpUint64(const void* a, const void* b) 
{
	return *(uint64_t*)a > *(uint64_t*)b ? -1 : 1;
}

int cmpChar(const void* a, const void* b)
{
    return *(char*)a > *(char*)b ? -1 : 1;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*))
{
    void* max = arr;

    for (size_t i = 0; i < n; i++)
    {
        if (cmp( ((char*)arr + i * elem_s), max ) < 0)
        {
            max = (char*)arr + i * elem_s;  
        }
    }
    
    return max; 
}

int main() 
{
	int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
	int* max = (int*)findMax(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInt);
	printf("Result INT: %d\n", *max);	// should print 100

    char arr2[] = {'b', 's', 'c', 'a'};
	char* max2 = (char*)findMax(arr2, sizeof(arr2)/sizeof(char), sizeof(char), cmpChar);
    printf("Result CHAR: %c\n", *max2);	

    Point a = {2, 3, 4};
    Point b = {3, 45, 4};
    Point c = {0, 0, 0};
    Point points[] = {a, b, c};
    Point* maxPoint = (Point*)findMax(points, 3, sizeof(Point), cmpPoint);
    printf("Result POINT: %.2lf, %.2lf, %.2lf\n", maxPoint->x, maxPoint->y, maxPoint->z);

    Human d = {50, 175};
    Human e = {69, 185};
    Human f = {80, 185};
    Human humans[] = {d, e, f};
    Human* maxHuman = (Human*)findMax(humans, 3, sizeof(Human), cmpHuman);
    printf("Result HUMAN: %.2lf, %u\n", maxHuman->weight_kg, maxHuman->height_cm);
    
    float arr3[] = {1.534, 24.22, 4.22, 9, 11.3};
    F2 floatArr2[5]; 

    for (int i = 0; i < 5; i++)
    {
        floatArr2[i].f = arr3[i];
    }

	float* max3 = (float*)findMax(arr3, sizeof(arr3)/sizeof(float), sizeof(float), cmpFloat);
    printf("Result FLOAT: %.2lf\n", *max3);	

	return 0;
}