OBJECTS = Game.o Player.o Map.o Pickup.o DisplayLists.o Ghost.o SndMgr.o Particle.o

all: compile link

compile: Game DisplayLists Player Map Pickup Ghost SndMgr Particle link

Game: Game.cpp Player.hpp Ghost.hpp Map.hpp Pickup.hpp Particle.hpp
	g++ -c Game.cpp

DisplayLists: DisplayLists.cpp Game.hpp
	g++ -c DisplayLists.cpp

Player: Player.cpp Pickup.hpp defines.hpp Map.hpp SndMgr.hpp
	g++ -c Player.cpp

Map: Map.cpp Pickup.hpp Ghost.hpp
	g++ -c Map.cpp

Pickup: Pickup.cpp
	g++ -c Pickup.cpp

Ghost: Ghost.cpp defines.hpp Map.hpp
	g++ -c Ghost.cpp

SndMgr: SndMgr.cpp 
	g++ -c SndMgr.cpp

Particle: Particle.cpp 
	g++ -c Particle.cpp

.PHONY: link
link:
	g++ -o pac -lsfml-graphics -lsfml-audio -lsfml-system -lGLU $(OBJECTS)
