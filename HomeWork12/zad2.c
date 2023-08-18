#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(double arr[],int size);
void fill_arr_rand(int A, int B, int strat, int size, double *arr);

int main()
{
    int n,m,p;
    srand(time(NULL));
    scanf("%d",&n);

    double *arr1 = malloc(sizeof(double) * n);
    fill_arr_rand(0, 1001, 0, n, arr1);
    print_arr(arr1,n);

    scanf("%d",&m);
    double *arr2 = realloc(arr1,sizeof(double) * m);
    fill_arr_rand(1000, 1001, n, m, arr2);
    print_arr(arr2,m);

    scanf("%d",&p);
    double *arr3 = realloc(arr2,sizeof(double) * p);
    fill_arr_rand(2000, 1001, m, p, arr3);
    print_arr(arr3,p);

    return 0;
}

void fill_arr_rand(int A, int B, int strat, int size, double *arr)
{
    for (size_t i = strat; i < size; i++)
    {
        arr[i] = (A + rand()%B)/1000.;
    }
}

void print_arr(double arr[],int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%lf ",arr[i]);
    }
    printf("\n");
}