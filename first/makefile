main = .main
objects = Particle/PSO.cpp Function/function.cpp main.cpp

objects: $(objects)
	g++ -Wall -g $(objects) -o $(main)

run:objects
	clear
	./$(main) 3 6 0 1 3 10
format:
	find . -regex '.*\.\(cpp\|hpp\|h\|c\)' -exec clang-format -style=file -i {} \;
