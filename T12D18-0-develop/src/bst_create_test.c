#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_create_test();

int main() {
    bst_create_test();
}

void bst_create_test() {
    t_btree* tmp1 = bstree_create_node(45);
    t_btree* tmp2 = bstree_create_node(0);
    t_btree* tmp3 = bstree_create_node(-123);
    printf("Creating new node with value 45\n");
    printf("tmp1.val = %d\n", tmp1->val);
    if (tmp1->val == 45)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(tmp1);

    printf("Creating new node with value 0\n");
    printf("tmp2.val = %d\n", tmp2->val);
    if (tmp2->val == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(tmp2);

    printf("Creating new node with value -123\n");
    printf("tmp3.val = %d\n", tmp3->val);
    if (tmp3->val == -123)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(tmp3);
}
