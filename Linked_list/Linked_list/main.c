#include <stdio.h>
#include <stdlib.h>

//forward declaration
struct node;
typedef struct node Node;
struct node {
	int data;
	Node* next;
};

void head_insert(Node** pHead, int item);
void print_list(Node* head);
void tail_inset_recursive(Node** pHead, int item);
void destroy(Node** pHead);

int main(int argc, char* argv[]) {
	Node* head = NULL;
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		printf("no memory allocated\n");
		exit(1);
	}
	temp->data = 1;
	temp->next = head;
	head = temp;
	head_insert(&head, 2);  //head=head_insert(head, 2);
	head_insert(&head, 3);
	tail_inset_recursive(&head, 4);
	tail_inset_recursive(&head, 5);
	tail_inset_recursive(&head, 6);
	print_list(head);
	destroy(&head);
	if (head == NULL) {
		printf("head is %d\n", head);
		printf("Success!\n");
	}
	return 0;
}

void head_insert(Node** pHead, int item) {  // Node* head_insert(Node* head, int item)
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		printf("no memory allocated\n");
		exit(1);
	}
	temp->data = item;
	temp->next = *pHead;
	*pHead = temp;
	//printf("in insert %d\n", (*pHead)->data);
}

void tail_inset_recursive(Node** pHead, int item) {
	if ((*pHead) == NULL) {
		*pHead = (Node*)malloc(sizeof(Node));
		if ((*pHead) == NULL) {
			printf("No space was allocated\n");
			exit(1);
		}
		(*pHead)->data = item;
		(*pHead)->next = NULL;
	}
	else
		tail_inset_recursive(&(*pHead)->next, item);
}

void print_list(Node* head) {
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

void destroy(Node** pHead) {
	Node* temp;
	temp = *pHead;
	while (temp != NULL) {
		//printf("head is %d\n", *pHead);
		*pHead = temp->next;
		free(temp);
		temp = *pHead;
	}
	//printf("head is %d\n", *pHead);
}