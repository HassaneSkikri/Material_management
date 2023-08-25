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
// insertion at the end of the list
list *insert_end(list *list1, int identification, char name[], float price, int quantity)
{
    material *nouveauElt = (material *)malloc(sizeof(material));
    fill_material(nouveauElt, identification, name, price, quantity);
    nouveauElt->previous = nouveauElt->following = NULL;
    if (list1->end == NULL)
    {
        list1->start = list1->end = nouveauElt;
    }
    else
    {
        material *temp = list1->end;
        temp->following = nouveauElt;
        nouveauElt->previous = temp;
        list1->end = nouveauElt;
    }
    list1->size++;
    return list1;
}
//-------------------------------------------------------------------------------------------------
// insert the item before the position
list *insert_pos_before(list *list1, int identification, char name[], float price, int quantity, int position)
{
    material *nouveauElt = (material *)malloc(sizeof(material));
    fill_material(nouveauElt, identification, name, price, quantity);
    nouveauElt->previous = nouveauElt->following = NULL;
    material *temp = list1->start;
    if (temp == NULL)
    {
        list1->start = list1->end = nouveauElt;
    }
    else
    {
        while (temp != NULL && temp->id != position)
        {
            temp = temp->following;
        }
        if (temp->id == position)
        {
            nouveauElt->following = temp;
            nouveauElt->previous = temp->previous;
            if (temp->previous != NULL)
            {
                temp->previous->following = nouveauElt;
            }
            else
            {
                list1->start = nouveauElt;
            }
            temp->previous = nouveauElt;
        }
        else
        {
            printf("cette position nexiste pas \n");
        }
    }
    list1->size++;
    return list1;
}
//-------------------------------------------------------------------------------------------------
// insert the item after the position
list *insert_pos_after(list *list1, int identification, char name[], float price, int quantity, int position)
{
    material *nouveauElt = (material *)malloc(sizeof(material));
    fill_material(nouveauElt, identification, name, price, quantity);
    nouveauElt->previous = nouveauElt->following = NULL;
    material *temp = list1->start;
    if (temp == NULL)
    {
        list1->start = list1->end = nouveauElt;
    }
    else
    {
        while (temp != NULL && temp->id != position)
        {
            temp = temp->following;
        }
        if (temp->id == position)
        {
            nouveauElt->following = temp->following;
            nouveauElt->previous = temp;
            if (temp->following != NULL)
            {
                temp->following->previous = nouveauElt;
            }
            else
            {
                list1->end = nouveauElt; // Update the end pointer
            }
            temp->following = nouveauElt;
        }

        else
        {
            printf("the position %d not found \n", position);
        }
    }
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