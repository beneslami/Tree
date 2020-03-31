#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

node_t *tree;

int main(){
	tree = init();
	add(tree, (void*)40);
	add(tree, (void*)10);
	add(tree, (void*)50);
	add(tree, (void*)8);
	add(tree, (void*)35);
	add(tree, (void*)43);
	add(tree, (void*)76);
	add(tree, (void*)7);
	add(tree, (void*)30);
	add(tree, (void*)41);
	add(tree, (void*)45);
	add(tree, (void*)73);
	add(tree, (void*)77);
	add(tree, (void*)11);
	add(tree, (void*)33);
	add(tree, (void*)20);
	add(tree, (void*)78);

	inorder_traversal(tree);
	printf("\n");
	del(tree, (void*)30);
	inorder_traversal(tree);
	printf("\n");
	//deinit(tree->root);
	return 0;
}
