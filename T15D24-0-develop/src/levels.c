#include "libs.h"

int print_levels(FILE* ptr) {  // OUTPUT
    int is_error = 0;
    levels rec;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        printf("LEVELS\n");
        fread(&rec, sizeof(levels), 1, ptr);
        while(!feof(ptr)) {
            printf("%d %d %d\n", rec.level, rec.cells_num, rec.pr_flag);   
            fread(&rec, sizeof(levels), 1, ptr);
        }
    }
    return is_error;
}

int checkLevelsId(FILE* ptr, int id) {
    int res = 0;
    fseek(ptr, 0, SEEK_END);
    int size = ftell(ptr)/sizeof(levels);
    if ((id >= 0) && (id < size))
        res = 1;
    return res;
}

levels getLevelsRecord() {
    levels rec;
    while (1) {
        printf("Enter: level, number of cells on level, protection flag\n");
        if (scanf("%d %d %d", &(rec.level), &(rec.cells_num), &(rec.pr_flag)) == 3)
            break;
        else
            printf("n/a\n");
    }
    return rec;
}

int addLevelsRecord(FILE* ptr, levels rec) {  // ADD
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, 0, SEEK_END);
        fwrite(&rec, sizeof(levels), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}

int deleteLevelsRecord(FILE* ptr, int id) {  // DELETE
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        levels rec;
        int i = id;
        fseek(ptr, (i+1) * sizeof(levels), SEEK_SET);
        while (!feof(ptr)) {
            fseek(ptr, (i+1) * sizeof(levels), SEEK_SET);
            if (fread(&rec, sizeof(levels), 1, ptr) != 1)
                break;
            fseek(ptr, i * sizeof(levels), SEEK_SET);
            fwrite(&rec, sizeof(levels), 1, ptr);
            i++;
        }
        fseek(ptr, 0, SEEK_SET);
        truncate(levels_fpath, i * sizeof(levels));
    }
    return is_error;
}

int insertLevelsRecord(FILE* ptr, int id, levels new_rec) {  //INSERT
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        levels rec;
        int i;
        fseek(ptr, -sizeof(levels), SEEK_END);
        fread(&i, sizeof(int), 1, ptr);
        while (i >= id) {
            fseek(ptr, i * sizeof(levels), SEEK_SET);
            fread(&rec, sizeof(levels), 1, ptr);
            fseek(ptr, (i + 1) * sizeof(levels), SEEK_SET);
            fwrite(&rec, sizeof(levels), 1, ptr);
            i--;
        }
        fseek(ptr, (i+1) * sizeof(levels), SEEK_SET);
        fwrite(&new_rec, sizeof(levels), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}

int changeLevelsRecord(FILE* ptr, int id, levels rec) {  // CHANGE
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, id * sizeof(levels), SEEK_SET);
        fwrite(&rec, sizeof(levels), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}
