all: invaders

invaders: invaders.c ../z80.o
	gcc invaders.c -I .. ../z80.o `sdl-config --cflags --libs` -o invaders
