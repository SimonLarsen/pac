OBJECTS=Game.o Player.o Map.o Pickup.o DisplayLists.o Ghost.o SndMgr.o Particle.o

all: compile link

compile: Game.o DisplayLists.o Player.o Map.o Pickup.o Ghost.o SndMgr.o Particle.o link

Game.o: Game.cpp Game.hpp Player.hpp Ghost.hpp Map.hpp Pickup.hpp Particle.hpp
	g++ -c Game.cpp

DisplayLists.o: DisplayLists.cpp Game.hpp
	g++ -c DisplayLists.cpp

Player.o: Player.cpp Player.hpp Pickup.hpp defines.hpp Map.hpp SndMgr.hpp
	g++ -c Player.cpp

Map.o: Map.cpp Map.hpp Pickup.hpp Ghost.hpp
	g++ -c Map.cpp

Pickup.o: Pickup.cpp Pickup.hpp
	g++ -c Pickup.cpp

Ghost.o: Ghost.cpp Ghost.hpp defines.hpp Map.hpp
	g++ -c Ghost.cpp

SndMgr.o: SndMgr.cpp SndMgr.hpp
	g++ -c SndMgr.cpp

Particle.o: Particle.cpp Particle.hpp
	g++ -c Particle.cpp

.PHONY: link
link:
	g++ -o pac -lsfml-graphics -lsfml-audio -lsfml-system -lGLU $(OBJECTS)
