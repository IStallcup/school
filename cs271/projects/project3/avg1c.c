	;#include <stdio.h>
	;
	;int main()
	;{
	;	printf("Name:		Isaac Stallcup\n")	;
	;	printf("Program:	avg1.asm\n")	;
	;	printf("What is your name?\n")	;
	;	
	;	char *name	;
	;	name = (char *)malloc(sizeof(char))	;
	;	scanf("%s", &name)	;
	;	
	;	int num_temp, num = 0, counter = 0	;
	;	
	;	printf("Hello, %s.\n", &name)	;
	;	
	;	printf("Please enter integers you wish to average.\n")	;
	;	
	;	printf("*Negative numbers will end the averaging process and display the average.*\n")	;
	;	
	;	printf("-*Input numbers between 0 and 100.*-\n")	;
	;	
	;	int x	;
	;	
	;	for (x = 2	; x > 0	; x--)
	;	{
	;		printf("Enter an integer:	")	;
	;		scanf("%d", &num_temp)	;
	;		
	;		if (num_temp < 0)
	;		{
	;			break	;
	;		}
	;		
	;		while (num_temp >= 101)
	;		{
	;			printf("-*Input numbers between 0 and 100.*-\n")	;
	;			printf("Enter an integer:	")	;
	;			scanf("%d", &num_temp)	;
	;		}
	;		
	;		num += num_temp	;
	;		
	;		counter++	;
	;		
	;		x++	;
	;	}
	;	
	;	printf("Negative detected.\nAveraging...\n")	;
	;	
	;	printf("Numbers found:\t\t\t%d\n", counter)	;
	;	
	;	if (counter == 0)
	;		return 0	;
	;
	;	printf("Sum of %d numbers:\t\t%d\n", counter, num)	;
	;	
	;	num /= counter	;
	;	
	;	printf("Average:\t\t\t%u\n", num)	;
	;	
	;	printf("Goodbye, %s", &name)	;
	;	
	;	printf(".\n")	;
	;	
	;	return 0	;
	;	
	;}