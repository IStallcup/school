	; Name: Isaac Stallcup
	; Creation date: Jan 20, 2015
	; Last modified: 20:53 Jan 23, 2015
	;
	; 
	; Name of file: CS271_proj2_stallcui.asm
	; Description: get 2 integers from the user, display their
	;				sum, difference, product, integer quotient and remainder
	; Assemble:	nasm -f elf CS271_proj2_stallcui.lst  CS271_proj2_stallcui.asm
	; Link:		gcc -m32 -o CS271_proj2_stallcui  CS271_proj2_stallcui.o
	; Run:		./CS271_proj2_stallcui
	; Output:	Sum:[value] Difference[value] Product:[value] Quotient:[value] Remainder:[value]
	;
	;Equivalent C Code:
	;
	;#include <stdio.h>
	;
	;int main()
	;{
	;	signed int* integer1 = malloc(sizeof(*integer1));
	;	
	;	signed int* integer2 = malloc(sizeof(*integer2));
	;	
	;	signed int* sum = malloc(sizeof(*sum));
	;	
	;	signed int* dif = malloc(sizeof(*dif));
	;	
	;	signed int* pro = malloc(sizeof(*pro));	
	;	
	;	signed int* quo = malloc(sizeof(*quo));	
	;	
	;	signed int* rem = malloc(sizeof(*rem));	
	;	
	;	printf("Name:		Isaac Stallcup\n");
	;	
	;	printf("Program:	CS271_proj2_stallcui.asm\n");
	;	
	;	printf("Please input two integers:\n");
	;	
	;	scanf("%d %d", integer1, integer2);
	;	
	;	printf("Integers: %d %d\n", *integer1, *integer2);
	;	
	;	*sum = *integer1 + *integer2;
	;	
	;	*dif = *integer1 - *integer2;
	;	
	;	*pro = *integer1 * *integer2;
	;		
	;	*quo = *integer1 / *integer2;
	;
	;	*rem = *integer1 - (*quo * *integer2);
	;	
	;	printf("Sum:%d Difference:%d Product:%d Quotient:%d Remainder:%d\n", *sum, *dif, *pro, *quo, *rem);
	;	
	;	printf("Goodbye.\n");
	;	
	;	return 0;
	;}

	;declare external functions
	extern printf
	extern scanf
	
section .data

	;name
	myname:		db "Name:		Isaac Stallcup", 10, 0
	
	;program name
	myprog:		db "Program:	CS271_proj2_stallcui.asm", 10, 0
	
	;asks for input
	askin:		db "Please input two integers:", 10, 0
	
	;imput prompt formatting
	prompt:		db "%d %d", 0
	
	;shows input
	showint:	db "Integers: %d %d", 10, 0
	
	;shows result
	showres:	db "Sum:%d Difference:%d Product:%d Quotient:%d Remainder:%d", 10, 0
	
	;displays end message
	disend:		db "Goodbye.", 10, 0
	
section .bss
	
	;integer values
	integer1:	resd 1
	integer2:	resd 1
	
	;math values
	sum:	resd 1
	dif:	resd 1
	pro:	resd 1
	quo:	resd 1
	rem:	resd 1
	
section .text

	global main
	
	main:
		nop
		push ebp
		mov ebp, esp
		
		;print name
		
		push dword myname
		
		call printf
		
		add esp, 4 ;move stack pointer
		
		;print program name
		push dword myprog
		
		call printf
		
		add esp, 4
		
		;ask for inputs
		push dword askin
		
		call printf
		
		add esp, 4
		
		;get 2 inputs
		push dword integer2
		
		push dword integer1
		
		push dword prompt
		
		call scanf
		
		add esp, 12
		
		;confirm the inputs
		push dword [integer2]
		
		push dword [integer1]
		
		push dword showint
		
		call printf
		
		add esp, 12
		
		;sums the inputs
		mov eax, [integer1]
		;moves integer1 to eax
		add eax, [integer2]
		;adds integer2 to the accumulated
		;register (containing integer1),
		;stores it in eax
		mov [sum], eax
		;copies eax to the value of sum
		
		;gets integer1 - integer2
		mov eax, [integer1]
		;moves integer1 to eax
		sub eax, [integer2]
		;subtracts integer2 from the accumulated
		;register (containing integer1),
		;stores it in eax
		mov [dif], eax
		;copies eax to the value of dif
		
		
		mov eax, [integer1]
		;moves integer1 to eax
		mul dword [integer2]
		;multiplies integer2 and 
		;contents of the accumulated
		;register (containing integer1),
		;stores it in eax
		mov [pro], eax
		;copies eax to the value of pro
		
		mov eax, [integer1]
		;moves integer1 to eax
		div dword [integer2]
		;divides accumulated value by integer2
		;[integer division], stores remainder in
		;edx and stores result in eax
		mov [quo], eax
		;copies eax to value of quo
		mov [rem], edx
		;copies edx to value of rem
		
		;prepare values to be output
		push dword [rem]
		
		push dword [quo]
		
		push dword [pro]
		
		push dword [dif]
		
		push dword [sum]
		
		push dword showres
		
		call printf
		;prints out values formatted correctly
		add esp, 20
		
		
		push dword disend
		;displays end message
		call printf
		
		add esp, 4
		
		
		mov esp, ebp
		
		pop ebp
		
		mov eax, 0
		
		ret