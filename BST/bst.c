#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

tree_t *init(){
	tree_t *tree = calloc(1, sizeof(tree_t));
	node_t *node = calloc(1, sizeof(node_t));
	node->left = NULL;
	node->right = NULL;
	node->data = NULL;
	tree->root = node;
	return tree;
}

int add(node_t *node, void *data){
	if(node->data == NULL){ //first time when there is only root node exists
		node->data = data;
		return 0;
	}
	node_t *prev = NULL, *ptr;
	ptr = node;
	char type;
	while(ptr){
			prev = ptr;
			if(data < ptr->data){
				ptr = ptr->left;
				type = 'l';
			}
			else if (data > ptr->data){
				ptr = ptr->right;
				type = 'r';
			}
	}
	if(type == 'l'){
		node_t *node = calloc(1, sizeof(node_t));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		prev->left = node;
		return 1;
	}
	else if(type == 'r'){
		node_t *node = calloc(1, sizeof(node_t));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		prev->right = node;
		return 1;
	}
	return -1;
}

int del(node_t *node){

	if(node->left == NULL && node->right == NULL){
		free(node);
	}

	else if(node->left != NULL){ //node has only left child
		node_t *temp = node;
		node = node->left;
		free(temp);
	}

	else if(node->right != NULL){ //node has only right child
		node_t *temp = node;
		node = node->right;
		free(temp);
	}

	else if(node->left != NULL && node->right != NULL){ // node has two children
		node_t *temp = min_value(node->right);
		node->data = temp->data;
		free(temp);
	}
	return 0;
}

void preorder_traversal(node_t *root){
	printf("%d ", (int)root->data);
	if(root->left != NULL){
		inorder_traversal(root->left);
	}
	if(root->right != NULL){
		inorder_traversal(root->right);
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

void postorder_traversal(node_t *root){
	if(root->left != NULL){
		inorder_traversal(root->left);
	}
	if(root->right != NULL){
		inorder_traversal(root->right);
	}
	printf("%d ", (int)root->data);
}

node_t *min_value(node_t *node){
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}

node_t *max_value(node_t *node){
	while(node->right != NULL){
		node = node->right;
	}
	return node;
}

node_t *find(node_t *node, void* data){
	if(node == NULL){
		return NULL;
	}
	while(1){
		if(data < node->data){
			node = node->left;
		}
		else if(data > node->data){
			node = node->right;
		}
		else if (data == node->data){
			return node;
		}
	}
}

void deinit(node_t *root){
	if(root == NULL) return;
	deinit(root->left);
	deinit(root->right);
	free(root);
	free(root);
}
