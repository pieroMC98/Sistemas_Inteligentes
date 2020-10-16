main = .main
objects = PSO.cpp main.cpp

objects: $(objects)
	g++ -Wall -g $(objects) -o $(main)

run:objects
	./$(main)
format:
	clang-format -i *.cpp *.h
