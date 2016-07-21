/*********************************************************************  
** Program Filename: Game.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Implementation file for the Game class
** Input: Console
** Output: Console
*********************************************************************/

#include "Game.hpp"

/*********************************************************************  
** Function: Game::Game()
** Description: Default constructor for the Game class
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: Calls Setup()
*********************************************************************/ 
Game::Game() {
	Setup();
}

/*********************************************************************  
** Function: Game::~Game()
** Description: Destructor for the Game class
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: Calls destructor_helper on the current Space
*********************************************************************/ 
Game::~Game() {
	destructor_helper(current);
}

/*********************************************************************  
** Function: Game::Setup()
** Description: Sets up the Game board and initializes player data
** Parameters: 
** Pre-Conditions: "Room.hpp", "Hallway.hpp", "Bathroom.hpp"
** Post-Conditions: current points to the player's bedroom
*********************************************************************/ 
void Game::Setup() {
	time_left = 40;
	victory = false;
	num_inv = 0;
	health = 10;
	string descript;
	
	Space* tmp = new Room;
	current = tmp;
	descript = 
	"You’re sitting in your bedroom in peace, "
	"listening to the latest Coldplay record and playing some "
	"video games. You used to be a demon hunter, but you finally "
	"defeated their army several months ago. Now you’ve decided to "
	"retire, having had enough adventure for one (or many) lifetimes. "
	"As you work on beating the final boss in your game, you see a red "
	"light in the corner of your eye. “Not again,” you think to yourself. "
	"You look into your closet and see a hoard of fiery imps stampeding toward "
	"you. You know that in only a few seconds, the room will be completely cursed.";
	tmp->set_description(descript);
	tmp->set_room_name("Bedroom");
	Space* next;
	
	next = new Hallway;
	tmp->set_south(next);
	next->set_north(tmp);
	descript = 
	"You’re in the hallway. To the east is the guest bedroom. To the "
	"south is the living room. To the north is your former bedroom, now "
	"thoroughly incinerated by the approaching demon army. You feel the "
	"burning heat even standing in the next room.";
	next->set_description(descript);
	next->set_room_name("Hallway");
	
	tmp = tmp->get_south();
	
	next = new Room;
	tmp->set_east(next);
	next->set_west(tmp);
	descript = 
	"You're in your guest bedroom. You mostly use it for storage these days. ";
	next->set_description(descript);
	next->set_room_name("Guest Bedroom");
	next->add_item("Mini steam turbine", "Generates power using steam");
	next->add_item("Stuffed koala", "A fuzzy koala toy");
	next->add_item("Cheese grater", "Transforms cheese into confetti");
	
	next = new Room;
	tmp->set_south(next);
	next->set_north(tmp);
	descript =
	"You’re in your living room. You see paintings of your family on the walls. "
	"None of them call much these days ever since you started hanging around demons. "
	"You see your TV playing scrambled noise even though it was off a few minutes ago. ";
	next->set_description(descript);
	next->set_room_name("Living Room");
	next->add_item("TV", "A standard CRT from 1988");
	next->add_item("Remote control", "Controls your TV from feet away");
	next->add_item("Candle", "An unlit candle");
	
	
	tmp = tmp->get_south();
	
	next = new Bathroom;
	tmp->set_west(next);
	next->set_east(tmp);
	descript =
	"This is the bathroom – your favorite place to think about life. It’s relatively "
	"clean, with a sink, tub, and toilet. The sink is running for some reason.";
	next->set_description(descript);
	next->set_room_name("Bathroom");
	next->add_item("Toothbrush", "Dental hygiene is very important");
	
	next = new Room;
	tmp->set_south(next);
	next->set_north(tmp);
	descript = 
	"You’re in the garage. You used to work on demon-fighting technology here "
	"until you defeated them (or at least you thought you did). Now, there are "
	"a bunch of rusty tools and non-functional gadgets lying around.";
	next->set_description(descript);
	next->set_room_name("Garage");
	next->add_item("Demon disintegrator", "This would be really helpful right now, but its power supply rusted off");

}

