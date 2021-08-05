#include "libs.h"

int print_modules(FILE* ptr) {  // OUTPUT
    int is_error = 0;
    modules rec;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        printf("MODULES\n");
        fread(&rec, sizeof(modules), 1, ptr);
        while(!feof(ptr)) {
            printf("%d %s %d %d %d\n", rec.id, rec.name, rec.level, rec.cell, rec.flag);   
            fread(&rec, sizeof(modules), 1, ptr);
        }
    }
    return is_error;
}

void getname(char* name) {
    int size = 0;
    char c = ' ';
    scanf("%c", &c);
    if (c == '\n')
        scanf("%c", &c);
    while ((c != '\n')&& (size != 30)) {
        name[size++] = c;
        scanf("%c", &c);
    }
    if (size > 30)
        printf("n/a\n");
    else
        name[size] = '\0';
}

int getLastId(FILE* ptr) {
    int id = -1;
    if (ptr != NULL) {
        fseek(ptr, -sizeof(modules), SEEK_END);
        fread(&id, sizeof(int), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return id;
}

int checkModulesId(FILE* ptr, int id) {
    int res = 0;
    if ((id >=0) && (id <= getLastId(ptr)))
        res = 1;
    return res;
}

modules getModulesRecord(int id) {
    printf("Enter record\n");
    modules rec;
    rec.id = id;
    printf("name:\n");
    getname(rec.name);
    printf("level:\n");
    while (1) {
        if (scanf("%d", &(rec.level)) != 1)
            printf("n/a\n");
        else 
            break;
    }
    printf("cell:\n");
    while (1) {
        if (scanf("%d", &(rec.cell)) != 1)
            printf("n/a\n");
        else 
            break;
    }
    printf("flag:\n");
    while (1) {
        if (scanf("%d", &(rec.flag)) != 1)
            printf("n/a\n");
        else 
            break;
    }
    return rec;
}

int addModulesRecord(FILE* ptr, modules rec) {  // ADD
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, 0, SEEK_END);
        fwrite(&rec, sizeof(modules), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}

int deleteModulesRecord(FILE* ptr, int id) {  // DELETE
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        modules rec;
        int i = id;
        fseek(ptr, (i+1) * sizeof(modules), SEEK_SET);
        while (!feof(ptr)) {
            fseek(ptr, (i+1) * sizeof(modules), SEEK_SET);
            if (fread(&rec, sizeof(modules), 1, ptr) != 1)
                break;
            fseek(ptr, i * sizeof(modules), SEEK_SET);
            rec.id--;
            fwrite(&rec, sizeof(modules), 1, ptr);
            i++;
        }
        fseek(ptr, 0, SEEK_SET);
        truncate(modules_fpath, i * sizeof(modules));
    }
    return is_error;
}

int insertModulesRecord(FILE* ptr, int id, modules new_rec) {  //INSERT
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        modules rec;
        int i;
        fseek(ptr, -sizeof(modules), SEEK_END);
        fread(&i, sizeof(int), 1, ptr);
        while (i >= id) {
            fseek(ptr, i * sizeof(modules), SEEK_SET);
            fread(&rec, sizeof(modules), 1, ptr);
            fseek(ptr, (i + 1) * sizeof(modules), SEEK_SET);
            rec.id++;
            fwrite(&rec, sizeof(modules), 1, ptr);
            i--;
        }
        fseek(ptr, (i+1) * sizeof(modules), SEEK_SET);
        fwrite(&new_rec, sizeof(modules), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}

int changeModulesRecord(FILE* ptr, int id, modules rec) {  // CHANGE
    int is_error = 0;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fseek(ptr, id * sizeof(modules), SEEK_SET);
        printf("wa kak zapishu\n");
        printf("%d \"%s\" %d %d %d\n", rec.id, rec.name, rec.level, rec.cell, rec.flag);
        fwrite(&rec, sizeof(modules), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return is_error;
}
