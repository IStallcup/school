	; Name:				Isaac Stallcup
	; Creation date: 	Feb 6, 2015
	; Last modified: 	2:43 Feb 7, 2015
	;
	; 
	; Name of file: as4.asm
	; Description: 
		
	; Assemble:	nasm -f elf -l as4.lst  as4.asm
	; Link:		gcc -m32 -o as4 as4.o
	; Run:		./as4
	; Output:	

	; Equivalent C code

	extern	printf		
	extern 	scanf
	
SECTION .data				

get_input:		db "Input string: ", 0

string:			db "%s", 0

show_input:		db "Your input string was %s.", 10, 0

SECTION .bss				

string_in:		resd 1

SECTION .text				

	global main				

	main:					
		push	ebp
		mov		ebp,esp

		push dword get_input
		call printf;
		add esp, 4
		
		push dword string_in
		push dword string
		call scanf
		add esp, 8
		
		
		
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	
	