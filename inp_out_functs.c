#include "functions.h"
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

//--------------------------------------------------------------
void load_list(list *list1, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    char line[50]; // Buffer size adjusted to match line length

    // Read and discard the header lines
    for (int i = 0; i < 2; i++)
    {
        if (fgets(line, sizeof(line), fp) == NULL)
        {
            printf("Error reading header from file\n");
            exit(1);
        }
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        int id, quantity;
        char name[10];
        float price;

        if (sscanf(line, "| %d | %9[^|] | %f | %d |", &id, name, &price, &quantity) == 4)
        {
            insert_end(list1, id, name, price, quantity);
        }
    }

    printf("-------Loading the list completed-------\n");
    fclose(fp);
}
