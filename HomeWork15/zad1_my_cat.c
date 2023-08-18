#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        FILE *fptr;

        char filename[100], c;

        strcpy(filename, argv[i]);

        fptr = fopen(filename, "r");
        if (fptr == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }

        // Read contents from file
        c = fgetc(fptr);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(fptr);
        }
        printf("\n");

        fclose(fptr);
    }

    return 0;
}
