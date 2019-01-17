#include <stdio.h>

struct node;
typedef struct node Node;
struct node {
	int data;
	Node* left;
	Node* right;
};

void tree_insert(Node** pRoot, int item);
void preorder_traversal(Node* root);
void inorder_traversal(Node* root);
void postorder_traversal(Node* root);
void tree_destroy(Node** pRoot);

int main(int argc, char* argv[]) {
	Node* root = NULL;
	tree_insert(&root, 42);
	tree_insert(&root, 7);
	tree_insert(&root, -3);
	tree_insert(&root, 39);
	tree_insert(&root, 1);
	tree_insert(&root, 23);
	tree_insert(&root, 0);
	preorder_traversal(root);
	tree_destroy(&root);
	return 0;
}
void tree_insert(Node** pRoot, int item) {
	if (*pRoot == NULL) {
		*pRoot = (Node*)malloc(sizeof(Node));
		if (*pRoot == NULL)
			exit(1);
		(*pRoot)->data = item;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
	}
	else {
		if (item < (*pRoot)->data) {
			tree_insert(&(*pRoot)->left, item);
		}
		else
			tree_insert(&(*pRoot)->right, item);
	}
}
void preorder_traversal(Node* root) {
	if (root != NULL) {
		printf("%d\n", root->data);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}

}

void tree_destroy(Node** pRoot) {
	if (*pRoot != NULL) {
		tree_destroy(&(*pRoot)->left);
		tree_destroy(&(*pRoot)->right);
		printf("destroy: %d\n", (*pRoot)->data);
		free(*pRoot);
		*pRoot = NULL;
	}
}