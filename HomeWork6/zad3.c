#include <stdio.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t *dest_cnt);

int isPositive(int);
int addOne(int);

int main()
{
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size = 0;


    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);

    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ",dest[i]);
    }
    printf("\n");
    
    return 0;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t *dest_cnt)
{
    for (size_t i = 0; i < n; i++)
    {
        if(filter_f(arr[i]) == 1)
        {
            *dest++ = map_f(arr[i]);
            *dest_cnt += 1;
        }
    }
    
}

int isPositive(int a)
{
    if(a >= 0)
        return 1;
    return 0;
}

int addOne(int a)
{
    return a += 1;
}
