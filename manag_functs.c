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
    scanf("%.2f", &new_stock->price);
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
    int choice;
    printf("---------menu---------------\n");
    printf("hello! what do you want ?\n");
    printf("1.To add material at the start\n");
    printf("2.To add material at the end\n");
    printf("3.To add material after a position \n");
    printf("4.To add material before a position \n");
    printf("enter your choice please ?\n");
    scanf("%d", &choice);
    printf("how much material do you want to add? ");
    scanf("%d", &nbr);

    switch (choice)
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
    int choice;
    int position;
    material *stock[max];
    printf("---------menu---------------\n");
    printf("hello! what do you want ?\n");
    printf("1.delete material at the start\n");
    printf("2.delete material at the end\n");
    printf("3.Delete material at a position\n ");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
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
//------------------------------------------------------------
// modify an existing material in the list
list *modify_material(list *list1)
{

    material *temp = list1->start;
    int choice;
    int id, new_id;
    char name[40], new_name[40];
    float price, new_price;
    int quantity, new_quantity;
    do
    {

        printf("--------------menu-----------\n");
        printf("hello! what do you want ?\n");
        printf("1.Modify the id\n");
        printf("2.Modify the name\n");
        printf("3.Modify the price\n");
        printf("4.Modify the quantity\n");
        printf("5.exit from the programme\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Id that you want to change\n");
            scanf("%d", &id);
            while (temp != NULL && temp->id != id)
            {
                temp = temp->following;
            }
            if (temp != NULL)
            {
                printf("enter the new id:\n");
                scanf("%d", &new_id);
                temp->id = new_id;
            }
            else
            {
                printf("Material with the specified ID not found.\n");
            }
            break;
        case 2:
            printf("Enter the name that you want to change\n");
            scanf("%s", name);
            getchar();
            while (temp != NULL && strcmp(temp->name, name) != 0)
            {
                temp = temp->following;
            }
            if (temp != NULL)
            {
                printf("enter the new name:\n");
                scanf("%s", new_name);
                getchar();
                strcpy(temp->name, new_name);
            }
            else
            {
                printf("Material with the specified name not found.\n");
            }
            break;
        case 3:
            printf("Enter the price that you want to change\n");
            scanf("%.2f", &price);
            while (temp != NULL && temp->price != price)
            {
                temp = temp->following;
            }
            if (temp != NULL)
            {
                printf("enter the new price:\n");
                scanf("%d", &new_price);
                temp->price = new_price;
            }
            else
            {
                printf("Material with the specified price not found.\n");
            }
            break;
        case 4:
            printf("Enter the quantity that you want to change\n");
            scanf("%d", &quantity);
            while (temp != NULL && temp->quantity != quantity)
            {
                temp = temp->following;
            }
            if (temp != NULL)
            {
                printf("enter the new quantity:\n");
                scanf("%d", &new_quantity);
                temp->quantity = new_quantity;
            }
            else
            {
                printf("Material with the specified quantity not found.\n");
            }
            break;
        case 5:
            choice = 0;
            break;
        default:
            printf("oops this choice does not exist\n");
            break;
        }
    } while (choice >= 1 && choice <= 4); // Only repeat for valid choices

    return list1;
}

//------------------------------------------------------------
// recherche un material dans la list par son identifiant.
void find_material(list *list1)
{

    int choice;
    int id;
    char name[40];
    float price;
    int quantity;
    material *temp = list1->start;
    do
    {
        printf("--------------menu-----------\n");
        printf("hello! what do you want ?\n");
        printf("1.find by id\n");
        printf("2.find by name\n");
        printf("3.find by price\n");
        printf("4.find by quantity\n");
        printf("5.exit from the programme\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("what is the id that you want to find :\n");
            scanf("%d", &id);
            while (temp != NULL && temp->id != id)
            {
                temp = temp->following;
            }
            if (temp->id == id)
            {
                printf("Your data is:\nThe size:%d\nId:%d \nName: %s \nPrice %.2f \nQuantity %d\n", list1->size, temp->id, temp->name, temp->price, temp->quantity);
            }
            else
            {
                printf("Material with the specified ID not found.\n");
            }
            break;
        case 2:
            printf("what is the name that you want to find :\n");
            scanf("%s", name);
            getchar();
            while (temp != NULL && strcmp(temp->name, name) != 0)
            {
                temp = temp->following;
            }
            if (strcmp(temp->name, name) == 0)
            {
                printf("Your data is:\nThe size:%d\nId:%d \nName: %s \nPrice %.2f \nQuantity %d\n", list1->size, temp->id, temp->name, temp->price, temp->quantity);
            }
            else
            {
                printf("Material with the specified name not found.\n");
            }
            break;
        case 3:
            printf("what is the price that you want to find :\n");
            scanf("%.2f", &price);
            while (temp != NULL && temp->price != price)
            {
                temp = temp->following;
            }
            if (temp->price == price)
            {
                printf("Your data is:\nThe size:%d\nId:%d \nName: %s \nPrice %.2f \nQuantity %d\n", list1->size, temp->id, temp->name, temp->price, temp->quantity);
            }
            else
            {
                printf("Material with the specified price not found.\n");
            }
            break;
        case 4:
            printf("what is the quantity that you want to find :\n");
            scanf("%d", &quantity);
            while (temp != NULL && temp->quantity != quantity)
            {
                temp = temp->following;
            }
            if (temp->quantity == quantity)
            {
                printf("Your data is:\nThe size:%d\nId:%d \nName: %s \nPrice %.2f \nQuantity %d\n", list1->size, temp->id, temp->name, temp->price, temp->quantity);
            }
            else
            {
                printf("Material with the specified quantity not found.\n");
            }
            break;
        case 5:
            choice = 0;
            break;
        default:
            printf("oops this choice does not exist\n");
            break;
        }
    } while (choice >= 1 && choice <= 5);
}