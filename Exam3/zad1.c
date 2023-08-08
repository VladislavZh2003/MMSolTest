#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bitmask 0b1

void my_xxd();

int main(int argc, char *argv[])
{
    if (argc != 3)
        exit(-1);
    char file_name[50], mode[50];
    strcpy(file_name, argv[1]);
    strcpy(mode, argv[2]);

    FILE *file = fopen(file_name, "r");
    char *buf;
    size_t n = 0;
    int c;

    if (file == NULL)
        return 0;

    buf = malloc(1000);

    while ((c = fgetc(file)) != EOF)
    {
        buf[n++] = (char)c;
    }
    buf[n] = '\0';

    if (mode[1] == 'H')
    {
        for (; *buf != '\0'; ++buf)
        {
            printf("%02x ", *buf);
        }
        printf("\n");
    }
    else if (mode[1] == 'B')
    {
        int i, j;
        unsigned char *b = (unsigned char *)buf;
        b += strlen(buf) - 1;
        for (i = 0; i < (int)strlen(buf); i++, b--)
        {
            for (j = 7; j > -1; j--)
            {
                printf("%d", ((*b) & bitmask << j) >> j);
            }
            printf(" ");
        }
        printf("\n");
    }

    // free(buf);
    fclose(file);

    return 0;
}