#include <stdio.h>
#include "date.h"

struct date {
	int month;
	int day;
	int year;
};
typedef struct date Date;
DATE date_init_default(void)
{
	Date* pDate;
	pDate = (Date*)malloc(sizeof(Date));
	if (pDate != NULL)
	{
		pDate->month = 1;
		pDate->day = 1;
		pDate->year = 1970;
	}

	return pDate;
}

Status date_set_month(DATE hDate, int month)
{
	Date* pDate = (Date*)hDate;
	if (month < 1 || month>12)
	{
		return FAILURE;
	}
	pDate->month = month;
	return SUCCESS;
}
void out_date(DATE hDate)
{
	Date* pDate = (Date*)hDate;
	printf("%d/%d/%d\n", (*pDate).month, pDate->day, pDate->year);
}
void date_destroy(DATE* phDate)
{
	Date* pDate = (DATE*)*phDate;
	free(pDate);
	*phDate = NULL;
}
