# Material Management

## Practice the Doubly Linked List

**This project is written in the C programming language and focuses on creating a material management program. based on a doubly linked list.**

### Goal

**The goal of this project is to manage materials using a doubly linked list data structure.**

#### Step 1: Data Structure

**Define  the data structure for material information:**

```c
struct material {
  int id;
  char name[50];
  float price;
  int quantity;
  struct material* previous;
  struct material* following;
};
```
#### Step 2: 

**define the structure of the doubly linked list to store the material:**

```c
struct list {
  struct element* start;
  struct element* end;
  int size;
};
```
#### Step 3: Basic List Manipulation Functions

**Implement the following basic functions for manipulating the list of materials:**

- ✅ `initialize_list()`: Initializes an empty list.
- ✅ `initialize_list()`: Initializes an empty list.
- ✅ `insert_start(list*, material)`: Inserts an item at the beginning of the list.
- ✅ `insert_end(list*, material)`: Inserts an item at the end of the list.
- ✅ `delete_start(list*)`: Removes the first item from the list.
- ✅ `delete_end(list*)`: Deletes the last item in the list.
- ✅ `display_list(list*)`: Displays the items in the list.

#### Step 4: Material Management Functions

**Implement the following  functions for the management of the materials:**

- ✅ `add_material(list*)`: Adds a new material to the list.
- ✅ `modify_material(list*, int)`: Modifies an existing material in the list.
- ✅ `remove_material(list*, int)`: Deletes a material from the list.
- ✅ `find_material(list*, int)`: Searches for material in the list by its identifier.

#### Step 5: Sorting Functions

**Implement sorting functions applied to this doubly linked list, in this case, the functions:**

- ✅ `sort_by_id(list*)`: Sorts the list by ascending identifier.
- ✅ `sort_by_name(list*)`: Sorts the list by ascending hardware name.
- ✅ `sort_by_price(list*)`: Sorts the list by ascending price.
- ✅ `sort_by_quantity(list*)`: Sorts the list by increasing quantity.

#### Step 6: File I/O Functions

**Add two functions for saving and loading:**

- ✅ `save_list(list*, char*)`: Save the list to a file.
- ✅ `load_list(list*, char*)`: Load the list from a file.

#### Step 7 :

***We will write a main function that uses the previous functions to carry out the management of the materials. This function could have the following format:***
```c
int main() {
list lst;
initialize_list(&lst);
//Use functions to manage material return 0;
}
```
