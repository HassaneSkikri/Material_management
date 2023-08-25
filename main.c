#include "material_list.h"
#include "functions.h"
//------------------------------------------------------------

int main(int argc, char const *argv[])
{
    list *list1;
    int i;
    list1 = (list *)malloc(sizeof(list)); // Dynamic allocation of the list1
    initialize_list(list1);
    list1 = insert_start(list1, 1, "HAY", 789, 23);
    list1 = insert_start(list1, 3, "HI", 779, 83);
    list1 = insert_pos_after(list1, 6, "HASSANE", 456, 32,3);
    list1 = insert_pos_before(list1, 9, "SKIKRIE", 466, 30,1);

    display_list(list1->start);
    list1 = delete_pos(list1,3);
    display_list(list1->start);

    return 0;
}