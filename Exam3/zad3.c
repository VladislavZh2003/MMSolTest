#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Product
{
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[3];
}Pr;

char *names[] = {"due","sia","tos","pat","dfi"};
char symbol[] = {'A','B','C','D'};

int main()
{
    srand(time(NULL));
    Pr prod[40];

    for (size_t i = 0; i < 40; i++)
    {
        strcpy(prod[i].product_name, names[rand()%5]);
        prod[i].product_type = symbol[rand()%4];
        prod[i].id = rand();
        prod[i].old_price = 5 + rand()%(5 - 101)/100;
        prod[i].new_price = (double)(100  + rand()%(10100 - 100)/100);
        printf("%lf\n",prod[i].new_price);
    }
    

    return 0;
}