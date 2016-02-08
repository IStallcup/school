; Name: Richard Sala
; Creation date: 2/23/2015
; Last modified: 2/27/2015
;
; 
; Name of file: a5.asm
; Description: approximation of e, number calculation
;			   matrix multiplication, frequency table
			
; Assemble:	nasm -f elf -l a5.lst  a5.asm
; Link:		gcc -m32 -o a5  a5.o
; Run:		./a5
; Output:	

; Equivalent C code

	
; Declare needed external functions
;
extern	printf			; the C function, to be called
extern scanf
	
SECTION .data				; Data section, initialized variables
	;introduction variables
	printi: db "Hello, this is Assignment 5 by Richard Sala!", 10, 0 	; printf format
	printi2: db "Please select one of the following: ", 10, 0
	printi3: db "1 = Approximate e. 2 =calculator. 3 = matrix multiplication. 4 = Relative Frequency Table.", 10, 0
	choice: db "%d", 0
	userchoice: dd 0
	emessage: db "Not 1-4, ending now. Have a nice day.", 10, 0
	exitmessage: db "Thanks for using my assignment, have a nice day. Good bye now.", 10, 0

	;func1
	printe: db "This is the true value of e: %.10f", 10, 0
	printe2: db "This is the approximation of e after 50 loops: %.10f", 10, 0
	limit: dq 50.0
	counte: dq 1.0
	n: dq 1.0
	
	;func2
	UB: dq 100.0			; upper bound
	LB: dq 0.0				; lower bound
	intro: db "Hello! This is Part 2 of Assignment 3. I'm not really sure what to call it but Richard Sala wrote it", 10, 0
	usernamep: db "Please enter your name: ", 10, 0 
	name: db "%s", 0
	Hello: db "Hello, %s!", 10, 0
	part1: db "You will be prompted for a value (decimals can be used) less than or equal to 100.0", 10, 0
	part2: db "When you're finished simply enter a negative number like -1", 10, 0
	part3: db "The program will then show the number of non negative numbers entered, sum, and average value of your input.", 10, 0
	part4: db "Enter your numbers", 10, 0
	input: dq "%lf", 0
	error: db "Number over 100. Number must be less.", 10, 0
	printf21: db "You entered a negative number! We're done!", 10, 0
	printf22: db "Results:", 10, 0
	printf23: db "Number of non negative integers = %.1f", 10, 0
	printf24: db "Sum = %.3f", 10, 0
	printf25: db "Average = %.3f", 10, 0
	specialcase: db "No non negative integers were entered!", 10, 0
	bye: dd "bye, %s!", 10, 0
	print1: dd "Input the numbers you want"
	num: dq 0.0
	sum: dq 0.0
	numbers: dq 0.0
	av: dq 0.0
	zero: dq 0.0
	one: dq 1.0
	temp: dq 0.0

	;func3
	matrix1: dq 1.12, 2.23, 3.34, 4.45
	matrix2: dq 2.11, 3.22, 4.33, 5.44
	linebr: db " ", 10, 0
	matrixprint: db "These are the two matrices that will be multiplied together: ", 10, 0
	product: db "Product is:", 10, 0
	matrixprintval: db "%.02f %.02f", 10, 0

	;func4
	tablep: db "Table is: ", 0
	stringp: db "%c ", 10, 0
	freqcount:	dd 0
	freqsize:	dq 6.0
	stringmess: db "String is: ", 10, 0
	tableprint: db "%lf ",  0
	count2: dq 0.0
	one4:	dq 1.0
	what:	dd "%d", 10, 0
	test:	db "", 10, 0
	counter4:	dd	0
	normalized:	dq 0.0
	normalizedA: dq 0.0
	print14:		db "Normalized value of one occurrence is: %lf ", 10, 0
	print1.54:		db "Values appear in order of string.", 10, 0
	print24:		db "At position %d the ", 0
	print34:		db "Frequency as a normalized value is: %lf", 10, 0

SECTION .bss				; BSS, uninitialized variables
	;func1:
	e: resq 1
	e2: resq 1
	
	;func2
	username: resd 1		; variable for username
	invar: resq 1

	;func3
	v1: resq 1
	v2: resq 1
	v3: resq 1
	v4: resq 1
	v5: resq 1
	v6: resq 1
	v7: resq 1
	v8: resq 1
	v4x: resq 4

	;func4
	string:	resd 6
	table:	resq 128


SECTION .text				; Code section.

