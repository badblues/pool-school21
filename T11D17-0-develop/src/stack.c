#include <stdlib.h>

#include "stack.h"

struct elem* init(int val) {
    struct elem* head = (struct elem*)malloc(sizeof(struct elem));
    head->val = val;
    head->next = NULL;
    return head;
}

void push(struct elem** head, int val) {
    struct elem* tmp = (struct elem*)malloc(sizeof(struct elem));
    tmp->val = val;
    tmp->next = *head;
    *head = tmp;
}

int pop(struct elem** head) {
    struct elem* tmp = *head;
    int value = (*head)->val;
    *head = (*head)->next;
    free(tmp);
    return value;
}

void destroy(struct elem** head) {
    struct elem* tmp = *head;
    while (*head != NULL) {
        free(tmp);
        *head = (*head)->next;
        tmp = *head;
    }
}
