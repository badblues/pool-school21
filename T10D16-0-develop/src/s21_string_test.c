#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
    #ifdef Quest_1
       s21_strlen_test();
    #endif
    #ifdef Quest_2
       s21_strcmp_test();
    #endif
    #ifdef Quest_3
       s21_strcpy_test();
    #endif
    #ifdef Quest_4
       s21_strcat_test();
    #endif
    #ifdef Quest_5
       s21_strchr_test();
    #endif
    #ifdef Quest_6
       s21_strstr_test();
    #endif
    #ifdef Quest_7
       s21_strtok_test();
    #endif
}

void s21_strlen_test() {
    printf("STRLEN TEST\n");
    char str1[30] = "kekekekkekek";
    char str2[30] = "qwertyuiop[]asdfghjkl;'";
    char str3[30] = "";
    char str4[50] = "12345678910qwerasdfgzxcvbgtfredbtg";
    char* arr[4] = {str1, str2, str3, str4};
    int sizes[4] = {12, 23, 0, 34};
    for (int i = 0; i < 4; i++) {
        if (s21_strlen(arr[i]) == sizes[i])
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    printf("STRCMP TEST\n");
    char str1[30] = "odin";
    char str2[30] = "odin";
    char str3[30] = "bolwe";
    char str4[30] = "desyat'";
    if (s21_strcmp(str1, str2) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (s21_strcmp(str1, str3) > 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (s21_strcmp(str4, str3) > 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (s21_strcmp(str3, str4) < 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (s21_strcmp(str3, str2) < 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcpy_test() {
    printf("STRCPY TEST\n");
    char str1[30] = "";
    char str2[30] = "odin";
    char str3[30] = "bolwe";
    char str4[30] = "desyat'";
    char str5[30] = "";
    s21_strcpy(str1, str2);
    if (s21_strcmp(str2, str1) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcpy(str3, str1);
    if (s21_strcmp(str3, str1) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcpy(str4, str5);
    if (s21_strcmp(str4, str5) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcpy(str5, str1);
    if (s21_strcmp(str1, str5) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcat_test() {
    printf("STRCAT TEST\n");
    char str1[30] = "";
    char str2[30] = "odin";
    char str3[30] = "bolwe";
    char str4[30] = "odinbolwe";
    char str5[30] = "odinbolweodinbolwe";
    char str6[30] = "odinbolweodinbolwe";
    s21_strcat(str1, str2);
    if (s21_strcmp(str2, str1) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcat(str1, str3);
    if (s21_strcmp(str1, str4) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcat(str4, str1);
    if (s21_strcmp(str4, str5) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcat(str5, "");
    if (s21_strcmp(str5, str6) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");    
}

void s21_strchr_test() {
    printf("STRCHR TEST\n");
    char str1[30] = "1234567890";
    char str2[30] = "Hello, World!";
    char str3[30] = "Aboba";
    char str4[30] = "";
    if (s21_strchr(str1, '9') - str1 == 8)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    if (s21_strchr(str2, 'W') - str2 == 7)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    if (s21_strchr(str3, 'c') - str3 < 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (s21_strchr(str4, 'c')  == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");    
}

void s21_strstr_test() {
    printf("STRSTR TEST\n");
    char str1[30] = "1234567890";
    char str2[30] = "Hello, World!";
    char str3[30] = "Aboba";
    char str4[30] = "";
    if (s21_strstr(str1, "234") - str1 == 1)
       printf("SUCCESS\n");
    else
          printf("FAIL\n");

    if (s21_strstr(str2, "World") - str2 == 7)
       printf("SUCCESS\n");
    else
          printf("FAIL\n");

    if (s21_strstr(str3, "biba") - str3 < 0)
       printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (s21_strstr(str4, "biba") == 0)
       printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strtok_test() {
    printf("STRTOK TEST\n");
    char str1[30] = "PROGRAM WORKS-CORRECTLY";
    char* res;
    res = s21_strtok(str1, " -");
    if (s21_strcmp(res, "PROGRAM") == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    res = s21_strtok(NULL, " -");
    if (s21_strcmp(res, "WORKS") == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    res = s21_strtok(NULL, " -");
    if (s21_strcmp(res, "CORRECTLY") == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    res = s21_strtok(NULL, " -");
    if (res == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
