#include <stdio.h>

#include "bst.h"

void bst_insert_test();

int main() {
    bst_insert_test();
}

void bst_insert_test() {
    t_btree* tmp1 = bstree_create_node(45);
    printf("Creating new node with value 45\n");
    printf("tmp1.val = %d\n", tmp1->val);
    if (tmp1->val == 45)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    bstree_insert(tmp1, 12, compare);
    printf("New node must be on the left side with value 12\n");
    printf("tmp1->left->val = %d\n", tmp1->left->val);
    if (tmp1->left->val == 12)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    bstree_insert(tmp1, 6, compare);
    printf("New node must be on the left left side with value 6\n");
    printf("tmp1->left->left->val = %d\n", tmp1->left->left->val);
    if (tmp1->left->left->val == 6)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    bstree_insert(tmp1, 50, compare);
    printf("New node must be on the right side with value 50\n");
    printf("tmp1->right->val = %d\n", tmp1->right->val);
    if (tmp1->right->val == 50)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
