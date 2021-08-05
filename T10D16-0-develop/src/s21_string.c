static char* old;


int s21_strlen(char* str) {
    int size = 0;
    while (*str != '\0') {
        size++;
        str++;
    }
    return size;
}

int s21_strcmp(char* str1, char* str2) {
    int flag = 0;
    while (1) {
        if (*str1 > *str2) {
            flag = *str1;
            break;
        }
        if (*str1 < *str2) {
            flag = -(*str2);
            break;
        }
        if ((*str1 == *str2) && (*str1 == '\0'))
            break;
        str1++;
        str2++;
    }
    return flag;
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

char* s21_strchr(char* str, char sym) {
    char* ptr = 0;
    while (*str != '\0') {
        if (*str == sym)
        ptr = str;
        str++;
    }
    return ptr;
}

char* s21_strstr(char* str1, char* str2) {
    char* ptr = 0;
    while (*str1 != '\0') {
        char* tmp = str1;
        char* tmp2 = str2;
        while (*tmp == *tmp2) {
            tmp++;
            tmp2++;
            if (*tmp2 == '\0')
                ptr = str1;
        }
        str1++;
    }
    return ptr;
}

char* s21_strtok(char* str, char* delim) {
    char* token;
    if (str == 0) {
        str = old;
    }
    if (str == 0)
        return 0;
    token = str;
    int flag = 1;
    while ((*str != '\0') && (flag)) {
        char* tmp = delim;
        while (*tmp != '\0') {
            if (*str == *tmp) {
                *str = '\0';
                flag = 0;
                break;
            }
            tmp++;
        }
        str++;
    }
    if (flag == 0)
        old  = str;
    else
        old = 0;
    return token;
}
