#ifndef functions_h
#define functions_h
#include "material_list.h"


void initialize_list(list *list1);
list *insert_start(list *list1, int identification, char name[], float price, int quantity);
void fill_material(material *nouveauElt, int identification, char name[], float price, int quantity);
void display_list(material *start);

#endif