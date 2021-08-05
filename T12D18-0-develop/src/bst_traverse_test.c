#include <stdio.h>

#include "bst.h"

void bst_traverse_test();

int main() {
    bst_traverse_test();
}

void bst_traverse_test() {
    t_btree* tmp1 = bstree_create_node(45);
    bstree_insert(tmp1, 12, compare);
    bstree_insert(tmp1, 6, compare);
    bstree_insert(tmp1, 50, compare);
    printf("func must print: <6 12 45 50>\n");
    bstree_apply_infix(tmp1, printNode);
    printf("\nfunc must print <45 12 6 50>\n");
    bstree_apply_prefix(tmp1, printNode);
    printf("\nfunc must print <50 45 12 6>\n");
    bstree_apply_postfix(tmp1, printNode);
}
