#include <stdio.h>

void reverseArray(int *arr, int length)
{
    int *start = arr;
    int *end = arr + length - 1;
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++; // otivame element nagore
        end--;   // start[0]++ - tova uvelichava stoinostta
    }
}
int main()
{
    int arr[] = {1, 2, 3, 5, 4};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    reverseArray(arr, length);
    printf("Reversed Array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}