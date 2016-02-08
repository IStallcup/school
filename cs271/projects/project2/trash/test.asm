section .text
	global _start
	
_start:
	mov edx, len_myname
	
	mov ecx, myname
	
	mov ebx, 1
	
	mov eax, 4
	
	int 0x80
	
	mov edx, len_progtitle
	
	mov ecx, progtitle
	
	mov ebx, 1
	
	mov eax, 4
	
	int 0x80
	
	mov eax, 1
	
	int 0x80
	
section .data

	myname db 'Name:		Isaac Stallcup', 0xa	
	len_myname equ $ - myname
	
	progtitle db 'Title:		project2.asm', 0xa
	len_progtitle equ $ - myname