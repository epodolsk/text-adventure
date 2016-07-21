/*********************************************************************  
** Program Filename: Bathroom.hpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Header file for the Bathroom class
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef PODOLSKE_BATHROOM_HPP
#define PODOLSKE_BATHROOM_HPP

#include "Space.hpp"

class Bathroom: public Space {
public:
	Bathroom();
	Item use(Item it);
private:
	bool isSteamy;
};

#endif