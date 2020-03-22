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
	if(node->left != NULL && node->right != NULL){ //first node
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

node_t *del(node_t *node){   // incomplete

	if(node->left != NULL && node->right != NULL){ // node has two children
		node_t *temp = min_value(node->right);
		node->data = temp->data;
		node->right = del(node->right);

	}
	else if(node->left != NULL){ //node has only left child
		node_t *temp = node->right;
		free(node);
		return temp;
	}
	else if(node->right != NULL){ //node has only right child
		node_t *temp = node->right;
		free(node);
		return temp;
	}
	else{ //node has no children
		free(node);
	}
	return node;
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
	if(root->left != NULL){
		root = root->left;
		deinit(root);
	}
	if(root->right != NULL){
		root = root->right;
		deinit(root);
	}
	free(root);
}
