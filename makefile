CPP = g++
CPPFLAGS  = -g -Wall
RM = rm -f

default: final

final:  main.o utilities.o Space.o Cursed.o Hallway.o Bathroom.o Room.o Game.o
	$(CPP) $(CPPFLAGS) -o final main.o utilities.o Space.o Cursed.o Hallway.o Bathroom.o Room.o Game.o

main.o:  main.cpp Space.hpp utilities.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

utilities.o:  utilities.cpp utilities.hpp
	$(CPP) $(CPPFLAGS) -c utilities.cpp
	
Space.o:  Space.cpp Space.hpp
	$(CPP) $(CPPFLAGS) -c Space.cpp
	
Cursed.o:  Cursed.cpp Cursed.hpp Space.hpp
	$(CPP) $(CPPFLAGS) -c Cursed.cpp

Hallway.o:  Hallway.cpp Hallway.hpp Space.hpp
	$(CPP) $(CPPFLAGS) -c Hallway.cpp

Bathroom.o:  Bathroom.cpp Bathroom.hpp Space.hpp
	$(CPP) $(CPPFLAGS) -c Bathroom.cpp

Room.o:  Room.cpp Room.hpp Space.hpp
	$(CPP) $(CPPFLAGS) -c Room.cpp
	
Game.o:  Game.cpp Game.hpp Space.hpp
	$(CPP) $(CPPFLAGS) -c Game.cpp

clean: 
	$(RM) final *.o *~