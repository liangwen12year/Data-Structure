
#include "status.h"

typedef void* DATE;
//init to some valid state
DATE date_init_default(void);
//change day, month, year
//get date
//advance the date to the next time 
//find a difference between two dates
Status date_set_month(DATE hDate, int month);
void out_date(DATE hDate);

void date_destroy(DATE* phDate);