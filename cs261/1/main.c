/***************************
**	Name: Isaac Stallcup
**	Date: June 28, 2015
**	Program: prog
**	Function: Calculate recursively and/or iteratively
**		an input or default number of fibonacci numbers,
**		and write the sequence to an external file.
**		Additionally, read a sequence of numbers from a file
**		and display their sum.
**	Command Line Options:
**		-r: recursive 


***************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

enum Mode {
	TEST_RECURSIVE_FIBONACCI = 0,
	TEST_ITERATIVE_FIBONACCI,
	TEST_SUMMATION,
	TEST_ALL
};

/* global variables which we will use to control what gets tested, and how much */
enum Mode programMode = TEST_RECURSIVE_FIBONACCI;
int globalMaxFibonacciNumToCompute = 10;

/* forward declarations */
int fibonacciRecursive(int n);
int fibonacciIterative(int n);

void testRecursiveFibonacci(char* filename, int maxFibonacciNumToCompute);
void testIterativeFibonacci(char* filename, int maxFibonacciNumToCompute);
void testSummation(char* filename);

/* This function will process the command line arguments and bind the global variables
 * appropriately.  If something is amiss, it will print the usage of the program
 */
void parseArgs(int argc, char** argv)
{
	int i;
	
	if(argc < 2)
		return;
	for(i = 1; i < argc; ++i)
	{
		if(strcmp(argv[i],"-r") == 0)
			programMode = TEST_RECURSIVE_FIBONACCI;
		else if(strcmp(argv[i], "-i") == 0)
			programMode = TEST_ITERATIVE_FIBONACCI;
	
		else if(strcmp(argv[i], "-s") == 0)
			programMode = TEST_SUMMATION;
			
		else if(strcmp(argv[i], "-a") == 0)
			programMode = TEST_ALL;
			
		else if(strcmp(argv[i], "-n") == 0 && argc > i)
			globalMaxFibonacciNumToCompute = atoi(argv[++i]);
		else
		{
			printf("\tUsage: ./prog [-r] [-i] [-n INTEGER] [-s] [-a]\n");
			printf("\t-r => set the program to test recursive fibonacci\n");
			printf("\t-i => set the program to test iterative fibonacci\n");
			
			printf("\t-n => set the number of fibonacci numbers to compute, i.e. -n 40\n");
			printf("\t-s => set the program to test summation and file reading\n");
			printf("\t-a => set the program to test everything\n");
		}
	}
}

int main (int argc, char** argv) 
{
	clock_t before, after;
	
	parseArgs(argc, argv);

	/* test recursive fibonacci */
	if(programMode == TEST_RECURSIVE_FIBONACCI || programMode == TEST_ALL)
	{
		/* this call will get the number of clock ticks since the program launched */
		before = clock();
		testRecursiveFibonacci("recursive.txt", globalMaxFibonacciNumToCompute);
		after = clock();
		/* the difference of after and before gives us the time of the stuff in between */ 
		printf("recursive version done in %f seconds\n", (float)(after-before)/(float)CLOCKS_PER_SEC);
	}
	
	/* test the iterative version */
	if(programMode == TEST_ITERATIVE_FIBONACCI || programMode == TEST_ALL)
	{
		before = clock();
		testIterativeFibonacci("iterative.txt", globalMaxFibonacciNumToCompute);
		after = clock();
		printf("iterative version done in %f seconds\n", (float)(after-before)/(float)CLOCKS_PER_SEC);
	}
	
	/* test file reading and summation */
	if(programMode == TEST_SUMMATION || programMode == TEST_ALL)
	{
		testSummation("numbers.txt");
	}
	return 0;
}

/* This function computes fibonacci numbers
 * param	n		index of the number to be computed
 * pre		n>0
 * ret		the nth fibonacci number
 */
