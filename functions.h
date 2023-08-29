#ifndef functions_h
#define functions_h
#include "material_list.h"

void initialize_list(list *list1);
void fill_material(material *nouveauElt, int identification, char name[], float price, int quantity);
list *insert_start(list *list1, int identification, char name[], float price, int quantity);
list *insert_end(list *list1, int identification, char name[], float price, int quantity);
list *insert_pos_before(list *list1, int identification, char name[], float price, int quantity, int position);
list *insert_pos_after(list *list1, int identification, char name[], float price, int quantity, int position);
//--------------------------------------------------------------------------------------------------------------
list *delete_start(list *list1);
list *delete_end(list *list1);
list *delete_pos(list *list1, int position);
//--------------------------------------------------------------------------------------------------------------
void display_list(material *start);
//--------------------------------------------------------------------------------------------------------------
void filling_data(material *new_stock);
list *add_material(list *list1);
list *remove_material(list *list1);
list *modify_material(list *list1);
void find_material(list *list1);
#endif