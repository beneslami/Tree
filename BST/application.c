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

	inorder_traversal(tree);
	del(tree, (void*)11);
	inorder_traversal(tree);
	flush(tree);
	return 0;
}
