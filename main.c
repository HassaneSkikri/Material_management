#include "material_list.h"
#include "functions.h"
//------------------------------------------------------------

int main(int argc, char const *argv[])
{
    list *list1;
    list1 = (list *)malloc(sizeof(list));
    initialize_list(list1);
    int choix;
    do
    {
        material *stock = (material *)malloc(sizeof(material));
        printf("---------------menu---------------\n");
        printf("Hello!\nWhat are you want to do ?\n");
        printf("0.To exit from the programme\n");
        printf("1.To add a new material to the list.\n");
        printf("2.To modify material from the list.\n");
        printf("3.To delete material from the list.\n");
        printf("4.To find material from the list.\n");
        printf("5.To Sort the list croissant.\n");
        printf("6.To save the list into a file.\n");
        printf("7.To load a file into a list.\n");

        printf("entrer your choice\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 0:
            exit(0);
            break;
        case 1:
            list1 = add_material(list1);
            display_list(list1->start);
            break;
        case 2:
            list1 = modify_material(list1);
            display_list(list1->start);
            break;
        case 3:
            list1 = remove_material(list1);
            display_list(list1->start);
            break;
        case 4:
            find_material(list1);
            display_list(list1->start);
            break;
        case 5:
            list1 = sort(list1);
            display_list(list1->start);
            break;
        case 6:
            save_list(list1);
            display_list(list1->start);
            break;
        case 7:
            load_list(list1, "manage_material.txt");
            display_list(list1->start);
            break;
        default:
            printf("oops this choice isn't exist try again \n");
            break;
        }
    } while (choix >= 0 && choix <= 7);
    return 0;
}