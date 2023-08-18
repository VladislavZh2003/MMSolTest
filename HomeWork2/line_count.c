#include <stdio.h>
int main()
{

    int c;
    int lines = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            lines++;
        }
    }
    printf("Number of lines: %d\n", lines);
    return 0;
}

//$ cat input.txt | ./linecount