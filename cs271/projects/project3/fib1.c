	;#include <stdio.h>
	;
	;int main()
	;{
	;	printf("Name:		Isaac Stallcup\n");
	;	
	;	printf("Program:	Fibonnaci.asm\n");
	;	
	;	int num = 0, fib_a, fib_b, fib_c;
	;	
	;	char *name;
	;	
	;	name = (char *)malloc(sizeof(char));
	;	
	;	printf("What is your name?\n");
	;	
	;	scanf("%s", &name);
	;	
	;	do
	;	{
	;		printf("How many numbers in the Fibonacci sequence would you like?\n");
	;		
	;		printf("*Please enter a number between 1 and 46, inclusive.\n");
	;		
	;		scanf("%u", &num);
	;		
	;	}while (num <= 0 || num > 46);
	;	
	;	printf("Showing first %u Fibonacci numbers.\n", num);
	;	
	;	fib_b = 0;
	;	
	;	fib_c = 1;
	;	
	;	int x;
	;	
	;	for (x = num; x > 0; x--)
	;	{
	;		fib_a = fib_b + fib_c;
	;		fib_c = fib_b;
	;		
	;		printf("%u     ", fib_a);
	;		
	;		fib_b = fib_a;
	;
	;	}
	;	
	;	printf("\nGoodbye, ");
	;	
	;	printf("%s", &name);
	;	
	;	printf(".\n");
	;	
	;	return 0;
	;}