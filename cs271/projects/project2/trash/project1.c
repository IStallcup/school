#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intro()
{
	printf("Name:\t\tIsaac Stallcup\n");
	
	printf("Program:\tCalcuator.c\n");
}

void get_data(signed int* input)
{
	printf("Enter integer:\n");
	
	scanf("%d", input);
}

void do_math(signed int* input1, signed int* input2)
{
	int sum = *input1 + *input2;
	
	printf("Sum:\t\t\t%d\n", sum);
	
	int diff = *input1 - *input2;
	
	printf("Difference:\t\t%d\n", diff);
	
	int prod = *input1 * *input2;
	
	printf("Product:\t\t%d\n", prod);
	
	int quot = *input1 / *input2;
	
	printf("Quotient:\t\t%d\n", quot);
	
	int rem = *input1 - (quot * *input2);
	
	printf("Remainder:\t\t%d\n", rem);
}

void end()
{
	printf("Goodbye.\n");
}

int main()
{
	intro();
	
	signed int* input1 = malloc(sizeof(*input1));
	
	signed int* input2 = malloc(sizeof(*input2));
	
	do{
	
		int qcon == 0;
		
		get_data(input1);
	
		get_data(input2);
	
		do_math(input1, input2);
		
		printf("Run again?\n");
	
	} while (qcon == 1);
	
	end();
	
	return 0;
}