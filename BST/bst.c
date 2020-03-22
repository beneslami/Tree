#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

node_t *init(){

	node_t *node = calloc(1, sizeof(node_t));
	node->left = NULL;
	node->right = NULL;
	node->data = NULL;
	return node;
}

int add(node_t *node, void *data){
	if(node->data == NULL){ //first time when there is only root node exists
		node->data = data;
		printf("%d -> %p\n",node->data, node);
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
		printf("%d -> %p\n", node->data, node);
		return 1;
	}
	else if(type == 'r'){
		node_t *node = calloc(1, sizeof(node_t));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		prev->right = node;
		printf("%d -> %p\n", node->data, node);
		return 1;
	}
	return -1;
}

int del(node_t *node, void* data){

	while(1){
		if(data < node->data){
			node = node->left;
		}
		else if(data > node->data){
			node = node->right;
		}
		else if (data == node->data){
			if(node->left == NULL && node->right == NULL){
				printf("%p\n", node);
				free(node);
				break;
			}
			else if(node->left != NULL){ //node has only left child
				node->data = node->left->data;
				printf("%p\n", node->left);
				free(node->left);
				break;
			}
			else if(node->right != NULL){ //node has only right child
				node->data = node->right->data;
				printf("%p\n", node->right);
				free(node->right);
				break;
			}

			else if(node->left != NULL && node->right != NULL){ // node has two children
				node_t *temp = min_value(node->right);
				node->data = temp->data;
				printf("%p\n", temp);
				free(temp);
				break;
			}
		}
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
