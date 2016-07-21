/*********************************************************************  
** Program Filename: Space.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Implementation file for the Space class
** Input: N/A
** Output: Console
*********************************************************************/

#include "Space.hpp"

/*********************************************************************  
** Function: Space::Space()
** Description: Default constructor for the Space class
*********************************************************************/ 
Space::Space() {
	north = NULL; 
	south = NULL; 
	west = NULL; 
	east = NULL; 
	num_items = 0;
	max_items = 4;
	items = new Item[max_items];
	harmful = false;
}

/*********************************************************************  
** Function: Space::add_item(string, string)
** Description: Creates an item from the parameters and adds it to the Space
** Parameters: item_name - the name of the item
               item_description - the description of the item
** Pre-Conditions: "utilities.hpp" for resizeArray()
** Post-Conditions: ++num_items
*********************************************************************/ 
void Space::add_item(string item_name, string item_description) {
	if(num_items == max_items) {
		resizeArray<Item>(items, num_items, max_items);
	}
	items[num_items]=Item(item_name, item_description);
	++num_items;
}

/*********************************************************************  
** Function: Space::add_item(string, string)
** Description: Adds an item to the Space
** Parameters: it - the item to be added
** Pre-Conditions: "utilities.hpp" for resizeArray()
** Post-Conditions: ++num_items
*********************************************************************/ 
void Space::add_item(Item it) {
	if(num_items == max_items) {
		resizeArray<Item>(items, num_items, max_items);
	}
	items[num_items] = it;
	++num_items;
}

/*********************************************************************  
** Function: Space::take_item(string, string)
** Description: Removes an item from the Space
** Parameters: index - the index of the item to be removed in the items array
** Pre-Conditions:
** Post-Conditions: --num_items
*********************************************************************/ 
void Space::take_item(size_t index) {
	for(size_t i = index; i < num_items-1; ++i) {
		items[i] = items[i+1];
	}
	--num_items;
}
