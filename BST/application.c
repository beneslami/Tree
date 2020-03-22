#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

tree_t *tree;

int main(){
	tree = init();
	add(tree, (void*)40);
	add(tree, (void*)10);
	add(tree, (void*)30);
	add(tree, (void*)25);
	add(tree, (void*)50);
	add(tree, (void*)11);
	add(tree, (void*)76);

	postorder_traversal(tree->root);
	printf("\n");
	node_t *node = find(tree->root, (void*)50);
	node_t *temp = del(node);
	printf("%d\n", (int)temp->data);
	postorder_traversal(tree->root);
	printf("\n");
	deinit(tree->root);
	return 0;
}
