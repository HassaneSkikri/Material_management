#include "material_list.h"
#include "functions.h"
//------------------------------------------------------------

int main(int argc, char const *argv[])
{
    list *list1;
    list1 = (list *)malloc(sizeof(list)); // Dynamic allocation of the list1
    initialize_list(list1);
    load_list(list1, "manage_material.txt");

    display_list(list1->start);

    return 0;
}