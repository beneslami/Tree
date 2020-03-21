#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

tree_t *init(){
	tree_t *tree = calloc(1, sizeof(tree_t));
	node_t *node = calloc(1, sizeof(node_t));
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->data = NULL;
	tree->root = node;
	return tree;
}

int add(tree_t *tree, void *data){
	node_t *node = tree->root;
	if(!node->data){
		node->data = data;
		return 0;
	}
	while(node){
		if(node->data > data){
			if(node->left){
				node = node->left;
			}
			else{
				node_t *item = calloc(1, sizeof(node_t));
				item->data = data;
				item->left = NULL;
				item->right = NULL;
				node->left = item;
				item->parent = node;
				return 0;
			}

		}
		else if(node->data < data){
			if(node->right){
				node = node->right;
			}
			else{
				node_t *item = calloc(1, sizeof(node_t));
				item->data = data;
				item->left = NULL;
				item->right = NULL;
				node->right = item;
				item->parent = node;
				return 0;
			}
		}
		else if(node->data == data){
			printf("data exist in the tree\n");
			return 0;
		}
	}
	return -1;
}

int del(node_t *node, void *data){   // incomplete

	if(node == NULL){
		return -1;
	}
	else if(data < node->data){
		del(node->left, data);
	}
	else if(data > node->data){
		del(node->right, data);
	}
	else{
		if(node->left != NULL && node->right != NULL){ // node has two children
			node_t *temp;
			temp = min_value(node->right);
			temp->parent = node->parent;
			temp->right = node->right;
			temp->left = node->left;
			free(node);
			return 0;
		}
		else if(node->left != NULL){ //node has only left child
			node_t *temp;
			temp = node->left;
			temp->parent = node->parent;
			free(node);
			return 0;
		}
		else if(node->right != NULL){ //node has only right child
			node_t *temp;
			temp = node->right;
			temp->parent = node->parent;
			free(node);
			return 0;
		}
		else{ //node has no children
			free(node);
			return 0;
		}
	}
}

void inorder_traversal(node_t *root) {
	if(root->left != NULL){
		inorder_traversal(root->left);
	}
  printf("%d ", (int)root->data);
	if(root->right != NULL){
		inorder_traversal(root->right);
	}
}

node_t *min_value(node_t *node){
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}
