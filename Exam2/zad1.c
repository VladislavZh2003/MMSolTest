#include <stdio.h>
#include <string.h>

void code_string(char *stringA, char *coded_string);
char symbol_arr[] = {'!', '#', '/', '~', '=', '"', '\\', '>', '.', ','};

int main()
{
    char num_arr[500];
    char coded_arr[500];

    scanf("%s",num_arr);

    code_string(num_arr,coded_arr);

    printf("%s",coded_arr);

    return 0;
}

void code_string(char *stringA, char *coded_string)
{
    for (size_t i = 0; i < strlen(stringA); i++)
    {
        if(i % 2 == 0)
            coded_string[i] = stringA[i] + 17;
        else
            coded_string[i] = symbol_arr[stringA[i] - '0'];
    }
}