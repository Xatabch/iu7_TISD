//apply tree
#ifndef __APPLYPRE_H__
#define __APPLYPRE_H__
void apply_pre(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg);
void print(struct tree_node *node, void *param);
#endif