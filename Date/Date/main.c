#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(int argc, char* agrv[]) {
	DATE today = NULL;
	today = date_init_default();
	if (data_set_month(today, 9) == FAILURE) {
		printf("cannot set month\n");
		exit(1);
	}
	out_date(today);
	//int* p = NULL;
	//p = (int*)malloc(sizeof(int));
	//if (p == NULL) {
	//	//print error message
	//	exit(1);
	//}
	//*p = 66;
	//free(p);
	//p = NULL;
	date_destroy(&today);
	return 0;
}