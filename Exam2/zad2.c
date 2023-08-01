#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct Car
{
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;
char *car_moldels[] = {"Audi_s3", "VW_Golf", "BMW_E36", "Mercedes_S350", "Ford_Mustang", "Toyota_Supra", "Peugeot_508", "Citroen_C4", "Honda_Civic", "Porche_Cayenne"};

int (*getComparator(int n))(const void *, const void *);

int compare_model_inc(const void *el1, const void *el2);
int compare_model_dec(const void *el1, const void *el2);
int compare_maxspeed_inc(const void *el1, const void *el2);
int compare_maxspeed_dec(const void *el1, const void *el2);
int compare_price_inc(const void *el1, const void *el2);
int compare_price_dec(const void *el1, const void *el2);

void print_car_arr(Car arr[], size_t size);

int main()
{
    srand(time(NULL));
    int number_of_func;
    scanf("%d", &number_of_func);

    size_t size = 10;
    Car my_car[size];
    for (size_t i = 0; i < size; i++)
    {
        strcpy(my_car[i].model, car_moldels[rand() % 10]);
        my_car[i].maxspeed = 110 + (rand() % (350 - 150));
        my_car[i].price = (double)(300000 + rand() % (1000000000 - 300000)) / 1000;
    }

    print_car_arr(my_car, size);

    qsort(my_car,size,sizeof(Car),getComparator(number_of_func));
    print_car_arr(my_car, size);

    return 0;
}

int (*getComparator(int n))(const void *, const void *)
{
    switch (n)
    {
    case 1:
        return compare_model_inc;
    case 2:
        return compare_model_dec;
    case 3:
        return compare_maxspeed_inc;
    case 4:
        return compare_maxspeed_dec;
    case 5:
        return compare_price_inc;
    case 6:
        return compare_price_dec;
    default:
        return compare_model_inc;
    }
}

int compare_model_inc(const void *el1, const void *el2)
{
    return (((Car*)el1)->model[0] - ((Car*)el2)->model[0]);
}
int compare_model_dec(const void *el1, const void *el2)
{
    return (((Car*)el2)->model[0] - ((Car*)el1)->model[0]);
}
int compare_maxspeed_inc(const void *el1, const void *el2)
{
    return (((Car*)el1)->maxspeed - ((Car*)el2)->maxspeed);
}
int compare_maxspeed_dec(const void *el1, const void *el2)
{
    return (((Car*)el2)->maxspeed - ((Car*)el1)->maxspeed);
}
int compare_price_inc(const void *el1, const void *el2)
{
    return (((Car*)el1)->price - ((Car*)el2)->price);
}
int compare_price_dec(const void *el1, const void *el2)
{
    return (((Car*)el2)->price - ((Car*)el1)->price);
}

void print_car_arr(Car arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Model: %s; Max speed: %dkm/h; Price: %lflv;\n", arr[i].model, arr[i].maxspeed, arr[i].price);
    }
    printf("\n");
}
