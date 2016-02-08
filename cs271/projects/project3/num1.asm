	; Name:				Isaac Stallcup
	; Creation date: 	Jan 30, 2015
	; Last modified: 	16:02 Jan 30, 2015
	;
	; 
	; Name of file: num1.asm
	; Description: print the numbers '98765' in a counted loop
		
	; Assemble:	nasm -f elf -l num1.lst  num1.asm
	; Link:		gcc -m32 -o num1 num1.o
	; Run:		./num1
	; Output:	the number sequence '98765'

	; Equivalent C code
	;
	;;#include <stdio.h>
	;
	;int main()
	;{
	;	int displayed = 9;
	;	
	;	int ecx;
	;	
	;	for (ecx=5; ecx > 0; ecx--)
	;	{
	;		printf("%d", displayed);
	;		displayed--;
	;	}
	;	
	;	printf("\n");
	;	
	;	return 0;
	;}

	extern	printf		
	extern 	scanf
	
SECTION .data				

show:			db "%d", 0

break:			db " ", 10

displayed:		db 9

SECTION .bss				



SECTION .text				

	global main				

	main:	
	
		push	ebp
		mov		ebp,esp

		mov ecx, 5
		
.loop:
		
		push ecx
		
		push dword [displayed]
		push dword show
		call printf
		add esp, 8
		
		mov eax, [displayed]
		dec eax
		mov [displayed], eax
		
		pop ecx

		loop .loop
		
.post_loop:

		push dword break
		call printf
		add esp, 4
		
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	
		
		