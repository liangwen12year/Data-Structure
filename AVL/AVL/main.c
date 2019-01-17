#include <stdio.h>
#include <stdlib.h>
struct node;
typedef struct node Node;
struct node {
	int data;
	Node* left;
	Node* right;
	int balance_factor;
};

int insert(Node** pRoot, int item);
Node* check_balance(Node** pRoot);
Node* rotate_left_right(Node** pRoot);
void inorder_traversal(Node* root);

int main(int argc, char argv[]) {
	Node* root = NULL;
	int taller;
	taller = insert(&root, 42);
	taller = insert(&root, 21);
	taller = insert(&root, 33);
	inorder_traversal(root);
	if (taller) {
		check_balance(&root);
	}
	inorder_traversal(root);
	return 0;
}
int insert(Node** pRoot, int item) {
	int old_balance_factor;
	if (*pRoot == NULL) {
		*pRoot = (Node*)malloc(sizeof(Node));
		if (*pRoot == NULL) {
			exit(1);
		}
		(*pRoot)->data = item;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		(*pRoot)->balance_factor = 0;
	}
	else {
		old_balance_factor = (*pRoot)->balance_factor;
		if (item < (*pRoot)->data) {
			if (insert(&(*pRoot)->left, item)) {
				(*pRoot)->balance_factor++;
				if ((*pRoot)->balance_factor > old_balance_factor)
					return 1;
				else
					return 0;
			}
		}
		if (item > (*pRoot)->data) {
			if (insert(&(*pRoot)->right, item)) {
				(*pRoot)->balance_factor--;
				if ((*pRoot)->balance_factor < old_balance_factor)
					return 1;
				else
					return 0;
			}
		}
	}
	return 1;
}
Node* check_balance(Node** pRoot) {
	if ((*pRoot)->balance_factor == 2) { // left heavy
		if (((*pRoot)->left)->balance_factor == 1) { //left heavy
													 //need to rotate right
		}
		else {//need left-right rotation
			rotate_left_right(&(*pRoot));
		}
	}
}
Node* rotate_left_right(Node** pRoot) {
	Node* temp_root = *pRoot;
	Node* temp_right = ((*pRoot)->left)->right;
	Node* temp_left = (*pRoot)->left;
	//rotate left child
	temp_root->left = temp_right;
	(temp_left)->right = NULL;
	(temp_right)->left = temp_left;
	temp_left->balance_factor++;
	//rotate right on parent (*pRoot)
	*pRoot = temp_right;
	temp_right->right = temp_root;
	(temp_right->right)->left = NULL;
	(temp_right->right)->balance_factor = 0;
}
void inorder_traversal(Node* root) {
	if (root != NULL) {
		inorder_traversal(root->left);
		printf("data=%d balance factor=%d\n", root->data, root->balance_factor);
		inorder_traversal(root->right);
	}
}