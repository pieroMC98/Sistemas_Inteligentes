main = .main
objects = \
../first/Function/function.cpp \
../first/Particle/PSO.cpp \
./Frog/frog.cpp \
main.cpp

objects: $(objects)
	clear
	g++ -Wall -g $(objects) -o $(main)

run:objects
	clear
	./$(main) 3 6 0 1 3 10
format:
	find . -regex '.*\.\(cpp\|hpp\|h\|c\)' -exec clang-format -style=file -i {} \;
