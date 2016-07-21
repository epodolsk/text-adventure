/*********************************************************************  
** Program Filename: Room.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Implementation file for the Room class
** Input: N/A
** Output: Console
*********************************************************************/

#include "Room.hpp"

Room::Room() : Space() {
	description = "You are in a bedroom.";
}

Item Room::use(Item it) {
	cout << "There was no effect." << std::endl;
	return Item();
}