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
UB: dd 100 	;variable UB for upper bound
LB: dd 0 	; variable LB for lower bound
print1:		db	"Hello and Welcome to Richard Sala's CS271 Assignment3 part 2 program (Honestly not really sure what to call it.) Please enter your name.", 10, 0
input1:		db "%s", 0
print2:		db  "Hello %s. This program will allow you to enter non negative integers that are less than 100. Then it will count and display the number of non negative integers entered, and the average. Just enter a negative number to end the input sequence. " , 10, 0
input2:		db "%d", 0
print3:		db "That number is too large, please do less than 100.", 10, 0
print4:		db "Input stage is over. Here are your values. Number of non negative integers: %d Sum of values: %d", 10, 0
print5:		db "The average value is: %d", 10, 0
print6: db "Sorry no input. Good bye %s", 10 , 0
print7: db "count is: %d", 10, 0



SECTION .bss				; BSS, uninitialized variables
		
	name1: 	resd 1		; this creates all variables as double words, initialized to 0
	input: resd 1
	average: resd 1
	sum: resd 1
	counter: resd 1
	
SECTION .text
	global main				; the standard gcc entry point

	main:					; the program label for the entry point
		push	ebp			; set up stack frame
		mov		ebp,esp

	;first print statement aka greeting
	push dword print1 	;pushes print statement
	call printf 	; calls c function
	add esp, 4 		;adds 4 because 1 push

	;first scan function aka username
	push dword name1 	;name variable
	push dword input1	;
	call scanf
	add esp, 8

	;second print statement aka instructions
	push dword name1 	;pushes their name into print statment
	push dword print2 	;prints second statement
	call printf 
	add esp, 8	;adds 8 because 2 pushes
	jmp .input 	;jumps to input function

	;input function for value
	.input:

	push dword input 	;variable named input aka the number that the user wants to use
	push dword input2 	;prepares for scanf
	call scanf 			;calls c function
	add esp, 8  		;adds 8 because 2 pushes

	mov eax, [input] 	;moves input value into eax
	cmp eax, [LB] 		;compares to lower bound
	jl .printpt1 		;jumps to print1 aka result print if eax (input) is less than lower bound (0)

	cmp eax, [UB] 		;compares eax and upper bound
	jge .greater 		;jumps to greater function if its greater than 100 which prints out a message 

	cmp eax, [UB]		;compares eax and upper bound
	jle .add 			;jumps to the add function which is a loop if its less than or equal to 100

	;function adds to counter and adds sum
	.add:

	add dword [sum], eax 	;adds sum and eax
	inc dword [counter] 	;increases the counter
	jmp .input 				;jumps to the input to create a loop

	;first results being printed
	.printpt1:
	push dword [name1] 			;pushes usernam
	push dword [sum]			;pushes sum value
	push dword [counter]		;pushes counter value
	push dword print4			;pushes print statement
	call printf 				;calls c function
	add esp, 16 				;adds 16 because 4 pushes
	jmp .avgcalc 				;jumps to average calculator

	;function to calculate average
	.avgcalc: 
	cmp dword [counter], 0 		;compares counter to 0 to see if it needs to output special message
	je .special 				;jumps to special

	mov al, byte [sum] 			;moves sum to al and its byte not dword
	xor ah,ah 					;bitwise function
	mov cl, [counter]			;moves counter to cl 
	div cl 						;divides
	mov byte [average], al 		;moves al to average
	jmp .printpt2				;jumps to next print

	;prints average
	.printpt2:
	push dword [average] 		;pushes average dword not byte though
	push dword print5 			;pushes print statement
	call printf 				;calls c function
	add esp, 8 					;adds 8 because 2 pushes
	jmp .end 					;jumps to end function

	;special function if user inputs just a negative number
	.special:
	push dword name1 			;pushes username
	push print6 				;prints out message
	call printf 				;calls c function
	add esp, 8 					;adds 8 because 2 pushes
	jmp .end 					;jumps to end

	;greater function used if user inputs value over 100, ends program to prevent bad sum calculation
	.greater:
	push print3 				;pushes print statement
	call printf 				;calls c function
	add esp, 4 					;adds 4 because 1 push
	jmp .end 					;jumps to end



	.end:

	mov		esp, ebp	; takedown stack frame
	pop		ebp			; same as "leave" op

	mov		eax,0		; normal, no error, return value
	ret					; return