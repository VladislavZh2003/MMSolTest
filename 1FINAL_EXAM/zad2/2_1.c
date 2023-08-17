#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char file_name[30];
    strcpy(file_name, argv[1]);
    uint64_t numbers = atoi(argv[2]);

    uint64_t buf[numbers];

    FILE *fptr;

    if ((fptr = fopen(file_name, "wb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }



    for (size_t i = 0; i < numbers; i++)
    {
        buf[i] = i;
    }
    fwrite(&buf, sizeof(buf), 1, fptr);

    fclose(fptr);

    return 0;
}

//sudo ghex numbers.bin