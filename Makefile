SOURCES = Game.cpp DisplayLists.cpp Player.cpp Map.cpp Pickup.cpp Ghost.cpp SndMgr.cpp
OBJECTS = Game.o Player.o Map.o Pickup.o DisplayLists.o Ghost.o SndMgr.o

all: compile link

compile:
	g++ -c $(SOURCES)

link:
	g++ -o pac -lsfml-graphics -lsfml-audio -lsfml-system -lGLU $(OBJECTS)
