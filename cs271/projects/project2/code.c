#include <stdio.h>

int main()
{
	signed int* integer1 = malloc(sizeof(*integer1));
	
	signed int* integer2 = malloc(sizeof(*integer2));
	
	signed int* sum = malloc(sizeof(*sum));
	
	signed int* dif = malloc(sizeof(*dif));
	
	signed int* pro = malloc(sizeof(*pro));	
	
	signed int* quo = malloc(sizeof(*quo));	
	
	signed int* rem = malloc(sizeof(*rem));	
	
	printf("Name:		Isaac Stallcup\n");
	
	printf("Program:	acalc.asm\n");
	
	printf("Please input two integers:\n");
	
	scanf("%d %d", integer1, integer2);
	
	printf("Integers: %d %d\n", *integer1, *integer2);
	
	*sum = *integer1 + *integer2;
	
	*dif = *integer1 - *integer2;
	
	*pro = *integer1 * *integer2;
	
	*quo = *integer1 / *integer2;
	
	*rem = *integer1 - (*quo * *integer2);
	
	printf("Sum:%d Difference:%d Product:%d Quotient:%d Remainder:%d\n", *sum, *dif, *pro, *quo, *rem);
	
	printf("Goodbye.\n");
	
	return 0;
}