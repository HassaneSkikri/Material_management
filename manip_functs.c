#include "material_list.h"

// Initialize the liste
void initialize_list(list *list1)
{
    list1->start = NULL;
    list1->end = NULL;
    list1->size = 0;
}

//-------------------------------------------------------------------------------------------------
// fill the material with the data
void fill_material(material *nouveauElt, int identification, char name[], float price, int quantity)
{
    nouveauElt->id = identification;
    strcpy(nouveauElt->name, name);
    nouveauElt->price = price;
    nouveauElt->quantity = quantity;
}

//-------------------------------------------------------------------------------------------------
// Inserts an item at the beginning of the list.
list *insert_start(list *list1, int identification, char name[], float price, int quantity)
{
    material *nouveauElt = (material *)malloc(sizeof(material));
    fill_material(nouveauElt, identification, name, price, quantity);
    nouveauElt->previous = nouveauElt->following = NULL;

    if (list1->start == NULL)
    {
        list1->start = list1->end = nouveauElt;
    }
    else
    {
        nouveauElt->following = list1->start;
        nouveauElt->following->previous = nouveauElt;
    }

    list1->start = nouveauElt;
    list1->size++;
    return list1;
}

//-------------------------------------------------------------------------------------------------
// display the list
void display_list(material *start)
{
    material *temp = start;
    if (temp == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        printf("---------------------\n");
        while (temp != NULL)
        {
            printf("Id : %d\n", temp->id);
            printf("Name  : %s\n", temp->name);
            printf("Price: %f\n", temp->price);
            printf("Quantity : %d\n", temp->quantity);
            printf("---------------------\n");
            temp = temp->following;
        }
    }
}