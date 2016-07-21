/*********************************************************************  
** Program Filename: Space.hpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Header file for the Space class
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef PODOLSKE_SPACE_HPP
#define PODOLSKE_SPACE_HPP

#include <string>
#include <iostream>
#include "utilities.hpp"
using std::string;
using std::cout;

struct Item {
	Item() {name = "Null"; description = "Null";}
	Item(string new_name, string new_description) {name = new_name; description = new_description;}
	string name;
	string description;
};

class Space {
public:
	Space();
	virtual ~Space() {delete [] items;}
	
	virtual Item use(Item it) = 0;
	
	//accessors
	/*********************************************************************  
	** Function: Space::get_north()
	** Description: Accessor for north
	*********************************************************************/ 
	Space* get_north() {return north;}
	
	/*********************************************************************  
	** Function: Space::get_south()
	** Description: Accessor for south
	*********************************************************************/ 
	Space* get_south() {return south;}
	
	/*********************************************************************  
	** Function: Space::get_west()
	** Description: Accessor for west
	*********************************************************************/ 
	Space* get_west() {return west;}
	
	/*********************************************************************  
	** Function: Space::get_east()
	** Description: Accessor for east
	*********************************************************************/ 
	Space* get_east() {return east;}
	
	/*********************************************************************  
	** Function: Space::get_description()
	** Description: Accessor for description
	*********************************************************************/ 
	string get_description() {return description;}
	
	/*********************************************************************  
	** Function: Space::get_num_items()
	** Description: Accessor for num_items
	*********************************************************************/ 
	size_t get_num_items() {return num_items;}
	
	/*********************************************************************  
	** Function: Space::get_items()
	** Description: Returns a pointer to the items array
	*********************************************************************/ 
	Item* get_items() {return items;}
	
	/*********************************************************************  
	** Function: Space::get_room_name()
	** Description: Accessor for room_name
	*********************************************************************/ 
	string get_room_name() {return room_name;}

	/*********************************************************************  
	** Function: Space::isHarmful()
	** Description: Accessor for harmful
	*********************************************************************/ 
	bool isHarmful() {return harmful;}

	
	//mutators
	/*********************************************************************  
	** Function: Space::set_north(Space*)
	** Description: Points north at ptr
	*********************************************************************/ 
	void set_north(Space* ptr) {north = ptr;}
	
	/*********************************************************************  
	** Function: Space::set_south(Space*)
	** Description: Points south at ptr
	*********************************************************************/ 	
	void set_south(Space* ptr) {south = ptr;}
	
	/*********************************************************************  
	** Function: Space::set_west(Space*)
	** Description: Points west at ptr
	*********************************************************************/ 
	void set_west(Space* ptr) {west = ptr;}
	
	/*********************************************************************  
	** Function: Space::set_east(Space*)
	** Description: Points east at ptr
	*********************************************************************/ 
	void set_east(Space* ptr) {east = ptr;}
	
	/*********************************************************************  
	** Function: Space::set_description(string)
	** Description: Sets the Space's description to new_description
	*********************************************************************/ 
	void set_description(string new_description) {description = new_description;}
	
	/*********************************************************************  
	** Function: Space::set_room_name(string)
	** Description: Sets the Space's name to new_room_name
	*********************************************************************/ 
	void set_room_name(string new_room_name) {room_name = new_room_name;}
	
	//add or remove items
	void add_item(string item_name, string item_description);
	void add_item(Item it);
	void take_item(size_t index);
	
protected:
	//pointers to cardinal directions
	Space* north;
	Space* south;
	Space* west;
	Space* east;
	
	//Space item data
	Item* items;
	size_t max_items;
	size_t num_items;
	
	//other Space information
	string room_name;
	string description;
	bool harmful;
};

#endif