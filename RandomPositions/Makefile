all: main.o game.o 
	gcc -o run main.o game.o
ran:
	./run
main.o: main.c
	gcc main.c
game.o: game.c
	gcc game.c
clean:
	rm run
	
