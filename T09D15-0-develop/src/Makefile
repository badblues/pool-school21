.PHONY: all clean rebuild

all: main_executable_module.o data_io.o data_stat.o data_sort.o data_process.o decision.o
	gcc -o ../build/Quest_3 main_executable_module.o data_io.o data_stat.o data_sort.o data_process.o decision.o

main_executable_module.o: main_executable_module/main_executable_module.c
	gcc -c main_executable_module/main_executable_module.c
data_io.o: data_libs/data_io.c
	gcc -c data_libs/data_io.c
data_stat.o: data_libs/data_stat.c
	gcc -c data_libs/data_stat.c
data_sort.o: data_libs/data_sort.c
	gcc -c data_libs/data_sort.c
data_process.o: data_module/data_process.c
	gcc -c data_module/data_process.c
decision.o: yet_another_decision_module/decision.c
	gcc -c yet_another_decision_module/decision.c

data_process.so: data_process.o data_stat.o
	gcc -shared -o data_process.so data_process.o data_stat.o

data_stat.a: data_stat.o
	ar r data_stat.a data_stat.o

build_with_static: main_executable_module.o data_io.o data_stat.a data_sort.o data_process.o decision.o
	gcc -o ../build/Quest_5 main_executable_module.o data_io.o data_stat.a data_sort.o data_process.o decision.o

build_with_dynamic: main_executable_module.o data_io.o data_stat.o data_sort.o data_process.so data_process.o decision.o
	gcc -o ../build/Quest_6 main_executable_module.o data_io.o data_stat.o data_sort.o data_process.so data_process.o decision.o
	mv data_process.so ../build/

clean:
	rm -rf *.o *.a ../build/*.so
	rm ../build/Quest_*

rebuild: clean all