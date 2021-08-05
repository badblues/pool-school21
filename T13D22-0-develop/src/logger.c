#include "log_levels.h"
#include "cipher.h"


FILE* log_init(char* path) {
    FILE* ptr = fopen(path, "a+");
    if (ptr == NULL)
        return NULL;
    return ptr;
}

void logcat(FILE* ptr, char* message, enum log_level level) {
    if (ptr == NULL)
        printf("pizdec\n");
    switch (level) {
        case 0:
            fprintf(ptr, "DEBUG ");
            break;
        case 1:
            fprintf(ptr, "TRACE ");
            break;
        case 2:
            fprintf(ptr, "INFO ");
            break;
        case 3:
            fprintf(ptr, "WARNING ");
            break;
        case 4:
            fprintf(ptr, "ERROR ");
            break;
    }

    time_t raw;
    struct tm* timeinfo = (struct tm*)malloc(sizeof(struct tm));
    time(&raw);
    timeinfo = localtime_r(&raw, timeinfo);
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    fprintf(ptr, "%d:%d:%d ", hour, min, sec);

    fprintf(ptr, "%s\n", message);
}

void log_close(FILE* ptr) {
    fclose(ptr);
}

char* createMes(char* path, int mode) {
    char* mes;
    switch (mode) {
        case 1:
            mes = (char*)malloc(sizeof(char) * (10 + strlen(path)));
            s21_strcpy(mes, "read from ");
            s21_strcat(mes, path);
            break;
        case 2:
            mes = (char*)malloc(sizeof(char) * (14 + strlen(path)));
            s21_strcpy(mes, "added line to ");
            s21_strcat(mes, path);
            break;
        case 3:
            mes = (char*)malloc(sizeof(char) * (20 + strlen(path)));
            s21_strcpy(mes, "encrypted directory ");
            s21_strcat(mes, path);
            break;
    }
    return mes;
}
