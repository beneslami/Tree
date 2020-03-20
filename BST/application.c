#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

tree_t *tree;

int main(){
	tree = init();
	
	flush(tree);
	return 0;
}