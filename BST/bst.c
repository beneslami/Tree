#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

node_t *before;

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
		printf("%d -> %p\n",(int)node->data, node);
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
		printf("%d -> %p\n", (int)node->data, node);
		return 1;
	}
	else if(type == 'r'){
		node_t *node = calloc(1, sizeof(node_t));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		prev->right = node;
		printf("%d -> %p\n", (int)node->data, node);
		return 1;
	}
	return -1;
}

int del(node_t *node, void* data){

	if(data < node->data){
		before = node;
		del(node->left, data);
	}

	else if(data > node->data){
		before = node;
		del(node->right, data);
	}

	else if (data == node->data){
		if(node->left == NULL && node->right == NULL){   // leaf node
			free(node);
			return 0;
		}

		else if(node->left != NULL && node->right == NULL) {       //node has only left child
			if(before->right == node){
				before->right = node->left;
				free(node);
				return 0;
			}
			else if(before->left == node){
				before->left = node->left;
				free(node);
				return 0;
			}
		}

		else if(node->right != NULL && node->left == NULL){        //node has only right child
			if(before->left == node){
				before->left = node->right;
				free(node);
				return 0;
			}
			else if(before->right == node){
				before->right = node->right;
				free(node);
				return 0;
			}
		}

		else if(node->left != NULL && node->right != NULL){        // node has two children
			node_t *temp = min_value(node->right);
			if(before->left == node){
					temp->left = node->left;
					before->left = temp;
					free(node);
					return 0;
			}
			else if(before->right == node){
					temp->left = node->left;
					before->right = temp;
					free(node);
					return 0;
			}
		}
	}
	else{
		printf("data does not exist\n");
		return -1;
	}
	return -1;
}

void preorder_traversal(node_t *root){

	printf("%d ", (int)root->data);
	if(root->left != NULL){
		preorder_traversal(root->left);
	}
	if(root->right != NULL){
		preorder_traversal(root->right);
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
		postorder_traversal(root->left);
	}
	if(root->right != NULL){
		postorder_traversal(root->right);
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
