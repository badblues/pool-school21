#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct poly {
    int deg;
    int coef;
    struct poly* next;
};

char* getStr();
struct poly* init(int coef, int deg);
void push(struct poly** head, int coef, int deg);
int getNumber(char** str);
struct poly* getPolynom(char* str);
int calculate(struct poly* head, int x);
void destroy(struct poly** head);

int main() {
    struct poly* head;
    int x = 3;
    char* str = getStr();
    head = getPolynom(str);
    int res = calculate(head, x);
    destroy(&head);
    printf("%d", res);
    return 0;
}

char* getStr() {
    char* str = (char*)malloc(sizeof(char) * 10);
    int size = 0, k = 1;
    char c = ' ';
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
    return str;
}

struct poly* init(int coef, int deg) {
    struct poly* head = (struct poly*)malloc(sizeof(struct poly));
    head->deg = deg;
    head->coef = coef;
    head->next = NULL;
    return head;
}

void push(struct poly** head, int coef, int deg) {
    struct poly* tmp = (struct poly*)malloc(sizeof(struct poly));
    tmp->deg = deg;
    tmp->coef = coef;
    tmp->next = *head;
    *head = tmp;
}

void destroy(struct poly** head) {
    struct poly* tmp = *head;
    while (*head != NULL) {
        free(tmp);
        *head = (*head)->next;
        tmp = *head;
    }
}

int getNumber(char** str) {
    int num = 0;
    int empt_flag = 1;
    int neg_flag = 0;
    if (**str == '-') {
        neg_flag = 1;
        (*str)++;
    }
    while ((**str >= '0') && (**str <= '9')) {
        empt_flag = 0;
        num *= 10;
        num += **str - '0';
        (*str)++;
    }
    if (empt_flag)
        num = 1;
    if (neg_flag)
        num = -num;
    return num;
}

struct poly* getPolynom(char* str) {
    int init_flag = 1;
    struct poly* head = NULL;
    while (*str != '\0') {
        int deg = 0, coef = 0;
        if (*str == '+')
            str++;
        coef = getNumber(&str);
        if (*str == '*')
            str++;
        if (*str == 'x') {
            str++;
            if (*str == '^')
                str++;
            deg = getNumber(&str);
        } else {
            deg = 0;
        }
        if (init_flag) {
            head = init(coef, deg);
            init_flag = 0;
        } else {
            push(&head, coef, deg);
        }
    }
    return head;
}

int calculate(struct poly* head, int x) {
    int sum = 0;
    for (struct poly* p = head; p!= NULL; p = p->next)
        sum += pow(x, p->deg) * p->coef;
    return sum;
}