global main				; the standard gcc entry point

	main:					; the program label for the entry point
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		;introduction with instructions on what to choose
		push dword printi
		call printf
		push dword printi2
		call printf
		push dword printi3
		call printf
		add esp, 12
		
		;get input from user to make decision
		push dword userchoice
		push dword choice
		call scanf
		add esp, 8

		;if they choose 1, go to func1
		mov eax, [userchoice]
		cmp eax, 1
		je .func1
		
		;if they choose 2, go to func2
		mov eax, [userchoice]
		cmp eax, 2
		je .func2
		
		;if they choose 3, go to func3
		mov eax, [userchoice]
		cmp eax, 3
		je .func3
		
		;if they choose 4, go to func4
		mov eax, [userchoice]
		cmp eax, 4
		je .func4
		
		;if not, jump to last
		jmp .end
		
		;calls func1 then jumps to last
		.func1:
			push dword [limit + 4]
			push dword [limit]
			call func1
			add esp, 8
			jmp .exit
		
		;calls func2 then jumps to last
		.func2:
			call func2
			jmp .exit
		;calls func3 then jumps to last
		.func3:
			call func3
			jmp .exit
		;calls func4 then jumps to last
		.func4:
			call func4
			jmp .exit

		;says goodbye
		.end:
			push emessage
			call printf
			add esp, 4

			mov		esp, ebp	; takedown stack frame
			pop		ebp			; same as "leave" op

			mov		eax,0		; normal, no error, return value
			ret					; return

		;exits correctly after function
		.exit:
			push exitmessage
			call printf
			add esp, 4

			mov		esp, ebp	; takedown stack frame
			pop		ebp			; same as "leave" op

			mov		eax,0		; normal, no error, return value
			ret					; return

	
; *********** FUNC1 ************	
	func1:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		;calculate actual average of e
		fldl2e ; load log_2(e)
		fld1   ; load 1
		fsub   ; subtract, store in st0
		f2xm1  ; 2**st0 - 1
		fld1   ; load 1
		fadd   ; add, result is 2**st0
		fld st0; reload st0
		fadd   ; so that we can double it
		fstp qword [e2]; load e
		
		;print actual value of e
		push dword [e2 + 4]
		push dword [e2]
		push printe
		call printf
		add esp, 12
	
		;adding the first one
		fld qword [one]
		fadd qword [zero]
		fstp qword [e]
		
		
		;loop to calculate e
		.eloop:
			;multiplying n by the counter
			fld qword [n]
			fmul qword [counte]
			fstp qword [n]

			;1 / factorial
			fld qword [one]
			fdiv qword [n]
			fstp qword [temp]

			;e = e + temp
			fld qword [temp]
			fadd qword [e]
			fstp qword [e]
			
			;increases counter
			fld qword [counte]
			fadd qword [one]
			fstp qword [counte]
			
			;compare the counter to the limist 
			fld qword [counte]		; load counte
			fcomp qword [limit]		; compare to limit (50.0)
			wait
			fstsw ax
			sahf
			ja .print
			
			;loop back
			jmp .eloop
			
		;print the value of e
		.print:
			push dword [e + 4]
			push dword [e]
			push printe2
			call printf
			add esp, 12
		
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		
		mov		eax,0		; normal, no error, return value
		ret					; return
		
