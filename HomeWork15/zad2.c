#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char file_name[30];

    printf("Write file name: ");
    scanf("%s", file_name);

    if (access(file_name, F_OK) != 0)
    {
        printf("ERROR!");
        exit(-1);
    }

    FILE *f1 = fopen(file_name, "w");

    int i, j, count = argc;
    char temp[25];
    char *arr[count];

    for (size_t i = 0; i < count; i++)
    {
        arr[i] = argv[i];
    }

    for (i = 0; i <= count; i++)
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }


    for (int i = 1; i < argc; i++)
        fprintf(f1, "%s\n", arr[i]);
    
    fclose(f1);

    return 0;
}