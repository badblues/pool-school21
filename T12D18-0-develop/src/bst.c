#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree* tmp = (t_btree*)malloc(sizeof(t_btree));
    tmp->val = item;
    tmp->left = NULL;
    tmp->left = NULL;
    return tmp;
}

int compare(int x, int y) {
    if (x >= y)
        return 1;
    if (x < y)
        return -1;
    return 0;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    int cmp = cmpf(root->val, item);
    if (cmp == 1) {
        if (root->left == NULL) {
            t_btree *tmp = bstree_create_node(item);
            root->left = tmp;
        } else {
            bstree_insert(root->left, item, cmpf);
        }
    }
    if (cmp == -1) {
        if (root->right == NULL) {
            t_btree *tmp = bstree_create_node(item);
            root->right = tmp;
        } else {
            bstree_insert(root->right, item, cmpf);
        }
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root->left != NULL)
        bstree_apply_infix(root->left, applyf);
    applyf(root->val);
    if (root->right != NULL)
        bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    applyf(root->val);
    if (root->left != NULL)
        bstree_apply_prefix(root->left, applyf);
    if (root->right != NULL)
        bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root->right != NULL)
        bstree_apply_postfix(root->right, applyf);
    applyf(root->val);
    if (root->left != NULL)
        bstree_apply_postfix(root->left, applyf);
}

void printNode(int val) {
    printf("%d ", val);
}
