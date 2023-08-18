#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 20
typedef struct Book
{
    char title[150];
    char author[100];
    int pages;
    float price;
} Book;

typedef struct Node
{
    Book data;
    struct Node *next;
} Node;

Book library[COUNT];

void gen_random_str(char *str)
{
    size_t n = 10 + rand() % 11;
    for (size_t i = 0; i < n; i++)
    {
        size_t j = rand() % 52;
        if (j <= 25)
            str[i] = j + 'a';
        else if (j <= 51)
            str[i] = j - 26 + 'A';
    }
}

Node *init_library()
{
    Node *cur_node = malloc(sizeof(Node));
    for (size_t i = 0; i < COUNT; i++)
    {
        gen_random_str(cur_node->data.title);
        gen_random_str(cur_node->data.author);
        cur_node->data.price = (rand() % (100100 - 100) + 100) / 100.;
        cur_node->data.pages = (rand() % (2001 - 5) + 5);
    }
    return cur_node;
}

void print(Node *head)
{
    Node *cur_node = head->next;

    printf("Title: %21s, Author: %21s, Price: %7.2f, Pages: %4d\n", head->data.title, head->data.author, head->data.price, head->data.pages);
    while (cur_node->next != NULL)
    {
        printf("Title: %21s, Author: %21s, Price: %7.2f, Pages: %4d\n", cur_node->data.title, cur_node->data.author, cur_node->data.price, cur_node->data.pages);
        cur_node = cur_node->next;
    }
    printf("\n");
}

struct Node *swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

int sort(struct Node **head, int count)
{
    struct Node **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {
        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {
            struct Node *p1 = *h;
            struct Node *p2 = p1->next;

            if (p1->data.title[0] > p2->data.title[0])
            {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        if (swapped == 0)
            break;
    }
}

int main()
{
    srand(time(NULL));

    Node *head = NULL, *last_node = NULL;

    head = malloc(sizeof(Node));
    head = init_library();
    last_node = head;

    for (size_t i = 1; i < COUNT; i++)
    {
        Node *cur_node = malloc(sizeof(Node));
        cur_node = init_library();

        last_node->next = cur_node;
        last_node = cur_node;
    }
    last_node->next = NULL;

    print(head);
    sort(&head, COUNT);
    print(head);

    Node *cur_node = head->next;
    while (cur_node->next != NULL)
    {
        Node *toDelete = cur_node;
        cur_node = cur_node->next;
        free(toDelete);
    }
    free(head);

    return 0;
}