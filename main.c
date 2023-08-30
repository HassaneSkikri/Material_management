#include "material_list.h"
#include "functions.h"
//------------------------------------------------------------

int main(int argc, char const *argv[])
{
    list *list1;
    list1 = (list *)malloc(sizeof(list)); // Dynamic allocation of the list1
    initialize_list(list1);
    list1 = insert_start(list1, 1, "PC", 200, 12);
    list1 = insert_start(list1, 2, "phone", 222, 11);
    list1 = insert_start(list1, 3, "book", 322, 91);
    list1 = insert_start(list1, 4, "mouse", 222, 71);
    list1 = insert_start(list1, 5, "car", 222, 41);
    display_list(list1->start);
    save_list(list1);

    return 0;
}