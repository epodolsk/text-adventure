/*********************************************************************  
** Program Filename: Cursed.hpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Header file for the Cursed class
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef PODOLSKE_CURSED_HPP
#define PODOLSKE_CURSED_HPP

#include "Space.hpp"

class Cursed: public Space {
public:
	Cursed();
	Item use(Item it);
	bool isHarmful() {return true;}
private:
};

#endif