int fibonacciRecursive(int n)
{
	if (n == 1) /* fib2 = 1 */
		return 1;
	if (n == 0) /* fib1 = 1 */
		return 1;
	if (n < 0) /* fib0 = 0 */
		return 0;
	 /* else return the sum of previous two fib numbers */
	return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

/* This function should call the fibonacci function a number of times, and write the
 * results to the file.
 * param	filename						name of the file to be opened
 * param	maxFibonacciNumToCompute		index of the max number to be computed
 * pre		maxFibonacciNumToCompute>0
 * post		a file exists, with fibonacci numbers 1-Max written in it.
 */
void testRecursiveFibonacci(char* filename, int maxFibonacciNumToCompute)
{
	FILE* recfile = fopen(filename, "w");
	if (!recfile) /* if file cannot be opened */
	{
		printf("File creation failed.");
		exit(0);
	}
	
	int currentFib;
	for (currentFib = maxFibonacciNumToCompute - 1; currentFib >= 0; currentFib--)
	{
		/* loop one fewer times than there are numbers to compute */
		fprintf(recfile, "%d\r\n", fibonacciRecursive(currentFib));
	}
	fclose(recfile);
}

/* This function computes fibonacci numbers
 * param	n		index of the number to be computed
 * pre		n>0
 * ret		the nth fibonacci number
 */
int fibonacciIterative(int n)
{
	/*printf("Running fibonacciIterative with value %d\r\n", n);*/
	int result, i; /*variable for for loop, result variable */
	/* this will allocate an array of size n which you can fill in (position i - 1 should store the ith fibonacci number) */
	int* fibArray = (int*) malloc(n*sizeof(int));
	if(!fibArray)	
	{
		fprintf(stderr, "*****malloc failed in iterative");
		return -1;
	}
	
	if (n == 1 || n == 2) /* fib1, fib2 are both 1 so nothing needs to be added */
	{
		free(fibArray);
		return 1;
	}

	if (n != 1 && n != 2)
	{
		fibArray[0] = 1; /* set values for fib1, fib2 */
		fibArray[1] = 1;
		for (i = 2; i <	n; i++)
		{
			fibArray[i] = fibArray[i-1] + fibArray[i-2]; 
			/* populate fibArray with fibonacci numbers */
		}
	}
	
	result = fibArray[n-1]; /* we however only want the nth indexed number (n-1th element of array) */
	
	/* clean up the memory we allocated */
	free(fibArray);
	return result;
}

/* This function should call the fibonacci function a number of times, and write the
 * results to the file.
 * param	filename						name of the file to be opened
 * param	maxFibonacciNumToCompute		index of the max number to be computed
 * pre		maxFibonacciNumToCompute>0
 * post		a file exists, with fibonacci numbers 1-Max written in it.
 */
void testIterativeFibonacci(char* filename, int maxFibonacciNumToCompute)
{
	FILE* itfile = fopen(filename, "w");
	if (!itfile) /* exit if file cannot be opened */
	{
		printf("File creation failed.");
		exit(0);
	}
	
	int currentFib;
	/* Start with the highest fibonacci number instead of the lowest */
	for (currentFib = 1; currentFib < maxFibonacciNumToCompute + 1; currentFib++)
	{
		/* loop one fewer times than there are numbers to compute */
		fprintf(itfile, "%d\r\n", fibonacciIterative(currentFib));
	}
	fclose(itfile);
}

/* This function should open a file, and read newline separated numbers from it.
 * As it does this, it should compute their running sum, then print it.
 * param	filename						name of the file to be opened
 * pre		a file by the nme of filename is on the disk, containing newline separted #s
 */
void testSummation(char* filename)
{
	int sum = 0; /* holds sum */
	char string[8]; /* for reading in characters from file */
	
	FILE* sumfile = fopen(filename, "r");
	if (!sumfile) /* exit if file opening fails */
	{
		printf("File reading of file %s failed.\r\n", filename);
		exit(0);
	}
	
	while(!feof(sumfile))
	{
		sum = sum + atoi(fgets(string, 8, sumfile)); /* adds to sum the contents of the line */
	}
	
	printf("Sum of %s is %d.\r\n", filename, sum); /* prints sum of file */
}