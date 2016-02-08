
	; Name:				Isaac Stallcup
	; Creation date: 	Jan 20 2015
	; Last modified: 	12:05 Jan 22 2015
	;
	; 
	; Name of file: project2.asm
	; Description: 	displays programmer name, program title to the user,
	;				then display instructions to the user to enter two integers.
	;				program then calculates their sum, difference, product and
	;				integer quotient/remainder. The program then terminates.
		
	; Assemble:	nasm -f elf -l template.lst  template.asm
	; Link:		gcc -m32 -o template  template.o
	; Run:		./template
	; Output:	a=5, eax=7

	; Equivalent C code
	; #include <stdio.h>
	; #include <stdlib.h>
	; #include <math.h>
	; 
	; void intro()
	; {
	; 	printf("Name:\t\tIsaac Stallcup\n");
	; 	
	; 	printf("Program:\tCalcuator.c\n");
	; }
	; 
	; void get_data(signed int* input)
	; {
	; 	printf("Enter integer:\n");
	; 	
	; 	scanf("%d", input);
	; }
	; 
	; void do_math(signed int* input1, signed int* input2)
	; {
	; 	int sum = *input1 + *input2;
	; 	
	; 	printf("Sum:\t\t\t%d\n", sum);
	; 	
	; 	int diff = *input1 - *input2;
	; 	
	; 	printf("Difference:\t\t%d\n", diff);
	; 	
	; 	int prod = *input1 * *input2;
	; 	
	; 	printf("Product:\t\t%d\n", prod);
	; 	
	; 	int quot = *input1 / *input2;
	; 	
	; 	printf("Quotient:\t\t%d\n", quot);
	; 	
	;	int rem = *input1 - (quot * *input2);
	; 	
	; 	printf("Remainder:\t\t%d\n", rem);
	; }
	; 
	; void end()
	; {
	; 	printf("Goodbye.\n");
	; }
	; 
	; int main()
	; {
	; 	intro();
	; 	
	; 	signed int* input1 = malloc(sizeof(*input1));
	; 	
	; 	signed int* input2 = malloc(sizeof(*input2));
	; 	
	; 	do{
	; 	
	; 		unsigned int qcon = 0;
	; 		
	; 		get_data(input1);
	; 	
	; 		get_data(input2);
	; 	
	; 		do_math(input1, input2);
	; 		
	; 		printf("Run again?\n");
	; 		
	; 		scanf("%u", qcon);
	; 		
	; 	
	; 	} while (qcon == 1);
	; 	
	; 	end();
	; 	
	; 	return 0;
	; }

	; Declare needed external functions
	;
	
	extern	printf			; the C function, to be called
	
SECTION .data				; Data section, initialized variables

prompt1 db "Hello World", 0

SECTION .bss				; BSS, uninitialized variables
	
SECTION .text				; Code section.

	global main				; the standard gcc entry point

	main:					; the program label for the entry point
		push	ebp			; set up stack frame
		mov		ebp,esp
	
		mov		eax, prompt1
	
	
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op

		mov		eax,0		; normal, no error, return value
		ret					; return
	