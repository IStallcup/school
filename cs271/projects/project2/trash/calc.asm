	extern printf
	extern scanf

	
section .data

	myname:		db "Name:			Isaac Stallcup", 10, 0	;name
	len_myname: equ $ - myname 
	
	myprog:		db "Program:		calc.asm", 10, 0		;program name
	len_myprog:	equ $ - myprog
	
	prompt:		db "Input an integer: ", 0
	len_prompt:	equ $ - prompt
	
	dsum:		db "The sum is ", 0
	len_dsum:	equ $ - dsum
	
	conf:		db "The input is ", 0
	len_conf:	equ $ - conf
	
section .bss
	
	input1:		resd 3
	len_input1:	equ $ - input1
	
	input2:		resd 3
	len_input2:	equ $ - input2
	
	oper:		resd 3
	len_oper:	equ $ - oper
	

section .text

	global main
	
	main:
		
		;displays name
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, myname
		
		mov edx, len_myname
		
		int 80H
		
		;displays program name
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, myprog
		
		mov edx, len_myprog
		
		int 80H
		
		;asks for input1
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, prompt
		
		mov edx, len_prompt
		
		int 80H
		
		;gets an input1
		mov eax, 3
		
		mov ebx, 0
		
		mov ecx, input1
		
		
		mov edx, len_input1
		
		int 80H
		
		;confirms input1
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, conf
		
		mov edx, len_conf
		
		int 80H
		
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, input1
		
		mov edx, len_input1
		
		int 80H
		
		;asks for input2
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, prompt
		
		mov edx, len_prompt
		
		int 80H
		
		
		;gets an input2
		mov eax, 3
		
		mov ebx, 0
		
		mov ecx, input2
		
		mov edx, len_input2
		
		int 80H
		
		;confirms input2
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, conf
		
		mov edx, len_conf
		
		int 80H
		
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, input2
		
		mov edx, len_input2
		
		int 80H
		
		;sum
		mov eax, [input1]
		
		mov ebx, [input2]
		
		ADD eax, ebx
		
		mov [oper], eax
		
		;display
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, dsum
		
		mov edx, len_dsum
		
		int 80H
		
		;value
		mov eax, 4
		
		mov ebx, 1
		
		mov ecx, oper
		
		int 80H
		
		ret
		