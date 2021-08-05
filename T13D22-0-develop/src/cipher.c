#include "cipher.h"
#include "file_io.h"
#include "encode.h"
#include "logger.h"


int getChoice();
void menu(int mode);

int main() {
    #ifdef LOG
    menu(1);
    return 0;
    #endif
    #ifndef LOG
    menu(0);
    #endif
    return 0;
}

void menu(int mode) {
    int flag = 1;
    char* path;
    char* dirpath;
    FILE* logptr;
    if (mode) {    // LOGMODE
        char* logfile = getPath();
        logptr = log_init(logfile);
    }
    while (flag) {
        int is_error = 0;
        char err = 32;
        int choice = getChoice();
        switch (choice) {
            case -1:
                flag = 0;
                break;
            case 1:
                path = getPath();
                is_error = readFile(path);
                if (is_error == 0) {
                    if (mode) {      //  LOGMODE
                        char* mes = createMes(path, 1);
                        logcat(logptr, mes, 2);
                        free(mes);
                    }
                    printf("\n");
                }
                break;
            case 2:
                is_error = writeToFile(path);
                if (is_error == 0) {
                    if (mode) {      // LOGMODE
                        char* mes = createMes(path, 2);
                        logcat(logptr, mes, 2);
                        free(mes);
                        mes = createMes(path, 1);
                        logcat(logptr, mes, 2);
                        free(mes);
                    }
                    readFile(path);
                    printf("\n");
                }
                break;
            case 3:
                dirpath = getPath();
                is_error = codeCaesars(dirpath);
                if ((is_error == 0) && (mode)) {       // LOGMODE
                    char* mes = createMes(dirpath, 3);
                    logcat(logptr, mes, 2);
                    free(mes);
                }
                break;
            default:
                is_error = 1;
                while (err != '\n')
                    err = getchar();  // we need to catch last '\n' from console
                break;
        }
        if (is_error == 1) {
            printf("n/a\n");
        }
    }
    log_close(logptr);
}

int getChoice() {
    int num = 0;
    if (scanf("%d", &num) != 1)
        return -2;
    return num;
}

char* getStr() {
    char* str = (char*)malloc(sizeof(char) * 10);
    int size = 0, k = 1;
    char c = ' ';
    scanf("%c", &c);
    if (c == '\n')
        scanf("%c", &c);
    while (c != '\n') {
        if (size > k * 10) {
            k++;
            char* tmp = (char*)realloc(str, sizeof(char) * 10 * k);
            if (tmp != NULL)
                str = tmp;
            else
                return NULL;
        }
        str[size++] = c;
        scanf("%c", &c);
    }
    str[size] = '\0';
    return str;
}

char* s21_strcpy(char* str1, char* str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return str1;
}

char* s21_strcat(char* str1, char* str2) {
    while (*str1 != '\0')
        str1++;
     while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return str1;
}

char* getPath() {
    char* str = getStr();
    char* tmp = (char*)malloc(sizeof(char) * (strlen(str) + 3));
    tmp[0] = '.';   tmp[1] = '.';   tmp[2] = '/';   tmp[3] = '\0';
    s21_strcat(tmp, str);
    free(str);
    return tmp;
}
