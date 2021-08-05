#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int getLen(FILE* ptr);
int search(FILE* ptr, int* date, int* code);
int compare(int* date, int* rec);
void writeCode(int code);

int main() {
    int is_error = 0;
    int code;
    int date[3];
    char* path = getPath();
    FILE* ptr = fopen(path, "rb");
    free(path);
    if (ptr == NULL)
        is_error = 1;
    else
        is_error = getDate(date);
    if (!is_error)
        is_error = search(ptr, date, &code);
    if (!is_error) {
        printf("%d", code);
        writeCode(code);
    } else {
        printf("n/a");
    }
    if (ptr)
        fclose(ptr);
    return 0;
}

int compare(int* date, int* rec) {
    int res = 0;
    if ((date[0] == rec[0]) && (date[1] == rec[1]) && (date[2] == rec[2]))
        res = 1;
    return res;
}

int getLen(FILE* ptr) {
    int i = 0;
    int num;
    fseek(ptr, 0, SEEK_SET);
    while (!feof(ptr)) {
        fread(&num, sizeof(int), 1, ptr);
        i++;
    }
    fseek(ptr, 0, SEEK_SET);
    return i;
}

int search(FILE* ptr, int* date, int* code) {
    int is_error = 1;
    int* rec = (int*)malloc(sizeof(int) * 8);
    int size = getLen(ptr) / 8;
    for (int i = 0; i < size; i++) {
        fread(rec, sizeof(int), 8, ptr);
        if (compare(date, rec)) {
            *code = rec[7];
            is_error = 0;
        }
    }
    free(rec);
    return is_error;
}

void writeCode(int code) {
    FILE* fptr = fopen("../src/code.txt", "w+");
    fprintf(fptr, "%d", code);
    fclose(fptr);
}
