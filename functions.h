#ifndef functions_h
#define functions_h
#include "material_list.h"


void initialize_list(list *list1);
void fill_material(material *nouveauElt, int identification, char name[], float price, int quantity);
list *insert_start(list *list1, int identification, char name[], float price, int quantity);
list *insert_end(list *list1, int identification, char name[],float price,int quantity);
list *insert_pos_before(list *list1, int identification, char name[], float price, int quantity, int position);
list *insert_pos_after(list *list1, int identification, char name[], float price, int quantity, int position);


void display_list(material *start);

#endif