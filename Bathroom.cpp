/*********************************************************************  
** Program Filename: Bathroom.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Implementation file for the Bathroom class
** Input: N/A
** Output: Console
*********************************************************************/

#include "Bathroom.hpp"

Bathroom::Bathroom() : Space() {
	description = "You are in the bathroom. You see a running faucet, a bathtub, and a toilet.";
	isSteamy = false;
}

Item Bathroom::use(Item it) {
	if(it.name == "Burning candle") {
		isSteamy = true;
		cout << "Steam fills the bathroom as you place the burning candle near the running sink." << std::endl;
		return Item("Steam","");
	}
	
	if(isSteamy && it.name == "Demon disintegrator with turbine") {
		return Item("Activated demon disintegrator", "The demon disintegrator has powered on and is ready to do its job!");
	}
	cout << "There was no effect." << std::endl;
	return Item();
}