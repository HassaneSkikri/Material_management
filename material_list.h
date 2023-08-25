#ifndef materiel_list_h
#define materiel_list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

//------------------------------------------------------------
// The principale structure

typedef struct material
{
    int id;
    char name[100];
    float price;
    int quantity;
    struct material *previous;
    struct material *following;
} material;

//------------------------------------------------------------
// The structure of the list

typedef struct list
{
    struct material *start;
    struct material *end;
    int size;
} list;





#endif