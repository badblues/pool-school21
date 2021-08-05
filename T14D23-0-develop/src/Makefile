FLAGS = -Wall -Werror -Wextra

all: state_search state_sort clear_state

state_sort: state_sort.c input.c sort.c
	gcc $(FLAGS) -c state_sort.c input.c sort.c
	gcc state_sort.o input.o sort.o -o ../build/Quest_1

state_search: state_search.c input.c
	gcc $(FLAGS) -c state_search.c input.c
	gcc state_search.o input.o -o ../build/Quest_2  

clear_state: clear_state.c input.c
	gcc $(FLAGS) -c clear_state.c input.c
	gcc clear_state.o input.o -o ../build/Quest_3

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 

clean:
	rm *.o
	rm ../build/*