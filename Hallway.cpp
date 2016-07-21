/*********************************************************************  
** Program Filename: Hallway.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Implementation file for the Hallway class
** Input: N/A
** Output: Console
*********************************************************************/

#include "Hallway.hpp"

Hallway::Hallway() : Space() {
	description = "You are in a hallway.";
}

Item Hallway::use(Item it) {
	if(it.name == "Candle") {
		cout << "You press the candle to the bedroom door, and the heat from the demon invasion is enough to light the candle" << std::endl;
		return Item("Burning candle", "The candle is now lit and radiating heat");
	}
	else {
		cout << "There was no effect." << std::endl;
		return Item();
	}
}