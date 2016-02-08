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
	;
	;
	;
	;
	;
	;
	;
	;
	;
	;

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
		
.display_fibs_intro:
		push dword [num]
		push dword show_fibs
		call printf
		add esp, 8
		
.set_init_fibs:
;sets initial values for F(0), F(1) and F(n)
		mov eax, 0			;sets incrementing var to 0
		mov [incv], eax
		
		mov eax, 1			;sets displayed fib number to 1 (current/nth term)
		mov [fib_a], eax
		
		mov eax, 1			;sets "previous" fib number to 1 (previous/n-1th term)
		mov [fib_b], eax
		
		mov eax, 0			;sets fib before previous to 0 (pre-previous/n-2th term)
		mov [fib_c], eax
		
.linebr:
		push dword line_br
		call printf
		add esp, 4
		
		mov eax, [incv]
		mov ebx, [num]
		sub eax, ebx		;checks if number of terms has been reached
		jz .farewell
		
.display_fibs:		
		
		mov eax, [incv]
		inc eax
		mov [incv], eax
		
		push dword [fib_a]
		push dword fib_res
		call printf
		add esp, 8
.calc_fibs:																												;Fibonacci sequence: F(n) = F(n-1) + F(n-2)
		mov eax, [fib_a]	;copies value of F(n) to eax																;{n is the current term, or value of incv}
		mov ebx, [fib_b]	;copies value of F(n-1) to ebx																;This code snippet effectively increments n, moving
		mov ecx, [fib_c]	;copies value of F(n-2) to ecx																;	F(n) to F(n+1), F(n-1) to F(n) and F(n-2) to F(n-1)
		mov [fib_c], ebx	;copies value of F(n-1) to F(n-2)															;	so the next time F(n) is displayed with the next n it is
		add ebx, ecx		;adds F(n-1) and F(n-2) to get F(n+1), stores in ebx										;	correct and this process can be repeated to reach the next
		mov [fib_a], eax	;sets F(n) to F(n+1)																		;	correct value.
		mov [fib_b], eax	;sets F(n-1) to F(n)																		;After this process, when 'n' is incremented, fib_a will contain F(n),
  		;																												;	fib_b will contain F(n-1) and fib_c will contain F(n-2) so this process
		;																												;	can be continued.
		mov eax, [incv]		;sets eax to [incv] outside of loop to check if line break needed
.check_ends:
		sub eax, 5			;subtracts five from the iteration value
		jz .linebr			;if the result is zero (the iteration is a multiple of five), jump to the .linebr instruction
		jg .check_ends		;repeat process if the result of the subtraction 
		
		mov eax, [incv]
		mov ebx, [num]
		sub eax, ebx		;checks if number of terms has been reached
		jnz .display_fibs	;if not, jump to display_fibs
		
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
	