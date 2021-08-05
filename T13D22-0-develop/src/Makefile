all: cipher logging_cipher

cipher: cipher.c file_io.c encode.c logger.c
	gcc -c cipher.c file_io.c encode.c logger.c
	gcc cipher.o file_io.o encode.o logger.o -o ../build/cipher

logging_cipher: cipher.c file_io.c encode.c logger.c
	gcc -D LOG -c cipher.c
	gcc -c file_io.c encode.c logger.c 
	gcc cipher.o file_io.o encode.o logger.o  -o ../build/logging_cipher
clean:
	rm *.o
	rm ../build/*