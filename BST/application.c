#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

node_t *tree;

int main(){
	tree = init();
	add(tree, (void*)40);
	add(tree, (void*)10);
	add(tree, (void*)30);
	add(tree, (void*)25);
	add(tree, (void*)50);
	add(tree, (void*)11);
	add(tree, (void*)76);

	preorder_traversal(tree);
	printf("\n");
	del(tree, (void*)30);
	preorder_traversal(tree);
	printf("\n");
	//deinit(tree->root);
	return 0;
}
