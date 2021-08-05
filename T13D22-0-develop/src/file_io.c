#include <stdio.h>
#include "cipher.h"
#include "encode.h"

int fileOutput(FILE* ptr) {
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        char c = fgetc(ptr);
        is_error = 1;
        while (c != -1) {
            is_error = 0;
            printf("%c", c);
            c = fgetc(ptr);
        }
    }
    return is_error;
}

int fileInput(FILE* ptr) {
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, 0, SEEK_END);
        fputc('\n', ptr);
        char c;
        scanf("%c%c", &c, &c);
        while (c != '\n') {
            fputc(c, ptr);
            scanf("%c", &c);
        }
    }
    return is_error;
}

int readFile(char* path) {
    int is_error = 0;
    FILE* ptr = fopen(path, "r");
    is_error = fileOutput(ptr);
    fclose(ptr);
    return is_error;
}

int writeToFile(char* path) {
    int is_error = 0;
    FILE* ptr = fopen(path, "r+");
    is_error = fileInput(ptr);
    fclose(ptr);
    return is_error;
}
