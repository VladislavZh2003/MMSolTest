#include <stdio.h>
#include <string.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t *dest_cnt);
int set(int a);
int get(int a);

int isEven(int a);
int isPrime(int a);
int isPositive(int a);
int square(int a);
int count_1_bits(int a);

void print_arr(int dest[] , int size);

int main()
{
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size;

    filter_and_map(arr, 8, isEven, set, dest, &new_size);
    print_arr(dest,new_size);

    filter_and_map(arr, 8, isPrime, square, dest, &new_size);
    print_arr(dest,new_size);

    filter_and_map(arr, 8, isPositive, count_1_bits, dest, &new_size);
    print_arr(dest,new_size);

    return 0;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t *dest_cnt)
{
    memset(dest, 0, 10);
    *dest_cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (filter_f(arr[i]) == 1)
        {
            *dest++ = map_f(arr[i]);
            *dest_cnt += 1;
        }
    }
}

int isPrime(int a)
{
    int i;
    for (size_t i = 2; i <= a/2; i++)
    {
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int isEven(int a)
{
    if(a%2 == 0)
        return 1;
    return 0;
}

int isPositive(int a)
{
    if(a >= 0)
        return 1;
    return 0;
}

int square(int a)
{
    return a * a;
}

int count_1_bits(int a)
{
    int bit_count = 0;
    while(a)
    {
        bit_count += a & 1;
        a >>= 1;
    } 
    return bit_count;
}

int set(int a)
{
    return a;
}
int get(int a)
{
    return 1;
}

void print_arr(int dest[] , int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");
}
