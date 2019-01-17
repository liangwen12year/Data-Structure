#include <stdlib.h>
#include <stdio.h>

void buble_sort(int a[], int size);
void buble_sort_improved(int a[], int size);
void selection_sort(int a[], int size);
void insertion_sort_with_sentinel(int a[], int size);
int find_index(int a[], int size, int start_index);
void insertion_sort(int a[], int size);
void insertion_sort_with_sentinel_shift(int a[], int size);
void shell_sort(int a[], int size);
void quick_sort(int a[], int size);

void swap(int* a, int* b);

int main(int argc, char* argv[]) {
	int i;
	int number[] = { 5,3,4,1,2 };
	for (i = 0; i < 5; i++) {
		printf("%d\n", number[i]);
	}
	printf("-----\n");
	//buble_sort_improved(number, 5);
	//insertion_sort_with_sentinel_shift(number, 5);
	//shell_sort(number, 5);
	quick_sort(number, 5);
	for (i = 0; i < 5; i++) {
		printf("%d\n", number[i]);
	}
	return 0;
}
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void buble_sort(int a[], int size) {
	//start in the beginning of the list
	//compare first pair, if out order
	//yes, swap
	//move through lst 
	//repeat
	int n;
	int i;
	for (n = 0; n < size - 1; n++) {
		for (i = 0; i < size - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(&a[i], &a[i + 1]); //swap(a+1,a+i+1)
			}
		}
	}

}
void buble_sort_improved(int a[], int size) {
	int n;
	int i;
	int is_swapped = 1;
	for (n = 0; n < size - 1 && is_swapped; i++) {
		is_swapped = 0;
		for (i = 0; i < size - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(&a[i], &a[i + 1]);
				is_swapped = 1;
			}
		}
	}
}
void selection_sort(int a[], int size) {
	int i;
	int index_smallest;
	for (i = 0; i < size - 1; i++) {
		index_smallest = find_index(a, size, i);
		swap(&a[i], &a[index_smallest]);
	}
}
int find_index(int a[], int size, int start_index) {
	int i;
	int index_min = start_index;
	for (i = start_index; i < size; i++) {
		if (a[i] < a[index_min]) {
			index_min = i;
		}
	}
	return index_min;
}
void insertion_sort(int a[], int size) {
	int i;
	int j;

	for (i = 0; i < size; i++) {
		j = i;
		while (j - 1 >= 0 && a[j] < a[j - 1]) {
			swap(&a[j - 1], &a[j]);
			j--;
		}
	}

}
void insertion_sort_with_sentinel(int a[], int size) {
	int i;
	int j;
	swap(&a[0], &a[find_index(a, size, 0)]);
	for (i = 1; i < size; i++) {
		j = i;
		while (a[j] < a[j - 1]) {
			swap(&a[j - 1], &a[j]);
			j--;
		}
	}
}
void insertion_sort_with_sentinel_shift(int a[], int size) {
	int i;
	int j;
	int temp;
	swap(&a[0], &a[find_index(a, size, 0)]);
	for (i = 1; i < size; i++) {
		j = i;
		temp = a[j];
		while (a[j] < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
			a[j] = temp;
		}

	}
}
void shell_sort(int a[], int size) {
	int i, j, h;
	h = size / 3 + 1;
	do {
		h--;
		for (i = h; i < size; i++) {
			j = i;
			while (j - h >= 0 && a[j] < a[j - 1]) {
				swap(&a[j - 1], &a[j]);
				j--;
			}
		}

	} while (h != 1);

}
void quick_sort(int a[], int size) {
	//pivot is the left most element
	//put everything smaller than the pivot on the left of the pivot
	//everything greater than the pivot on the right
	//quick_sort on unsorted list
	int* left;
	int* right;
	int* pivot;
	pivot = &a[0];
	left = a;
	right = a + size - 1;
	if (size < 2) {
		return;
	}
	while (left < right) {
		//move right
		while (right > left &&*right > *pivot) {
			right--;
		}
		//move the left
		while (left < right&& *left <= *pivot) {
			left++;
		}
		if (left != right)
			swap(left, right);
	}
	swap(pivot, left);
	quick_sort(a, left - a);
	quick_sort(&a[left - a + 1], &a[size - 1] - right);
}