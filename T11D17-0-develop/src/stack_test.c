#include <stdio.h>
#include "stack.h"

void test();

int main() {
    test();
}

void test() {
    struct elem* head = init(45);
    printf("INITIALIZING WITH VALUE 45\n");
    printf("head->val = %d\n", head->val);
    if (head->val == 45)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    push(&head, -123);
    printf("PUSHING VALUE -123\n");
    printf("head->val = %d\n", head->val);
    if (head->val == -123)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("POP MUST RETURN -123\n");

    int res = pop(&head);
    printf("pop = %d\n", res);
    if (res == -123)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("NOW HEAD MUST BE VALUE 45\n");
    printf("head->val = %d\n", head->val);
    if (head->val == 45)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destroy(&head);
}
