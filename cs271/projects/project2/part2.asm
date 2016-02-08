	; Name: Richard Sala
	; Creation date: 2/1/2015
	; Last modified: 2/2/2015
	;
	; 
	; Name of file: printf1.asm
	; Description: print an integer from storage and from a register
		
	; Assemble:	nasm -f elf -l template.lst  template.asm
	; Link:		gcc -m32 -o template  template.o
	; Run:		./template
	; Output:	a=5, eax=7

	; Equivalent C code
	;#include <stdio.h>
	;#include <stdlib.h>
	;int main()
	;{
	;char *name;
	;int input;
	;int cont=0;
	;int sum=0;
	;int average=0;
	;int counter=0;
	    ;name = (char *)malloc (sizeof(char));
	    ;printf("Hello and Welcome to Richard Sala's CS271 Assignment3 part 2 program. Please enter your name. ");
	    ;scanf("%s", &name);
	    ;printf("Hello %s. This program will allow you to enter non negative integers that are less than 100. \n Then it will count and display the number of non negative integers entered, and the average. \n Just enter a negative number to end the input sequence. \n");
	    ;do{
	    ;scanf("%d", &input);
	    ;if (input < 0 ){
	        ;cont = 1;
	        ;break;
	    ;}
	    ;if (input < 101){
	        ;counter++;
	        ;sum=sum+input;
	    ;}
	    ;else{
	        ;printf("That number is too large, please do less than 100.");
	    ;}
	    ;}while(cont == 0);
	    ;average= sum/counter;
	    ;printf("Input stage is over. Here are your values. Number of non negative integers: %d\n Sum of values: %d \n Average ;value: %d \n Thank you for using my program %s good bye now.", counter, sum, average, name);
	;return 0;
	;}
	; Declare needed external functions
	extern	printf			; the C function, to be called
	extern  scanf			; the C function, to be called


SECTION .data

;program identifiers
print1:		db	"Hello and Welcome to Richard Sala's CS271 Assignment3 part 2 program. Please enter your name.", 10, 0
input1:		db "%s", 0
print2:		db  "Hello %s. This program will allow you to enter non negative integers that are less than 100. Then it will count and display the number of non negative integers entered, and the average. Just enter a negative number to end the input sequence. " , 10, 0
input2:		db "%d", 0
print3:		db "That number is too large, please do less than 100.", 10, 0
print4:		db "Input stage is over. Here are your values. Number of non negative integers: %d Sum of values: %d Average value: %d Thank you for using my program %s good bye now.", 10, 0
print5: db "Sorry no input.", 10 , 0
print6: db "LB is: %d   UB is: %d", 10, 0
UB: db 100


SECTION .bss				; BSS, uninitialized variables
		
	name1: 	resd 1		; this creates all variables as double words, initialized to 0
	input: resd 1
	average: resd 1
	sum: resd 1
	counter: resd 1
	LB: resd 1
	
SECTION .text
	global main				; the standard gcc entry point

	main:					; the program label for the entry point
		push	ebp			; set up stack frame
		mov		ebp,esp

	push dword print1
	call printf
	add esp, 4

	push dword name1
	push dword input1
	call scanf
	add esp, 8

	push dword name1
	push dword print2
	call printf 
	add esp, 8
	jmp .input

	.input:

	push dword input
	push dword input2
	call scanf
	add esp, 8

	push dword [UB]
	push dword [LB]
	push dword print6
	call printf
	add esp, 12
	jmp .testloop

	.testloop:

	inc cx
	mov eax, [input]
	add eax, [sum]
	mov [sum], eax
	mov [counter], cx
	cmp eax, [LB]
	jl .avgcalc
	cmp eax, [UB]
	jge .greater
	cmp eax, [UB]
	jl .input




	.avgcalc: 
	mov eax, [sum]
	div dword [counter]
	mov [average], edx
	jmp .final

	.special:
	push print5
	call printf
	add esp, 4
	jmp .end

	.greater:
	push print3
	call printf
	add esp, 4
	jmp .end

	.final:
	push dword [counter]
	push dword [sum]
	;push dword [average]
	push dword print4
	call printf
	add esp, 12
	jmp .end

	.end:

	mov		esp, ebp	; takedown stack frame
	pop		ebp			; same as "leave" op

	mov		eax,0		; normal, no error, return value
	ret					; return