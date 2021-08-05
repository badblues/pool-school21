#include "cipher.h"
#include "logger.h"

int findFiles(char* str) {
    int res = 0;
    int i = strlen(str);
    if (i >= 2) {
        if ((str[i-1] == 'c') && (str[i-2] == '.'))
            res = 1;
        if ((str[i-1] == 'h') && (str[i-2] == '.'))
            res = 2;
    }
    return res;
}

char* getFullPath(char* dir, char* filename) {
    char* res = (char*)malloc(sizeof(char) * (strlen(dir) + strlen(filename) + 1));
    s21_strcpy(res, dir);
    s21_strcat(res, "/");
    s21_strcat(res, filename);
    return res;
}

void cleanFile(char* path) {
    FILE* ptr = fopen(path, "w");
    fclose(ptr);
}

void caesarsCipher(char* path, int shift) {
    FILE* ptr = fopen(path, "r+");
    char c = fgetc(ptr);
    while (c != -1) {
        fseek(ptr, -1, SEEK_CUR);
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
            fputc((c + shift) % 255, ptr);
        else
            fputc(c, ptr);
        c = fgetc(ptr);
    }
    fclose(ptr);
}

int codeCaesars(char* path) {
    int is_error = 0;
    int shift;
    if (scanf("%d", &shift) != 1)
        is_error = 1;
    DIR* dir = opendir(path);
    if (dir == NULL)
        is_error = 1;
    if (is_error == 0) {
        struct dirent* cur;
        while ((cur = readdir(dir)) != 0) {
            int var = findFiles(cur->d_name);
            if (var == 1) {
                char* filepath = getFullPath(path, cur->d_name);
                caesarsCipher(filepath, shift);
                free(filepath);
            }
            if (var == 2) {
                char* filepath = getFullPath(path, cur->d_name);
                cleanFile(filepath);
                free(filepath);
            }
        }
        free(path);
        closedir(dir);
    }
    return is_error;
}
