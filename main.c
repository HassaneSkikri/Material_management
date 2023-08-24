#include "material_list.h"
#include "functions.h"
//------------------------------------------------------------

int main(int argc, char const *argv[])
{
    list *list1;
    int i;

    printf("How many materials do you want to add ?");
    scanf("%d", &i);

    list1 = (list *)malloc(sizeof(list)); // Dynamic allocation of the list1
    initialize_list(list1);

    material *stock[i];

    for (i = 0; i < 2; i++)
    {
        stock[i] = (material *)malloc(sizeof(material)); // Dynamic allocation of the stock(i)
        printf("Filling in the data for the material %d:\n", i + 1);
        printf("Id : ");
        scanf("%d", &stock[i]->id);
        getchar();
        printf("Name of the product : ");
        fgets(stock[i]->name, sizeof(stock[i]->name), stdin);
        stock[i]->name[strcspn(stock[i]->name, "\n")] = '\0'; // Remove the newline character
        printf("Price of the product : ");
        scanf("%f", &stock[i]->price);
        getchar();
        printf("Quantity : ");
        scanf("%d", &stock[i]->quantity);
        getchar();

        list1 = insert_start(list1, stock[i]->id, stock[i]->name, stock[i]->price, stock[i]->quantity);
    }
    display_list(list1->start);

    // Free allocated memory
    for (int j = 0; j < i; j++)
    {
        free(stock[j]);
    }
    free(list1);

    return 0;
}