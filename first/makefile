main = .main
objects = Particle/PSO.cpp Function/function.cpp main.cpp

objects: $(objects)
	g++ -Wall -g $(objects) -o $(main)

run:objects
	clear
	./$(main) 2 3
format:
	clang-format -i *.cpp *.h
