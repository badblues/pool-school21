.PHONY: all clean rebuild
all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: s21_string_test.c s21_string.o 
	gcc -D Quest_1 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_1
strcmp_tests: s21_string_test.c s21_string.o
	gcc -D Quest_2 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_2
strcpy_tests: s21_string_test.c s21_string.o
	gcc -D Quest_3 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_3
strcat_tests: s21_string_test.c s21_string.o
	gcc -D Quest_4 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_4
strchr_tests: s21_string_test.c s21_string.o
	gcc -D Quest_5 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_5
strstr_tests: s21_string_test.c s21_string.o
	gcc -D Quest_6 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_6
strtok_tests: s21_string_test.c s21_string.o
	gcc -D Quest_7 -c s21_string_test.c
	gcc s21_string_test.o s21_string.o -o ../build/Quest_7

s21_string.o: s21_string.c
	gcc -c s21_string.c

clean:
	rm -rf *.o
	rm -rf ../build/Q*

rebuild: clean all