	extern printf
	extern scanf

SECTION .data

	fmt:    db "Got %d and %d as input!", 10, 0
	
	input:	db "%d %d",0			 ; the scanf format

SECTION .bss				; BSS, uninitialized variables
	int1:	resd 1
	int2:	resd 1
	sum:	resd 1
	
SECTION .text				; Code section.

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

		mov eax, [int1]
		mov ebx, [int2]
		add eax, ebx
		mov [sum], eax
		
		push dword sum
		push dword [sum]
		push dword fmt
		call printf
		add esp, 12
		
		mov esp, ebp	; takedown stack frame
		pop ebp			; same as "leave" op

		mov eax,0		; normal, no error, return value
		ret					; return