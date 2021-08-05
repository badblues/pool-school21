all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module: main_module_entry_point.c print_module.o
	gcc -D Quest_1 -c main_module_entry_point.c
	gcc main_module_entry_point.o print_module.o -o ../build/Quest_1

documentation_module: main_module_entry_point.c documentation_module.o print_module.o
	gcc -D Quest_2 -c main_module_entry_point.c
	gcc main_module_entry_point.o documentation_module.o print_module.o -o ../build/Quest_2

documentation_module.o: documentation_module.c
	gcc -c documentation_module.c

print_module.o: print_module.c
	gcc -c print_module.c

bst_create_test: bst.c bst_create_test.c
	gcc -c bst.c bst_create_test.c
	gcc bst.o bst_create_test.o -o ../build/Quest_3
	
bst_insert_test: bst.c bst_insert_test.c
	gcc -c bst.c bst_insert_test.c
	gcc bst.o bst_insert_test.o -o ../build/Quest_4

bst_traverse_test: bst.c bst_traverse_test.c
	gcc -c bst.c bst_traverse_test.c
	gcc bst.o bst_traverse_test.o -o ../build/Quest_5

clean:
	rm *.o
	rm ../build/*

rebuild:
	clean all