/*********************************************************************  
** Function: Game::Play()
** Description: Coordinates the flow of the Game, terminating when the player
                wins, dies, or time expires
*********************************************************************/ 
void Game::Play() {
	cout << "**DEMON QUEST by ERIC PODOLSKY**" << std::endl;
	Info();
	Curse(current);
	while(victory==false && health > 0 && time_left > 0) {
		cout << "You have " << time_left << " moves before the demons break out and destroy the world." << std::endl;
		Input();
		--time_left;
		if(victory == false) {
			Info();
			if(current->isHarmful()) {
				Damage();
			}
		}
	}
	if(victory == true) {
		cout << "You wielded the demon disintegrator toward the army, causing them to vaporize instantly. You won!" << std::endl;
	}
	else if(health == 0) {
		cout << "You spent too much time in cursed rooms, and your bones turned to jelly. You died." << std::endl;
	}
	else {
		cout << "You ran out of time! The demons broke down all the walls of your house leaving rubble in their paths. You lose." << std::endl;
	}
}

/*********************************************************************  
** Function: Game::Input()
** Description: Manages the input of commands by the user. Terminates if 
                the players successfully moves or uses an item
*********************************************************************/ 
void Game::Input() {
	string input;
	char command;
	char yn;
	bool moved = false;
	bool used = false;
	do {
		cout << "What would you like to do (type h for a list of commands)? ";
		std::cin >> command;
		checkType(command);
		switch(command) {
			case 'n':
			case 's':
			case 'e':
			case 'w':
				if(Move(command)) {
					moved = true;
				}
				break;
			case 'x':
				if(current->get_num_items() == 0) {
					cout << "There are no items in the room!" << std::endl;
				}
				else {
					int num;
					cout << "Which is the number of the item you would like to examine? ";
					std::cin >> num;
					checkRange(num, 1, current->get_num_items());
					std::cout << current->get_items()[num-1].name << ": " << current->get_items()[num-1].description << std::endl;
					cout << "Would you like to take this item? (y/n) ";
					std::cin >> yn;
					checkYN(yn);
					if(yn == 'y' || yn == 'Y') {
						addToInventory(num-1);
						if(current->get_num_items()>0) {
							cout << "The items in this room are now: " << std::endl;
							for(size_t i = 0; i < current->get_num_items(); ++i) {
								cout << i+1 << ") " << current->get_items()[i].name << std::endl; 
							}
						}
					}
				}
				break;
			case 'i':
				if(num_inv > 0) {
					if(InventoryMenu())
						used = true;
				}
				else {
					cout << "Your inventory is empty." << std::endl;
				}
				break;
			case 'l':
				Info();
				break;
			case 'h':
				cout << "COMMANDS" << std::endl;
				cout << "n, s, w, e - move in a cardinal direction" << std::endl;
				cout << "x - examine/take an item in the room" << std::endl;
				cout << "i - look at your inventory" << std::endl;
				cout << "l - look at the room" << std::endl;
				break;
			default:
				cout << "Invalid command. Type h for a list of legal commands." << std::endl;
				break;
		}
	} while(moved == false && used == false);
}

/*********************************************************************  
** Function: Game::Info()
** Description: Displays information about the current room, including
                its description, the items it contains, and adjacent rooms
*********************************************************************/ 
void Game::Info() {
	cout << std::endl;
	cout << current->get_description() << std::endl;
	if(current->get_num_items()>0) {
		cout << "The items in this room are: " << std::endl;
		for(size_t i = 0; i < current->get_num_items(); ++i) {
			cout << i+1 << ") " << current->get_items()[i].name << std::endl; 
		}
	}
	cout << "The following rooms are adjacent: " << std::endl;
	if(current->get_south()!=NULL) {
		cout << "South: " << current->get_south()->get_room_name() << std::endl;
	}
	if(current->get_north()!=NULL) {
		cout << "North: " << current->get_north()->get_room_name() << std::endl;
	}
	if(current->get_east()!=NULL) {
		cout << "East: " << current->get_east()->get_room_name() << std::endl;
	}
	if(current->get_west()!=NULL) {
		cout << "West: " << current->get_west()->get_room_name() << std::endl;
	}
}

