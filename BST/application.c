#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

tree_t *tree;

int main(){
	tree = init();
	add(tree->root, (void*)40);
	add(tree->root, (void*)10);
	add(tree->root, (void*)30);
	add(tree->root, (void*)25);
	add(tree->root, (void*)50);
	add(tree->root, (void*)11);
	add(tree->root, (void*)76);

	preorder_traversal(tree->root);
	printf("\n");
	node_t *node = find(tree->root, (void*)25);
	printf("%d\n", node->left->data);
	preorder_traversal(tree->root);
	printf("\n");
	//deinit(tree->root);
	return 0;
}
