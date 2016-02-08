	; Name:				Isaac Stallcup
	; Creation date: 	Jan 27, 2015
	; Last modified: 	7:35 Jan 27, 2015
	;
	; 
	; Name of file: avg1.asm
	; Description: print an integer from storage and from a register
		
	; Assemble:	nasm -f elf -l avg1.lst  avg1.asm
	; Link:		gcc -m32 -o avg1 avg1.o
	; Run:		./avg1
	; Output:	

	; Equivalent C code	
	;#include <stdio.h>
	;
	;int main()
	;{
	;	printf("Name:		Isaac Stallcup\n")	;
	;	printf("Program:	avg1.asm\n")	;
	;	printf("What is your name?\n")	;
	;	
	;	char *name	;
	;	name = (char *)malloc(sizeof(char))	;
	;	scanf("%s", &name)	;
	;	
	;	int num_temp, num = 0, counter = 0	;
	;	
	;	printf("Hello, %s.\n", &name)	;
	;	
	;	printf("Please enter integers you wish to average.\n")	;
	;	
	;	printf("*Negative numbers will end the averaging process and display the average.*\n")	;
	;	
	;	printf("-*Input numbers between 0 and 100.*-\n")	;
	;	
	;	int x	;
	;	
	;	for (x = 2	; x > 0	; x--)
	;	{
	;		printf("Enter an integer:	")	;
	;		scanf("%d", &num_temp)	;
	;		
	;		if (num_temp < 0)
	;		{
	;			break	;
	;		}
	;		
	;		while (num_temp >= 101)
	;		{
	;			printf("-*Input numbers between 0 and 100.*-\n")	;
	;			printf("Enter an integer:	")	;
	;			scanf("%d", &num_temp)	;
	;		}
	;		
	;		num += num_temp	;
	;		
	;		counter++	;
	;		
	;		x++	;
	;	}
	;	
	;	printf("Negative detected.\nAveraging...\n")	;
	;	
	;	printf("Numbers found:\t\t\t%d\n", counter)	;
	;	
	;	if (counter == 0)
	;		return 0	;
	;
	;	printf("Sum of %d numbers:\t\t%d\n", counter, num)	;
	;	
	;	num /= counter	;
	;	
	;	printf("Average:\t\t\t%u\n", num)	;
	;	
	;	printf("Goodbye, %s", &name)	;
	;	
	;	printf(".\n")	;
	;	
	;	return 0	;
	;	
	;}

	extern	printf		
	extern 	scanf
	
SECTION .data				

name:		db "Name:		Isaac Stallcup", 10, 0

title:		db "Program:	avg1.asm", 10, 0

pr_name:	db "What is your name?", 10, 0

name_get:	db "%s", 0

greet:		db "Hello, %s.", 10, 0

instr_1:	db "Please enter integers you wish to average.", 10, 0

instr_2:	db "*Negative numbers will end the averaging process and display the average.*", 10, 0

instr_3:	db "-*Input numbers between 0 and 100.*-", 10, 0

instr_4:	db "Enter an integer:	", 0

num_in:		db "%d", 0

counter:	dd 0

avging:		db "Negative detected.", 10, "Averaging...", 10, 0

show_count:	db "Numbers found:			%d", 10, 0

show_sum:	db "Sum of %d numbers:		%d", 10, 0

avg:		db "Average:			%u", 10, 0

bye1:		db "Goodbye, %s", 0

bye2:		db ".", 10, 0

SECTION .bss				

name_in:	resd 1

num_temp:	resd 1

num:		resd 1

SECTION .text				

	global main				

	main:					
		push	ebp
		mov		ebp,esp

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
		
		push dword name_in
		push dword greet
		call printf
		add esp, 8
		
		push dword instr_1
		call printf
		add esp, 4
		
		push dword instr_2
		call printf
		add esp, 4	
		
		mov ecx, 2
		
.error:
		
		push dword instr_3
		call printf
		add esp, 4
		
.get_num:
		
		push ecx
		
		push dword instr_4
		call printf
		add esp, 4
		
		push dword num_temp
		push dword num_in
		call scanf
		add esp, 8
		
		mov eax, [num_temp]
		cmp eax, 0
		jl .end
		
		mov eax, [num_temp]
		mov ebx, 101
		sub eax, ebx
		jns .error
		
		mov eax, [num]
		mov ebx, [num_temp]
		add eax, ebx
		mov [num], eax
		
		mov eax, [counter]
		inc eax
		mov [counter], eax
		
		pop ecx
		
		inc ecx
		
		loop .get_num
		
.end:
		
		push dword avging
		call printf
		add esp, 4
		
		push dword [counter]
		push dword show_count
		call printf
		add esp, 8
		
		mov eax, [counter]
		sub eax, 0
		jz .bye
		
		push dword [num]
		push dword [counter]
		push dword show_sum
		call printf
		add esp, 12
		
		mov al, byte [num]
		xor ah, ah
		mov cl, [counter]
		div cl
		mov byte [num], al
		
		push dword [num]
		push dword avg
		call printf
		add esp, 8
		
		push dword name_in
		push dword bye1
		call printf
		add esp, 8
		
		push dword bye2
		call printf
		add esp, 4		
.bye:
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	
	