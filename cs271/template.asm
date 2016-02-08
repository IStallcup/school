	; Name:				Isaac Stallcup
	; Creation date: 	Jan 27, 2015
	; Last modified: 	7:35 Jan 27, 2015
	;
	; 
	; Name of file: FILENAME.asm
	; Description: print an integer from storage and from a register
		
	; Assemble:	nasm -f elf -l FILENAME.lst  FILENAME.asm
	; Link:		gcc -m32 -o FILENAME FILENAME.o
	; Run:		./FILENAME
	; Output:	

	; Equivalent C code

	extern	printf		
	extern 	scanf
	
SECTION .data				



SECTION .bss				



SECTION .text				

	global main				

	main:					
		push	ebp
		mov		ebp,esp

		
		
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	
	