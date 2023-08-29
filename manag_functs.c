#include "functions.h"
#include "material_list.h"

void filling_data(material *new_stock)
{
    printf("Id: ");
    scanf("%d", &new_stock->id);
    getchar();
    printf("Give me the name of the product: ");
    fgets(new_stock->name, sizeof(new_stock->name), stdin);
    new_stock->name[strcspn(new_stock->name, "\n")] = '\0';
    printf("Enter the price of the product: ");
    scanf("%f", &new_stock->price);
    getchar();
    printf("Enter the quantity: ");
    scanf("%d", &new_stock->quantity);
    getchar();
}

//------------------------------------------------------------
// adding new material
list *add_material(list *list1)
{
    int i = 0, nbr, position;
    int choix;
    printf("---------menu---------------\n");
    printf("hello! what do you want ?\n");
    printf("1.To add material at the start\n");
    printf("2.To add material at the end\n");
    printf("3.To add material after a position \n");
    printf("4.To add material before a position \n");
    printf("enter your choice please ?\n");
    scanf("%d", &choix);
    printf("how much material do you want to add? ");
    scanf("%d", &nbr);

    switch (choix)
    {

    case 1:
        for (i = 0; i < nbr; i++)
        {
            material *new_stock = (material *)malloc(sizeof(material));
            filling_data(new_stock);
            list1 = insert_start(list1, new_stock->id, new_stock->name, new_stock->price, new_stock->quantity);
            free(new_stock);
        }
        break;
    case 2:
        for (i = 0; i < nbr; i++)
        {
            material *new_stock = (material *)malloc(sizeof(material));
            filling_data(new_stock);
            list1 = insert_end(list1, new_stock->id, new_stock->name, new_stock->price, new_stock->quantity);
            free(new_stock);
        }
        break;
    case 3:
        for (i = 0; i < nbr; i++)
        {

            printf("Enter the position that you want to insert after :\n");
            scanf("%d", &position);
            material *new_stock = (material *)malloc(sizeof(material));
            filling_data(new_stock);
            list1 = insert_pos_after(list1, new_stock->id, new_stock->name, new_stock->price, new_stock->quantity, position);
            free(new_stock);
        }
        break;

    case 4:
        for (i = 0; i < nbr; i++)
        {

            printf("Enter the position that you want to insert before :\n");
            scanf("%d", &position);
            material *new_stock = (material *)malloc(sizeof(material));
            filling_data(new_stock);
            list1 = insert_pos_before(list1, new_stock->id, new_stock->name, new_stock->price, new_stock->quantity, position);
            free(new_stock);
        }
        break;

    default:
        printf("!!oops, this choice does not exist!! \n");
        break;
    }
    return list1;
}

//------------------------------------------------------------
// remove a material
list *remove_material(list *list1)
{
    int choix;
    int position;
    material *stock[max];
    printf("---------menu---------------\n");
    printf("hello! what do you want ?\n");
    printf("1.delete material at the start\n");
    printf("2.delete material at the end\n");
    printf("3.Delete material at a position\n ");
    printf("Enter your choice\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        list1 = delete_start(list1);
        return list1;
        break;
    case 2:
        list1 = delete_end(list1);
        return list1;
        break;
    case 3:
        printf("Enter the position that you want to insert \n");
        scanf("%d", &position);
        list1 = delete_pos(list1, position);
        break;
    default:
        printf("oops this choice dont existe\n");
        break;
    }
    return list1;
}