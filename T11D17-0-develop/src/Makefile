all: door_struct polynomial stack_test

door_struct: dmanager_module.c
	gcc dmanager_module.c -o ../build/Quest_1

polynomial: polynomial.c
	gcc polynomial.c -o ../build/Quest_2

stack_test: stack_test.c stack.c
	gcc -c stack_test.c stack.c
	gcc stack_test.o stack.o -o ../build/Quest_3

clean:
	rm ../build/*
	rm *.o

rebuild:
	clean all