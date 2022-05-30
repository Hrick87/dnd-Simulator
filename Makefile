CC = g++

CFLAGS = -Wall -g -std=c++1z

main: main.cpp Attack.o Spell.o Character.o 
	$(CC) $(CFLAGS) $^ -o $@

%.o: 
	$(CC) $(FLAGS) -c $< -o $@
