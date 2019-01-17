#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int array[100] = { 1,2 };
	printf("%d\n",array[2]);
	printf("%d\n", array[4]);
	printf("%d", array[3]);

	return 0;
}