main = main
objects = \
../first/Function/function.cpp \
../Operator/operator.cpp \
../first/Particle/PSO.cpp \
../second/Frog/frog.cpp \
./Source/Source.cpp \
./Bee/Bee.cpp \
./Bee/Empleada/Empleada.cpp \
./Bee/Observadora/Observadora.cpp \
./Bee/Exploradora/Exploradora.cpp \
./main.cpp
objects: $(objects)
	clear
	g++ -Wall -g $(objects) -o $(main)

run:objects
	clear
	./$(main) 3 6 0 1 3 10
format:
	find . -regex '.*\.\(cpp\|hpp\|h\|c\)' -exec clang-format -style=file -i {} \;
