#ifndef SRC_BST_H_
#define SRC_BST_H_

typedef struct tree t_btree;

struct tree {
    int val;
    t_btree* left;
    t_btree* right;
};

t_btree *bstree_create_node(int item);
int compare(int a, int b);
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
void printNode(int val);

#endif  // SRC_BST_H_
