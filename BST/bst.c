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

int del(tree_t *tree, void *data){
	node_t *node = tree->root;
	if(node == NULL){
		return -1;
	}

	if(data > node->data){//compare with root
		node = node->right;
		while(node){
			if(data > node->data){
				node = node->right;
			}
			else if(data < node->data){
				node = node->left;
			}
			else if(data == node->data){
				if(node->left == NULL && node->right == NULL){
					free(node);
					return 1;
				}
				else if(node->left == NULL || node->right == NULL){
					node_t *temp;
					if(node->left == NULL){
						temp = node->right;
						temp->parent = node->parent;
						free(node);
						return 1;
					}
					else if(node->right == NULL){
						temp = node->left;
						temp->parent = node->parent;
						free(node);
						return 1;
					}
				}
			}
		}
		printf("Data Not found\n");
		return -1;}
	else if(data < node->data){ //compare with root
		node = node->left;
		while(node){
			if(data > node->data){
				node = node->right;
			}
			else if(data < node->data){
				node = node->left;
			}
			else if(data == node->data){
				if(node->left == NULL && node->right == NULL){
					node = NULL;
					free(node);
					return 1;
				}
				else if(node->left == NULL || node->right == NULL){
					node_t *temp;
					if(node->left == NULL){
						temp = node->right;
						temp->parent = node->parent;
						free(node);
						return 1;
					}
					else if(node->right == NULL){
						temp = node->left;
						temp->parent = node->parent;
						free(node);
						return 1;
					}
				}
			}
		}
		printf("Data Not found\n");
		return -1;
	}
	else if(node->left == NULL && node->right == NULL){ //root has no children
		free(node);
		return 1;
	}
	else if(node->left == NULL || node->right == NULL){ //root has one child
		node_t *temp;
		if(node->left == NULL){
			temp = node->right;
			temp->parent = node->parent;
			free(node);
			return 1;
		}
		else if(node->right == NULL){
			temp = node->left;
			temp->parent = node->parent;
			free(node);
			return 1;
		}

	}
	else{
		printf("Something very strange happened\n");
		return -1;
	}
	return -1;
}

void inorder_traversal(node_t *root){
	/*node_t *node = tree->root;
	 node_t *current, *pre;

    if (node == NULL){
        return;
    }

    current = node;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", (int)current->data);
            current = current->right;
        }
        else {
            pre = current->left;
            while (pre->right != NULL && pre->right != current){
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            else {
                pre->right = NULL;
                printf("%d ", (int)current->data);
                current = current->right;
            }
        }
    }*/
		if(root->left != NULL){
			inorder_traversal(root->left);
		}
    printf("%d ", (int)root->data);
		if(root->right != NULL){
			inorder_traversal(root->right);
		}
}

void flush(tree_t *tree){

}
