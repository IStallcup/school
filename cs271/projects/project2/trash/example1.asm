
	; Name: D. Kevin McGrath
	; Creation date: 16 January 2015
	; Last modified: 09:09 16 January 2015
	;
	; 
	; Name of file: example1.asm
	; Description: First example file, with basic I/O
		
	; Assemble:	nasm -f elf -l example.lst  example1.asm
	; Link:		gcc -o example1  example1.o
	; Run:		example1
	; Output:	something

	; Equivalent C code
	; /* printf1.c  print an int and an expression */
	; #include <stdio.h>
	; int main()
	; {
	;   printf("Hello world!\n");
	;   return 0;
	; }

	; Declare needed external functions
	;
	extern printf			; the C function, to be called
	extern scanf			; C input function

section .data				; Data section, initialized variables
	fmt:    db "Got %d and %d as input!", 10, 0 ; The printf format, "\n",'0'
	input:	db "%d %d",0			 ; the scanf format

section .bss				; BSS, uninitialized variables
	int1:	resd 1
	int2:	resd 1
		
section .text				; Code section.

	global main				; the standard gcc entry point

	main:					; the program label for the entry point
		push ebp			; set up stack frame
		
		mov ebp,esp

		push dword int2
		
		push dword int1
		
		push dword input
		
		call scanf
		
		add esp, 12

		
		push dword [int2]
		
		push dword [int1]
		
		push dword fmt
		
		call printf
		
		add esp, 12

		
		mov esp, ebp	; takedown stack frame
		
		pop ebp			; same as "leave" op

		mov eax,0		; normal, no error, return value
		
		ret					; return
	
	
	
	
	
	
	
	