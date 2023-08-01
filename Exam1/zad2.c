#include <stdio.h>

void subseq(int arr[], int n, int dest[], int *new_n);

int main()
{
    int arr[10] = {5, 4, 3, 2, 1, 10, 11, 2, 3, 4};
    int size = 10;

    int *small_arr;
    int small_arr_size = 0;

    subseq(arr, size, small_arr, &small_arr_size);


    for (size_t i = 0; i < small_arr_size; i++)
    {
        printf("%d",small_arr[i]);
    }


    return 0;
}

void subseq(int arr[], int n, int dest[], int *new_n)
{
    int count = 0;
    int term[n];
    term[count] = arr[count];

    for (size_t i = 0; i < n-2; i++)
    {
        if(arr[i] > arr[i+1])
        {
            count++;
            term[count] = arr[i];
        }
        else
        {
            if(count > *new_n)
            {
                for (size_t j = 0; j < sizeof(term); j++)
                {
                    dest[j] = term[j];
                }
                count = 0;
            }
        }
    }
}