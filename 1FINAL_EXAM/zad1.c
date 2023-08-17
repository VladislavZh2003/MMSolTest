#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ITEMS_COUNT 10

typedef struct BankAccount
{
    uint16_t number;
    char owner_name[100];
    float availabilit;
    char currency[4];
} BankAc;

typedef struct Node
{
    BankAc data;
    struct Node *next;
} Node;

BankAc accounts[ITEMS_COUNT];

char *curency[] = {"$", "lv", "euro", "rub", "lira"};

void gen_random_name(char *str)
{
    for (size_t i = 0; i < 2 + (rand() % 4); i++)
    {
        size_t k = 0;
        str[k] = rand() %26 + 'A';

        size_t n = 1 + rand() % 20;
        k = 1;
        for (; k < n; k++)
        {
            size_t j = rand() % 26;
            str[k] = j + 'a';
        }

        str[k] = ' ';
    }
}

void init_accounts()
{
    for (size_t i = 0; i < ITEMS_COUNT; i++)
    {
        accounts[i].number = i;
        gen_random_name(accounts[i].owner_name);
        accounts[i].availabilit = (rand() % 10000000) / 100.;
        strcpy(accounts[i].currency, curency[rand() % 5]);
    }
}

void push_back(BankAc new_data, Node **head)
{
    Node *new_last_node = malloc(sizeof(Node));
    if(!new_last_node){
        perror("Could not malloc\n");
        exit(-1);
    }
    new_last_node->data = new_data;
    new_last_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_last_node;
        return;
    }

    Node *cur_node = *head;
    while(cur_node->next != NULL)
    {
        cur_node = cur_node->next;
    }

    cur_node->next = new_last_node;
}

void print_linked_list(Node *head)
{
    for (; head != NULL; head = head->next)
    {
        printf("Number: %3d, Name: %50s, Availability: %6.2f, Curency: %s\n", head->data.number, head->data.owner_name, head->data.availabilit, head->data.currency);
    }
    printf("\n");
}

double totalBalance(Node* head)
{
    double sum = 0;
    for (; head != NULL; head = head->next)
    {
        sum += head->data.availabilit; 
    }
    return sum;
}

Node *maxBalance(Node* head)
{
    Node *Big = malloc(sizeof(Node));

    int Biggest = 0;
    float BigAva = accounts[0].availabilit;

    for (size_t i = 0; i < ITEMS_COUNT-1; i++)
    {
        if(BigAva < accounts[i+1].availabilit)
        {
            Biggest = i+1;
            BigAva = accounts[i+1].availabilit;
        }
            
    }
    Big->data.number = accounts[Biggest].number;
    strcpy(Big->data.owner_name, accounts[Biggest].owner_name);
    Big->data.availabilit = accounts[Biggest].availabilit;
    strcpy(Big->data.currency, accounts[Biggest].currency);
    
    return Big;
}

int main()
{
    srand(time(NULL));

    init_accounts();

    Node *head = NULL;

    for (size_t i = 0; i < ITEMS_COUNT; i++)
    {
        push_back(accounts[i], &head);
    }
    
    print_linked_list(head);

    printf("sum = %f\n",totalBalance(head));

    Node *Big = maxBalance(head);

    print_linked_list(Big);
    

    return 0;
}

