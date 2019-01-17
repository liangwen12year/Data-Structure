

char* reverse(char* s) {

	char* head = s;
	char* tail = s;
	char container;
	while (*tail != '\0') {
		tail++;
	}
	tail--;

	while (head < tail) {
		container = *head;
		*head = *tail;
		*tail = container;
		head++;
		tail--;
	}

	return s;
}