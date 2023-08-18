#include <stdio.h>

//genarray.c
void *findMax(void *arr, size_t n, size_t elem_s, int (*cmp)(const void *, const void *));

int cmpInt(const void *el1, const void *el2);
int cmpDouble(const void *el1, const void *el2);
int cmpChar(const void *el1, const void *el2);

int main()
{
    int arr[] = {1, 2, -1, 3, 5, 11, 12, 13, 2, 100, 22};
    int *max = findMax(arr, sizeof(arr) / sizeof(int), sizeof(int), cmpInt);
    printf("%d\n", *max);

    double arrd[] = {1.0, 2.0, -1.0, 3.8, 100.3, 22.6};
    double *maxd = findMax(arrd, sizeof(arrd) / sizeof(double), sizeof(double), cmpDouble);
    printf("%lf\n", *maxd);

    char arrc[] = {'A','a','6','u','?','.','L'};
    char *maxc = findMax(arrc, sizeof(arrc) / sizeof(char), sizeof(char), cmpChar);
    printf("%c\n", *maxc);

    return 0;
}

void *findMax(void *arr, size_t n, size_t elem_s, int (*cmp)(const void *, const void *))
{   
    if(elem_s == 4)
    {
        int *max;
        int *int_arr = arr;
        max = &int_arr[0];
        for (size_t i = 0; i < n-1; i++)
        {
            if(cmp(&int_arr[i], &int_arr[i+1]) == -1)
                max = &int_arr[i];
            else if(cmp(&int_arr[i], &int_arr[i+1]) == 1)
                max = &int_arr[i+1];
        }
        return max;
    }
    else if(elem_s == 8)
    {
        double *maxd;
        double *double_arr = arr;
        maxd = &double_arr[0];
        for (size_t i = 0; i < n-1; i++)
        {
            if(cmp(&double_arr[i], &double_arr[i+1]) == -1)
                maxd = &double_arr[i];
            else if(cmp(&double_arr[i], &double_arr[i+1]) == 1)
                maxd = &double_arr[i+1];
        }
        return maxd;
    }
    else if(elem_s == 1)
    {
        char *maxc;
        char *char_arr = arr;
        maxc = &char_arr[0];
        for (size_t i = 0; i < n-1; i++)
        {
            if(cmp(&char_arr[i], &char_arr[i+1]) == -1)
                maxc = &char_arr[i];
            else if(cmp(&char_arr[i], &char_arr[i+1]) == 1)
                maxc = &char_arr[i+1];
        }
        return maxc;
    }
    return 0;
}

int cmpInt(const void *el1, const void *el2)
{
    const int *i1 = el1, *i2 = el2;

    if(*i1 == *i2)
        return 0;
    else if(*i1 < *i2)
        return 1;
    else(*i1 > *i2);
        return -1;
}
int cmpDouble(const void *el1, const void *el2)
{
    const double *i1 = el1, *i2 = el2;

    if(*i1 == *i2)
        return 0;
    else if(*i1 < *i2)
        return 1;
    else
        return -1;
}
int cmpChar(const void *el1, const void *el2)
{
    const char *i1 = el1, *i2 = el2;

    if(*i1 == *i2)
        return 0;
    else if(*i1 < *i2)
        return 1;
    else(*i1 > *i2);
        return -1;
}
