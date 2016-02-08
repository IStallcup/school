	; Name:				Isaac Stallcup
	; Creation date: 	Jan 27, 2015
	; Last modified: 	7:35 Jan 27, 2015
	;
	; 
	; Name of file: fib1.asm
	; Description: print an integer from storage and from a register
		
	; Assemble:	nasm -f elf -l fib1.lst  fib1.asm
	; Link:		gcc -m32 -o fib1 fib1.o
	; Run:		./fib1
	; Output:	an input number Fibonacci terms

	; Equivalent C code
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

	extern	printf		
	extern 	scanf
	
SECTION .data				

name:		db "Name:		Isaac Stallcup", 10, 0

title:		db "Program:	fib1.asm", 10, 0

pr_name:	db "What is your name?", 10, 0

name_get:	db "%s", 0

pr_num1:	db "How many numbers in the Fibonacci sequence would you like?", 10, 0

pr_num2:	db "*Please enter a number between 1 and 46, inclusive*", 10, 0

num_in:		db "%u", 0

bye1:		db 10, "Goodbye, ", 0

bye2:		db ".", 10, 0

show_fibs:	db "Showing first %u Fibonacci numbers.", 10, 0

fib_num:	db "%u: ", 0

fib_res:	db "%u     ", 0

line_br:	db 10



SECTION .bss				

name_in:	resd 2

num:		resd 1

fib_a:		resd 1

fib_b:		resd 1

fib_c:		resd 1

incv:		resd 1

SECTION .text				

	global main				

	main:					
		push	ebp
		mov		ebp,esp
		
.introduction:
		push dword name
		call printf
		add esp, 4
		
		push dword title
		call printf
		add esp, 4
		
		push dword pr_name
		call printf
		add esp, 4
		
		push dword name_in
		push dword name_get
		call scanf
		add esp, 8

.user_instructions:
		push dword pr_num1
		call printf
		add esp, 4
		
		push dword pr_num2
		call printf
		add esp, 4
		
.get_user_data:
		push dword num
		push dword num_in
		call scanf
		add esp, 8
		
		mov eax, [num]
		sub eax, 46
		cmp eax, 0
		jg .user_instructions
		
		mov eax, [num]
		add eax, 0
		cmp eax, 0
		jle .user_instructions
		
.display_fibs_intro:
		push dword [num]
		push dword show_fibs
		call printf
		add esp, 8

		mov eax, 0								
		mov [fib_b], eax
		
		mov eax, 1								
		mov [fib_c], eax
		
		mov ecx, [num]

.display_fibs:
		
		push ecx
		
		mov ebx, [fib_b]
		mov edx, [fib_c]
		mov [fib_c], ebx
		add ebx, edx
		mov [fib_a], ebx
		
		push dword [fib_a]
		push dword fib_res
		call printf
		add esp, 8
		
		mov [fib_b], ebx
		
		pop ecx
		
		loop .display_fibs
		
.farewell:
		push dword bye1
		call printf
		add esp, 4

		push dword name_in
		call printf
		add esp, 4
		
		push dword bye2
		call printf
		add esp, 4
		
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	
	