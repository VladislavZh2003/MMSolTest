#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define COUNT 10
typedef struct Book
{
    char title[150];
    char author[100];
    int pages;
    double price;
} Book;
char *book_titles[] = {
    "Cat Of Utopia",
    "Duke Of My Imagination",
    "Humans Of Insanity",
    "Hunters Of The Forsaken",
    "Descendants And Humans",
    "Turtles And Snakes",
    "Inception Of Heaven",
    "Hatred Of Darkness",
    "Walking The Commander",
    "Hiding The Ocean"};
char *book_authors[] = {
    "CARMEN LORENZO",
    "ANASTASIA PAUL",
    "HOMER COOKE",
    "CALLIE BRADLEY",
    "STERLING BECK",
    "TERI LAMB",
    "TOBY SANTOS",
    "LAWRENCE TINGEY",
    "BARRETT HIGGINS",
    "FRED DOLTON"
};

int compare_title_inc(const void *el1, const void *el2);
int compare_title_dec(const void *el1, const void *el2);
int compare_author_inc(const void *el1, const void *el2);
int compare_author_dec(const void *el1, const void *el2);
int compare_pages_inc(const void *el1, const void *el2);
int compare_pages_dec(const void *el1, const void *el2);
int compare_price_inc(const void *el1, const void *el2);
int compare_price_dec(const void *el1, const void *el2);

void print_library(Book arr[]);

int main()
{
    srand(time(NULL));

    Book library[COUNT];
    for (size_t i = 0; i < COUNT; i++)
    {
        strcpy(library[i].title, book_titles[rand() % 10]);
        strcpy(library[i].author, book_authors[rand() % 10]);
        library[i].pages = 5 + (rand() % (5 - 2000));
        library[i].price = (double)(100 + rand() % (100 - 100000)) / 100;
    }
    print_library(library);

    qsort(library,COUNT,sizeof(Book),compare_title_inc);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_title_dec);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_author_inc);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_author_dec);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_pages_inc);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_pages_dec);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_price_inc);
    print_library(library);
    qsort(library,COUNT,sizeof(Book),compare_price_dec);
    print_library(library);

    return 0;
}

int compare_title_inc(const void *el1, const void *el2)
{
    return (((Book*)el1)->title[0] - ((Book*)el2)->title[0]);
}
int compare_title_dec(const void *el1, const void *el2)
{
    return (((Book*)el2)->title[0] - ((Book*)el1)->title[0]);
}
int compare_author_inc(const void *el1, const void *el2)
{
    return (((Book*)el1)->author[0] - ((Book*)el2)->author[0]);
}
int compare_author_dec(const void *el1, const void *el2)
{
    return (((Book*)el2)->author[0] - ((Book*)el1)->author[0]);
}
int compare_pages_inc(const void *el1, const void *el2)
{
    return (((Book*)el1)->pages - ((Book*)el2)->pages);
}
int compare_pages_dec(const void *el1, const void *el2)
{
    return (((Book*)el2)->pages - ((Book*)el1)->pages);
}
int compare_price_inc(const void *el1, const void *el2)
{
    return (((Book*)el1)->price - ((Book*)el2)->price);
}
int compare_price_dec(const void *el1, const void *el2)
{
    return (((Book*)el2)->price - ((Book*)el1)->price);
}

void print_library(Book arr[])
{
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Book title: %s; Book author: %s; Pages: %d; Price: %lflv;\n", arr[i].title, arr[i].author, arr[i].pages, arr[i].price);
    }
    printf("\n");
}