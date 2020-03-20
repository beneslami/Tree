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

/*struct node* del(struct node *root, int x) {
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}*/

void flush(tree_t *tree){

}