/*********************************************************************  
** Function: Game::addToInventory(size_t index)
** Description: Attempts to add an item from the current room to the inventory
** Parameters: index - the index of the item in the items array of the current Space
** Pre-Conditions: There is an item at the given index in the Space
** Post-Conditions: The item may be added to the inventory
*********************************************************************/ 
void Game::addToInventory(size_t index) {
	Item it = current->get_items()[index];
	if(num_inv < INV_SIZE) {
		inventory[num_inv]=it;
		++num_inv;
		current->take_item(index);
	}
	else {
		cout << "Your inventory is full. Choose an item to drop: " << std::endl;
		for(size_t i = 0; i < num_inv; ++i) {
			cout << i+1 << ") " << inventory[i].name << std::endl;
		}
		cout << num_inv + 1 << ") " << it.name << " (the held item)" << std::endl;
		int num;
		std::cin >> num;
		checkRange(num, 1, num_inv+1);
		if(static_cast<size_t>(num) <= num_inv) {
			current->add_item(inventory[num-1]);
			inventory[num-1]=it;
			current->take_item(index);
		}
	}
}

/*********************************************************************  
** Function: Game::InventoryMenu()
** Description: Allows the player to manage the inventory
** Parameters: 
** Pre-Conditions:
** Post-Conditions: returns true if an item is successfully used or two items
                    items are successfully combined
*********************************************************************/ 
bool Game::InventoryMenu() {
	char command;
	cout << "Inventory: " << std::endl;
	for(size_t i = 0; i < num_inv; ++i) {
		cout << i+1 << ") " << inventory[i].name << std::endl;
	}

	bool done = false;
	do {
		cout << "Type x to examine an item, u to use an item, c to try to combine two items, or any other key to exit inventory: ";
		std::cin >> command;
		checkType(command);
		switch(command) {
			case 'x':
				int num;
				cout << "Which is the number of the item you would like to examine? ";
				std::cin >> num;
				checkRange(num, 1, num_inv);
				std::cout << inventory[num-1].name << ": " << inventory[num-1].description << std::endl;
				break;
			case 'u':
				if(useItem())
					return true;
				break;
			case 'c':
				if(combineItems())
					return true;
				break;
			default:
				done = true;
				break;
		}
	} while(done == false);
	return false;
}

/*********************************************************************  
** Function: Game::useItem()
** Description: Attempts to use an item specified by the user
** Parameters: 
** Pre-Conditions:
** Post-Conditions: returns true if an item is successfully used
*********************************************************************/ 
bool Game::useItem() {
	int num;
	Item result;
	cout << "Which is the number of the item you would like to use? ";
	std::cin >> num;
	checkRange(num, 1, num_inv);
	
	cout << "You used the " << inventory[num-1].name << ". ";
	result=current->use(inventory[num-1]);
	if(result.name=="Win") {
		victory = true;
		return true;
	}
	else if(result.name=="Null") {
		return false;
	}
	else if(result.name=="Steam") {
		return true;
	}
	else {
		cout << "The item became " << result.name << "! " << std::endl;
		inventory[num-1]=result;
		if(result.name == "Burning candle") {
			cout << "As you light the candle, the demons burst through the door and overtake the hallway. You have to get out!" << std::endl;
			Curse(current);
		}
		return true;
	}
}

/*********************************************************************  
** Function: Game::combineItems()
** Description: Attempts to combined two items specified by the user
** Parameters: 
** Pre-Conditions:
** Post-Conditions: returns true if the items are successfully combined
*********************************************************************/ 
bool Game::combineItems() {
	int i1, i2;
	cout << "What is the number of the first item in the combination? ";
	cin >> i1;
	checkRange(i1, 1, num_inv);
	cout << "What is the number of the second item in the combination? ";
	cin >> i2;
	checkRange(i2, 1, num_inv);
	if(i1 == i2) {
		cout << "Error: You cannot combine an item with itself." << std::endl; 
		return false;
	}
	if((inventory[i1-1].name == "Demon disintegrator" && inventory[i2-1].name == "Mini steam turbine") ||
	(inventory[i2-1].name == "Demon disintegrator" && inventory[i1-1].name == "Mini steam turbine")) {
		cout << "You combined the two items!";
		inventory[i1-1] = Item("Demon disintegrator with turbine", "You fixed your demon disintegrator to run on steam power. Now where to find steam?");
		for(size_t i = i2-1; i < num_inv-1; ++i) {
			inventory[i] = inventory[i+1];
		}
		--num_inv;
		return true;
	}
	cout << "Error: You cannot combine those two items." << std::endl;
	return false;
}

