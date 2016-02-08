	extern printf
	extern scanf
	
section .data

	prompt:		db "Input two integers:", 10, 0
	
	input:		db "%d %d", 0
	
section .bss

	a:			resd 1
	b:			resd 1

section .text

	global main
	
	main:
	
		nop
		
		push ebp
		
		mov ebp, esp
		
		push dword prompt
		
		call printf
		
		add esp, 4
		
		
		
		mov esp, ebp
		
		pop ebp
		
		mov eax, 0
		
		ret