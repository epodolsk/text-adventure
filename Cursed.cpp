/*********************************************************************  
** Program Filename: Cursed.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Implementation file for the Cursed class
** Input: N/A
** Output: Console
*********************************************************************/

#include "Cursed.hpp"

Cursed::Cursed() : Space() {
	description = 
	"What you see in this room is simply indescribable. It would be best"
	" to leave until you have some way of fighting the demons.";
	
	room_name = "Cursed Room";
	harmful = true;
}

Item Cursed::use(Item it) {
	if(it.name == "Activated demon disintegrator") {
		return Item("Win", "");
	}
	else {
		cout << "There was no effect." << std::endl;
		return Item();
	}
}