/*********************************************************************  
** Function: Game::Move(char)
** Description: Attempts to move in the specified direction (n, s, w, or e)
** Parameters: direction - the direction to be moved
** Pre-Conditions: direction is one of n,s,w,or e
** Post-Conditions: returns true if the move was made
*********************************************************************/ 
bool Game::Move(char direction) {
	switch(direction) {
		case 'n':
			if(!isNull(current->get_north())) {
				current = current -> get_north();
				return true;
			}
			break;
		case 's':
			if(!isNull(current->get_south())) {
				current = current -> get_south();
				return true;
			}
			break;
		case 'w':
			if(!isNull(current->get_west())) {
				current = current -> get_west();
				return true;
			}
			break;
		case 'e':
			if(!isNull(current->get_east())) {
				current = current -> get_east();
				return true;
			}
			break;
	}
	return false;
}

/*********************************************************************  
** Function: Game::isNull(Space*)
** Description: Returns whether a pointer is NULL. Used by the Move() functional
                to determine whether a move is legal
** Parameters: ptr - the pointer to be tested
** Pre-Conditions: 
** Post-Conditions: returns true if the move was possible
*********************************************************************/ 
bool Game::isNull(Space* ptr) {
	bool tmp = (ptr == NULL);
	if(tmp) 
		cout << "You cannot move that way!" << std::endl;
	return tmp;
}

/*********************************************************************  
** Function: Game::Curse(Space*)
** Description: Transforms the given room into a Cursed room and deletes the old room
** Parameters: room - the room to be converted
** Pre-Conditions:
** Post-Conditions: returns true if the move was possible
*********************************************************************/ 
void Game::Curse(Space* room) {
	Space* cursed_room;
	cout << "The " << room->get_room_name() << " has been cursed!" << std::endl;
	cursed_room = new Cursed;
	if(current==room) {
		current = cursed_room;
	}
	
	if(room->get_south()!=NULL) {
		cursed_room->set_south(room->get_south());
		room->get_south()->set_north(cursed_room);
	}
	if(room->get_north()!=NULL) {
		cursed_room->set_north(room->get_north());
		room->get_north()->set_south(cursed_room);
	}
	if(room->get_east()!=NULL) {
		cursed_room->set_east(room->get_east());
		room->get_east()->set_west(cursed_room);
	}
	if(room->get_west()!=NULL) {
		cursed_room->set_west(room->get_west());
		room->get_west()->set_east(cursed_room);
	}
	
	
	delete room;
}

/*********************************************************************  
** Function: Game::Damage
** Description: T
** Pre-Conditions:
** Post-Conditions: returns true if the move was possible
*********************************************************************/ 
void Game::Damage() {
	--health;
	if(health > 0) {
		cout << "You were hurt by staying in a cursed room! You will die "
		"if you spend " << health << " more turns in cursed rooms!" << std::endl;
	}
}

/*********************************************************************  
** Function: Game::destructor_helper(Space* curr)
** Description: Recursively deletes the entire game board
** Parameters: curr - the starting position
** Pre-Conditions: 
** Post-Conditions: the entire game board is delete
*********************************************************************/ 
void Game::destructor_helper(Space* curr) {
	if(curr->get_south()!=NULL) {
		curr->get_south()->set_north(NULL);
		destructor_helper(curr->get_south());
	}
	if(curr->get_north()!=NULL) {
		curr->get_north()->set_south(NULL);
		destructor_helper(curr->get_north());
	}
	if(curr->get_east()!=NULL) {
		curr->get_east()->set_west(NULL);
		destructor_helper(curr->get_east());
	}
	if(curr->get_west()!=NULL) {
		curr->get_west()->set_east(NULL);
		destructor_helper(curr->get_west());
	}
	delete curr;
}