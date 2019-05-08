CC = g++
DEBUG = -g
CFLAGS = -c -Wall -Werror -pedantic
INCLUDE = -I /home/Adrien/SFML-2.4.1/include -L /home/Adrien/SFML-2.4.1/lib
BOOST = -I /home/Adrien/boost -L /home/Adrien/boost/lib
BOOSTL = -lboost_unit_test_framework
LFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

all: MarkovModel.o TextGenerator.o
	$(CC) -o TextGenerator MarkovModel.o TextGenerator.o 
	
MarkovModel.o: MarkovModel.cpp
	$(CC) $(CFLAGS) MarkovModel.cpp MarkovModel.hpp
	
TextGenerator.o: TextGenerator.cpp
	$(CC) $(CFLAGS) TextGenerator.cpp MarkovModel.hpp
	
clean:
	rm *.o *.exe