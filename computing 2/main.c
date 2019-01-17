/************************************************
		Author:< Wen Liang >
		Date: <09/12/2017>
		Effort: < 0.5h >
		Purpose: < learn to use left shift operator and familiar with the use of for-loop
*************************************************/








#include <stdio.h>

main()
{
unsigned int x=1;
int i;

for(i=0;x!=0;i++)
	{
	x=x<<1;
	printf("%d:%u\n",i,x);
	}
}