; *********** FUNC2 ************	
	func2:
		push	ebp			; set up stack frame
		mov		ebp,esp

		;Displays the intro and asks the user to input their name
		push dword intro	; pushes intro
		push dword usernamep ; pushes username
		call printf			; call to printf
		add esp, 8			; allocate memory
		
		;Get the name from the user and put it into username
		push dword username	; pushes username
		push dword name	; push name
		call scanf			; call to scanf
		add esp, 8			; allocate memory
		
		;Welcomes the user
		push dword username
		push dword Hello
		call printf
		add esp, 8
		
		;Displays the instructions for the user
		push dword part1
		push dword part2
		push dword part3
		push dword part4
		call printf
		add esp, 16
		
		;input funciton
		.input:
			;gets a number input by the user
			push invar
			push input
			call scanf
			add esp, 8
			
			;compares to upper limit
			fld qword [invar]		; load invar
			fcomp qword [UB]		; compare to upper bound 50.0
			wait
			fstsw ax
			sahf
			ja .errorMsg			; jump if above to errorMsg
			
			;compares to lower bound
			fld qword [invar]		; load invar
			fcomp qword [LB]		; compare to lower bound 0.0
			wait
			fstsw ax
			sahf
			jb .print				; jump if below to print
			
			jmp .func				; if it's fine, go to func
		
		.func:
			fld qword [sum]			; load sum
			fadd qword [invar]		; add invar
			fstp qword [sum]		; store is back un sum
			
			fld qword [numbers]		; load counter (numbers)
			fadd qword [one]		; increase counter by one
			fstp qword [numbers]	; store value into numbers	
			
			jmp .input				; jump back to input, loop
		
		
		.errorMsg:
			push dword error	; prints error message
			call printf
			add esp, 4
		
			jmp .input				; jump back to input, loop
			
			
		.print:
			;special case, if there are no numbers
			fld qword [numbers]		; load numbers
			fcomp qword [zero]		; compare to 0
			wait
			fstsw ax
			sahf
			je .special				; jump to special
			
			push dword printf21		; print the description of results
			push dword printf22
			call printf
			add esp, 4
			
			; prints how many non negative integers
			push dword [numbers + 4]
			push dword [numbers]
			push dword printf23
			call printf
			add esp, 12
			
			; prints the sum
			push dword [sum + 4]
			push dword [sum]
			push dword printf24
			call printf
			add esp, 12
			
			jmp .calcav				; jumps to calculate average
		
		;calculate the average
		.calcav:
			fld qword [sum]			; load sum
			fdiv qword [numbers]	; divide by the counter (numbers)
			fstp qword [av]			; store value in average (av)
			
			jmp .finish				; jump to finish
			
		.finish:
			; display the average
			push dword [av + 4]
			push dword [av]
			push dword printf25
			call printf
			add esp, 12
			
			push dword username		; gets the username
			push dword bye		; goodbye statement 
			call printf
			add esp, 8
			
			jmp .end				; jumps to end
			
		; special case function
		.special:
			push dword specialcase		; print the special message		
			push dword username		; gets username
			push dword bye		; goodbye message
			call printf
			add esp, 12
			
			jmp .end
			
		.end:
			mov		esp, ebp	; takedown stack frame
			pop		ebp			; same as "leave" op
			
			mov		eax,0		; normal, no error, return value
			ret					; return

; *********** FUNC3 ************
		func3:
			push	ebp			; set up stack frame
			mov		ebp,esp
			
			;introduction
			push dword matrixprint
			call printf
			add esp, 4
			
			;print the first matrix
			push dword [matrix1 + 4]
			push dword [matrix1]
			push dword [matrix1 + 12]
			push dword [matrix1 + 8]
			push dword matrixprintval
			call printf
			push dword [matrix1 + 20]
			push dword [matrix1 + 16]
			push dword [matrix1 + 28]
			push dword [matrix1 + 24]
			push dword matrixprintval
			call printf
			add esp, 40
			;end line
			push dword linebr
			call printf
			add esp, 4
			
			;print the second matrix
			push dword [matrix2 + 4]
			push dword [matrix2]
			push dword [matrix2 + 12]
			push dword [matrix2 + 8]
			push dword matrixprintval
			call printf
			push dword [matrix2 + 20]
			push dword [matrix2 + 16]
			push dword [matrix2 + 28]
			push dword [matrix2 + 24]
			push dword matrixprintval
			call printf
			add esp, 40
			;end line
			push dword linebr
			call printf
			add esp, 4
				
		
		;calculations
		.calc:
			fld qword [matrix1]		; load first location of matrix1
			fmul qword [matrix2]		; multiply by the first location of matrix2
			fstp qword [v1]	; store in 
				
			fld qword [matrix1 + 8]
			fmul qword [matrix2 + 16]
			fstp qword [v2]
				
			fld qword [matrix1]	
			fmul qword [matrix2 + 16]
			fstp qword [v3]		
				
			fld qword [matrix1 + 8]
			fmul qword [matrix2 + 24]
			fstp qword [v4]
				
			fld qword [matrix1 + 16]
			fmul qword [matrix2]
			fstp qword [v5]
				
			fld qword [matrix1 + 24]
			fmul qword [matrix2 + 16]
			fstp qword [v6]	
				
			fld qword [matrix1 + 16]
			fmul qword [matrix2 + 8]
			fstp qword [v7]	
				
			fld qword [matrix1 + 24]	
			fmul qword [matrix2 + 24]
			fstp qword [v8]	
				
			fld qword [v1]
			fadd qword [v2]
			fstp qword [v4x]
				
			fld qword [v3]
			fadd qword [v4]
			fstp qword [v4x + 8]
				
			fld qword [v5]
			fadd qword [v6]
			fstp qword [v4x + 16]
				
			fld qword [v7]
			fadd qword [v8]
			fstp qword [v4x + 24]
				
			jmp .printMatrix
		
		.printMatrix:
			;product
			push dword product
			call printf
			add esp, 4
				
			;print the resulting matrix
			push dword [v4x + 4]
			push dword [v4x]
			push dword [v4x + 12]
			push dword [v4x + 8]
			push dword matrixprintval
			call printf
			push dword [v4x + 20]
			push dword [v4x + 16]
			push dword [v4x + 28]
			push dword [v4x + 24]
			push dword matrixprintval
			call printf
			add esp, 40

			jmp .end

		.end:
			mov		esp, ebp	; Takedown stack frame
			pop		ebp			; same as "leave" op

			mov		eax,0		; normal, no error, return value
			ret					; return

