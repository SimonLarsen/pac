SOURCES = Game.cpp DisplayLists.cpp Player.cpp Map.cpp Pickup.cpp
OBJECTS = Game.o Player.o Map.o Pickup.o DisplayLists.o

all:
	g++ -c $(SOURCES)
	g++ -o pac -lsfml-graphics -lsfml-system -lGLU $(OBJECTS)
