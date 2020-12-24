main = .main
objects = particle/pso.cpp function/function.cpp main.cpp

objects: $(objects)
	g++ -wall -g $(objects) -o $(main)

run:objects
	clear
	./$(main) 3 6 0 1 3 10
format:
	find . -regex '.*\.\(cpp\|hpp\|h\|c\)' -exec clang-format -style=file -i {} \;
