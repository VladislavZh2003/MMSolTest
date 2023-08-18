#include <stdio.h>
#include <string.h>
int main()
{
    char line[1000];

    while (fgets(line, sizeof(line), stdin))
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U')
            {
                continue;
            }
            printf("%c", line[i]);
        }
    }
    return 0;
}