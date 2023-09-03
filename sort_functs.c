#include "material_list.h"
#include "functions.h"

list *sort(list *list1)
{
    material *temp1, *temp2, *min;
    int choice;
    printf("--------------menu-----------\n");
    printf("hello! what do you want ?\n");
    printf("1.Sort by id\n");
    printf("2.Sort by name\n");
    printf("3.Sort by price\n");
    printf("4.Sort by quantity\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (list1->start == NULL)
        {
            return list1;
        }
        for (temp1 = list1->start; temp1->following != NULL; temp1 = temp1->following)
        {
            int min_valeur = temp1->id;
            min = temp1;
            for (temp2 = temp1->following; temp2 != NULL; temp2 = temp2->following)
            {
                if (temp2->id < min_valeur)
                {
                    min = temp2;
                    min_valeur = temp2->id;
                }
            }
            if (min != temp1)
            {
                int temp = temp1->id;
                temp1->id = min->id;
                min->id = temp;
            }
        }
        return list1;
        break;
    case 2:
        if (list1->start == NULL)
        {
            return list1;
        }
        for (temp1 = list1->start; temp1->following != NULL; temp1 = temp1->following)
        {
            char *min_name;
            strcpy(min_name, temp1->name);
            min = temp1;
            for (temp2 = temp1->following; temp2 != NULL; temp2 = temp2->following)
            {
                int cmp = strcmp(temp2->name, min_name);
                if (cmp == 1)
                {
                    min = temp2;
                    min_name = temp2->name;
                }
            }
            if (min != temp1)
            {
                char *temp = temp1->name;
                strcpy(temp1->name, min->name);
                strcpy(min->name, temp);
            }
        }
        return list1;
        break;
    case 3:
        if (list1->start == NULL)
        {
            return list1;
        }
        for (temp1 = list1->start; temp1->following != NULL; temp1 = temp1->following)
        {
            float min_valeur = temp1->price;
            min = temp1;
            for (temp2 = temp1->following; temp2 != NULL; temp2 = temp2->following)
            {
                if (temp2->price < min_valeur)
                {
                    min = temp2;
                    min_valeur = temp2->price;
                }
            }
            if (min != temp1)
            {
                int temp = temp1->price;
                temp1->price = min->price;
                min->price = temp;
            }
        }
        return list1;
        break;
    case 4:
        if (list1->start == NULL)
        {
            return list1;
        }
        for (temp1 = list1->start; temp1->following != NULL; temp1 = temp1->following)
        {
            int min_valeur = temp1->quantity;
            min = temp1;
            for (temp2 = temp1->following; temp2 != NULL; temp2 = temp2->following)
            {
                if (temp2->quantity < min_valeur)
                {
                    min = temp2;
                    min_valeur = temp2->quantity;
                }
            }
            if (min != temp1)
            {
                int temp = temp1->quantity;
                temp1->quantity = min->quantity;
                min->quantity = temp;
            }
        }
        return list1;
        break;
    default:
        printf("oops this choice does not exist\n");
        break;
    }
}
