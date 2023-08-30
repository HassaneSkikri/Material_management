#include"functions.h"
#include "material_list.h"

//--------------------------------------------------------------
void save_list(list *list1)
{
    FILE *fp;
    fp = fopen("manage_material.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    // Print header
    fprintf(fp, "________________________________________________\n");
    fprintf(fp, "| Identifiant |    Name    |  Price  | Quantity |\n");
    fprintf(fp, "|_____________|____________|_________|__________|\n");

    material *temp = list1->start;
    while (temp != NULL)
    {
        fprintf(fp, "| %-11d | %-10s | %-7.2f | %-8d |\n",
                temp->id, temp->name, temp->price, temp->quantity);
        fprintf(fp, "|_____________|____________|_________|__________|\n");
        temp = temp->following;
    }
    printf("-------the mission is completed-------\n");
    fclose(fp);
}