; *********** FUNC4 ************	
		func4:
		push	ebp			; set up stack frame
		mov		ebp,esp

	; create a frequency table from a char array
	freqTable:
		;push	ebp			; set up stack frame
		;mov		ebp,esp
	
	;manually fills the string with values
	;I couldn't get it working without manually adding them
	.manualfill:
		mov ecx, 0
		
		mov [string + 4 * ecx], byte 'A'
		add ecx, 1
		mov [string + 4 * ecx], byte 'A'
		add ecx, 1
		mov [string + 4 * ecx], byte 'B'
		add ecx, 1
		mov [string + 4 * ecx], byte 'C'
		add ecx, 1
		mov [string + 4 * ecx], byte 'D'
		add ecx, 1
		mov [string + 4 * ecx], byte 'E'
		add ecx, 1

	push tablep
	call printf
	add esp, 4

	;prints table
	.tableprint:
		push dword [table + 4]		;pushes value at postion eax in table
		push dword table
		push dword tableprint
		call printf
		add esp, 12

		mov eax, [count2]
		inc eax
		mov [count2], eax
		cmp dword [count2], 6
		jl .tableprint
		mov eax, [count2]
		mov eax, 0
		mov [count2], eax

	;zeros the registers
	.zero:
		mov eax, 0
		mov ecx, 0

		push dword test
		call printf
		add esp, 4

		push dword stringmess
		call printf
		add esp, 4
		jmp .originprint

	;prints string
	.originprint:
		mov eax, [count2]
		push dword [string + 4 * eax]
		push dword stringp
		call printf
		add esp, 8

		mov ebx, 0
		mov [counter4], ebx

		mov eax, [count2]
		inc eax
		mov [count2], eax
		cmp dword [count2], 6
		jl .originprint

		mov ecx, 0
		mov [count2], ecx
		jmp .freqnorm

	.freqnorm:
		fld qword [one4]
		fdiv qword [freqsize]
		fstp qword [normalized]
		jmp .counts

	;counter loop
	.counts:
		;push dword test
		;call printf
		;add esp, 4

		push dword [normalized + 4]
		push dword [normalized]
		push dword print14
		call printf
		add esp, 12

		push dword print1.54
		call printf
		add esp, 4

		fld qword [normalized]
		fadd qword [normalized]
		fstp qword [normalizedA]

		fld qword [normalizedA]
		fstp qword [table]

		fld qword [normalized]
		fstp qword [table + 8]
		
		fld qword [normalized]
		fstp qword [table + 16]

		fld qword [normalized]
		fstp qword [table + 24]

		fld qword [normalized]
		fstp qword [table + 32]

		jmp .printstatement

	;prints out values 
	.printstatement:
		push dword test
		call printf
		add esp, 4

		push dword [table + 4]
		push dword [table]
		push dword print34
		call printf
		add esp, 12

		push dword test
		call printf
		add esp, 4

		push dword [table + 12]
		push dword [table + 8]
		push dword print34
		call printf
		add esp, 16

		push dword test
		call printf
		add esp, 4

		push dword [table + 20]
		push dword [table + 16]
		push dword print34
		call printf
		add esp, 12

		push dword test
		call printf
		add esp, 4

		push dword [table + 28]
		push dword [table + 24]
		push dword print34
		call printf
		add esp, 12

		push dword test
		call printf
		add esp, 4

		push dword [table + 36]
		push dword [table + 32]
		push dword print34
		call printf
		add esp, 12

		push dword test
		call printf
		add esp, 4
		jmp .end


	;ends function
	.end:
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op

		mov		eax,0		; normal, no error, return value
		ret					; return