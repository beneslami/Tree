#ifndef BST_H
#define BST_H

/*
TODO list:
1- implement all of functions for integer data
   1.1- implement del
   1.2- implement inorder traversal
   1.3- implement flush
   1.4- implement preorder traversal
   1.5- implement postorder traversal
   1.6- implement find_min
   1.7- implement find_max
2- change structures and modify it as opaque pointers
3- change entire header file to a generic tree
   3.1- voiding data
   3.2- implement allback function for add
   3.3- implement allback function for del
   3.4- implement allback function for find_min
   3.5- implement allback function for find_max
4- try to create static and dynamic library
*/
typedef struct node_{
	void *data;
	struct node_ *left;
	struct node_ *right;
	struct node_ *parent;
	
}node_t;

typedef struct tree_{
	node_t *root;
}tree_t;

tree_t *init();
int add(tree_t*, void*);
int del(tree_t*, void*);
void flush(tree_t*);
void *find_min(tree_t*);
void *find_max(tree_t*);
void preorder_traversal(tree_t*);
void inorder_traversal(tree_t*);
void postorder_traversal(tree_t*);

#endif