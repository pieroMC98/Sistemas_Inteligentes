main = main
objects = PSO.c main.c 
format : 
	clang-format -i *.c *.h
objects : $(objects) gcc $(objects) -
		      o $(main)
run:objects
	./ $(main)
