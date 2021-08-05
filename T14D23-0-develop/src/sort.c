#include "state_sort.h"

int compare(int* rec1, int* rec2) {
    int res = 0;
    int i = 0;
    while ((!res) && (i < 6)) {
        if (rec1[i] > rec2[i])
            res = 1;
        if (rec1[i] < rec2[i])
            res = -1;
        i++;
    }
    return res;
}

void swap(FILE* ptr, int* rec1, int* rec2, int id1, int id2) {
    fseek(ptr, (id1 * 8) * sizeof(int), SEEK_SET);
    fwrite(rec2, sizeof(int), 8, ptr);
    fseek(ptr, (id2 * 8) * sizeof(int), SEEK_SET);
    fwrite(rec1, sizeof(int), 8, ptr);
}


int sortFile(FILE* ptr) {
    int is_error = 0;
    int* rec1 = (int*)malloc(sizeof(int) * 8);
    int* rec2 = (int*)malloc(sizeof(int) * 8);
    int size = getLen(ptr) / 8;
    for (int i = 0; i < size; i++) {
        int j = 0;
        while (j < size - 1) {
            fseek(ptr, 8 * j * sizeof(int), SEEK_SET);
            fread(rec1, sizeof(int), 8, ptr);
            fread(rec2, sizeof(int), 8, ptr);
            int res = compare(rec1, rec2);
            if (res == 1)
                swap(ptr, rec1, rec2, j, j + 1);
            j++;
        }
    }
    free(rec1);
    free(rec2);
    fseek(ptr, 0, SEEK_SET);
    return is_error;
}
