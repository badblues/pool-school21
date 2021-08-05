#include "state_sort.h"

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

int getDate(int* date) {
    int is_error = 0;
    char* str = getStr();
    int len = strlen(str);
    date[0] = 0;    date[1] = 0;    date[2] = 0;
    for (int i = 2; i >= 0; i--) {
        while (*str) {
            if (((*str >= '0') && (*str <= '9')) || (*str == '.')) {
                if (*str == '.') {
                    str++;
                    break;
                }
            date[i] *= 10;
            date[i] += *str - '0';
            } else {
                is_error = 1;
            }
            str++;
        }
    }
    free(str - len);
    return is_error;
}
