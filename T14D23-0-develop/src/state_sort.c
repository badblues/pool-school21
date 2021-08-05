#include "state_sort.h"
#include "input.h"
#include "sort.h"


int fileOutput(FILE* ptr);
void menu();
int addRec(FILE* ptr);

int main() {
    menu();
    return 0;
}

void menu() {
    int is_error = 0;
    int choice;
    char* path = getPath();
    FILE* ptr = fopen(path, "r+b");
    free(path);
    if (ptr == NULL)
        is_error = 1;
    choice = getChoice();
    if (is_error == 0) {
        switch (choice) {
            case 0:
                is_error = fileOutput(ptr);
                break;
            case 1:
                sortFile(ptr);
                is_error = fileOutput(ptr);
                break;
            case 2:
                is_error = addRec(ptr);
                if (!is_error) {
                    sortFile(ptr);
                    is_error = fileOutput(ptr);
                }
                break;
            default:
                is_error = 1;
                break;
        }
    }
    if (is_error)
        printf("n/a\n");
    if (ptr)
        fclose(ptr);
}

int fileOutput(FILE* ptr) {
    fseek(ptr, 0, SEEK_SET);
    int is_error = 0;
    int num = 5;
    int size = getLen(ptr);
    if ((size % 8 != 0) || (size < 8)) {
        is_error = 1;
    } else {
        fread(&num, sizeof(int), 1, ptr);
        printf("%d", num);
        for (int i = 1; i < size ; i++) {
            if (i % 8 == 0)
                printf("\n");
            else
                printf(" ");
            fread(&num, sizeof(int), 1, ptr);
            printf("%d", num);
        }
    }
    return is_error;
}

int addRec(FILE* ptr) {
    int is_error = 0;
    int arr[8];
    for (int i = 0; i < 8; i++) {
        if (scanf("%d", &(arr[i])) != 1) {
            is_error = 1;
            break;
        }
    }
    char c;
    if ((scanf("%c", &c) > 0) && ((c != '\n') && (c != ' ')))
        is_error = 1;
    if (!is_error) {
        fseek(ptr, 0, SEEK_END);
        fwrite(arr, sizeof(int), 8, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
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
    return i-1;
}
