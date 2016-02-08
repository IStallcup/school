	; Name:				Isaac Stallcup
	; Creation date: 	Jan 27, 2015
	; Last modified: 	22:32 Feb 11, 2015
	;
	; 
	; Name of file: math.asm
	; Description: perform 4 functions as stated in assignment.
		
	; Assemble:	nasm -f elf -l math.lst  math.asm
	; Link:		gcc -m32 -o math math.o
	; Run:		./math
	; Output:	

	; Equivalent C code:
	;#include <stdio.h>
	;#include <math.h>
	;#include <stdlib.h>
	;
	;int work_array[16];
	;
	;void print_array()
	;{
	;	int x = 0;
	;	while (x < 16)
	;	{
	;		printf("%d ", work_array[x]);
	;		x++;
	;	}
	;	
	;	printf("\n");
	;}
	;
	;void swp_array()
	;{
	;	
	;	
	;	while (x < 16)
	;	{
	;		work_array[x] = x;
	;		x++;
	;	}
	;	
	;	printf("Original Array:\n");
	;	
	;	print_array();
	;	
	;	printf("Swapped Array:\n");
	;	
	;	int cc = 0;
	;	int aa = 0;
	;	int bb = 15;
	;	int x = 0;
	;	
	;	while (x < 8)
	;	{
	;		cc = work_array[aa];
	;		work_array[aa] = work_array[bb];
	;		work_array[bb] = cc;
	;		aa++;
	;		bb--;
	;		x++;
	;	}
	;	print_array();
	;}
	;
	;void rotate_array()
	;{
	;	int cc = 0;
	;	int aa = 0;
	;	int bb = 1;
	;	
	;	for (x = 0; x < 16; x++)
	;	{
	;		work_array[x] = x;
	;	}
	;	
	;	printf("Original Array:\n");
	;	
	;	print_array();
	;	printf("Rotated Array Left:\n");
	;	int x = 0;
	;	cc = work_array[aa];
	;	while (x < 16)
	;	{	
	;		work_array[aa] = work_array[bb];
	;		if (bb == 15)
	;		{
	;			work_array[bb] = cc;
	;			break;
	;		}
	;		aa++;
	;		bb++;
	;		x++;
	;	}
	;	
	;	print_array();
	;	
	;	mk_array();
	;	print_array();
	;	printf("Rotated Array Right:\n");
	;	x = 0;
	;	cc = 0;
	;	aa = 15;
	;	bb = 14;
	;	cc = work_array[aa];
	;	while (x < 16)
	;	{	
	;		work_array[aa] = work_array[bb];
	;		if (bb == 0)
	;		{
	;			work_array[bb] = cc;
	;			break;
	;		}
	;		aa--;
	;		bb--;
	;		x++;
	;	}
	;	
	;	print_array();
	;}
	;
	;void freq_table()
	;{
	;	char string[64];
	;	int freq_table[26] = {0};
	;
	;	int x = 0;
	;	
	;	while (x < 4)
	;	{
	;		z = 0;
	;		if (string[x] == 'a')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'b')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'c')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'd')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'e')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'f')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'g')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'h')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'i')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'j')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'k')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'l')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'm')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'n')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'o')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'p')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'q')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'r')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 's')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 't')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'u')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'v')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'w')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'x')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'y')
	;			freq_table[z]++;
	;		z++;
	;		if (string[x] == 'z')
	;			freq_table[z]++;		
	;		x++;
	;	}
	;	
	;	x = 0;
	;	char temp;
	;	
	;	while (x < 52)
	;	{
	;		printf("%d", freq_table[x]);
	;	}
	;}
	;
	;/*void sieve()
	;{
	;
	;	int n = 0;
	;	printf("Which number would you like to sieve? ");
	;	scanf("%d", &n);
	;	
	;	int nums[128];
	;	
	;	int primes[128];
	;	
	;	int x = 0;
	;	
	;	while (x < n)
	;	{
	;		primes[x] = 1;
	;		x++;
	;	}
	;	
	;	x = 0;
	;	
	;	
	;	while (x < n)
	;	{
	;		nums[x] = x + 1;
	;		x++;
	;	}
	;	
	;	printf("\n1 is special.\n");
	;	
	;	int k = 1;
	;	
	;	int sqrtn = sqrt(n);
	;	
	;	//printf("sqrt n: %d\n", sqrtn);
	;	
	;	int marker = 1;
	;	
	;	int marker_x = 2;
	;	
	;	while (k < sqrtn)
	;	{
	;		while (k >= marker && marker < n)
	;		{
	;			//printf("Marker:%d\n", marker);
	;			marker++;
	;		}
	;		
	;		while (((marker_x * marker) <= n) && marker > 1)
	;		{
	;			//printf("Prime: %d\n", marker);
	;			//printf("Composite:%d\n", (marker_x * marker));
	;			//printf("Sequence:%d\n\n", primes[(marker_x * marker)-1]);
	;			primes[(marker_x * marker)-1] = 0;
	;			marker_x++;
	;		}
	;		
	;		marker_x = 2;
	;		
	;		k = marker;
	;	}
	;	
	;	x = 0;
	;	
	;	printf("Candidates:\t");
	;	while (x < n)
	;	{
	;		printf("%d ", nums[x]);
	;		x++;
	;	}
	;	
	;	x = 1;
	;	
	;	printf("\nPrimenss:\t* ");
	;	
	;	while (x < n)
	;	{
	;		printf("%d ", primes[x]);
	;		if (x >= 9)
	;			printf(" ");
	;		x++;
	;	}
	;
	;	printf("\n");
	;
	;}*/
	;
	;int main()
	;	;	;{
	;	int yn = 1;
	;	do {
	;	int sel = 0;
	;	
	;	
	;	while (sel > 4 || sel < 1)
	;	{
	;		//Welcome stuff goes here
	;		printf("Please select desired feature:");
	;		printf("\n1: Reverse Array\t2: Rotate Array\n3. Frequency Table\t4. Sieve of Eratosthenes\n");
	;		//list features
	;		scanf("%d", &sel);
	;	}
	;	
	;	if (sel == 1)
	;	{
	;		printf("PART ONE\n");
	;		swp_array();
	;		
	;	}
	;	
	;	else if (sel == 2)
	;	{
	;		printf("PART TWO\n");
	;		rotate_array();
	;	}
	;	
	;	else if (sel == 3)
	;	{
	;		printf("PART THREE\n");
	;		freq_table();
	;		
	;	}
	;	
	;	else if (sel == 4)
	;	{
	;		printf("PART FOUR\n");
	;		sieve();
	;	}
	;	
	;	printf("Go again? 1=Y, 0=N ");
	;	scanf("%d", &yn);
	;	} while(yn != 0);
	;	return 0;
	;}
	;

	extern	printf		
	extern 	scanf
	extern	sqrt
	
SECTION .data

go?:		db "Go again? 1=Y, 0=N ", 0					;prompt to go again

INPUT:		db "%d", 0									;gets input

OUTPUT:		db "%d ", 0									;gets output

OUTPUT_s:	db "%d", 0									;gets output without space
	
OUTPUT_c:	db "%c", 0									;outputs char

select_op:	db "Please select desired feature:", 0		;formatting

options:	db 10, "1. Reverse Array", 9, "2: Rotate Array", 10, "3. Frequency Table", 9, "4. Sieve of Eratosthenes", 10, 0

p1:			db "---------------", 10, "   PART ONE    ", 10, "---------------", 10, 0

original:	db "Original Array: ", 10, 0				;formatting

array:		dd 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16	;original 16 element array

swapped:	db 10, "Swapped Array:", 10, 0				;formatting

shifted_r:	db 10, "Rotated Right:", 10, 0				;formatting

shifted_l:	db 10, "Rotated Left:", 10, 0				;formatting

cln:		db ":", 0									;prints colon

br:			db 10										;prints line break

shw_str:	db "String:", 10, 0							;formatting

finalprint: db " Amount: %d Letters go in order shown", 10, 0	;table formatting

in_progress:db "Still in progres...", 10, 0				;awkward...

SECTION .bss				

yn:			resd	1									;value used to determine whether to quit or continue running program

sel:		resd	1											;value used to select which part of program to run

x:			resd	1									;value will be used for many types of counting

y:			resd	1									;value will be used for many types of counting

z:			resd	1									;value will be used for many types of counting

alpha:		resd	64									;string, hard-coded in, of up to 64 characters

f_tab:		resd	26									;frequency table

nums:		resd	128

SECTION .text				

	global main				

	main:					
		push	ebp										;set up stack frame
		mov		ebp,esp

	.do_loop:
		
		mov al, 1										
		mov [yn], eax									;set quit/continue value to yes
	
		mov al, 0										
		mov [sel], al									;set selection value to 0
	
	;		**Menu**
	.main_menu:
		
		push dword select_op							;asks user to select an operation
		call printf
		add esp, 4
		
		push dword options								;prints list of options
		call printf
		add esp, 4
		
		push dword sel									;preps sel for reading
		push dword INPUT								;pushes framework for reading sel
		call scanf
		add esp, 8
		
		mov eax, [sel]									;moves sel to eax for comparison test
		cmp eax, 4										;compares 4 to eax
		jg .main_menu									;if 4 > sel, return to the main menu; equivalent to while( x > 4 )
		
		mov ebx, [sel]									;moves sel to eax for comparison test
		cmp eax, 1										;compares 1 to eax
		jl .main_menu									;if 1 < sel, return to the main menu; equivalent to while( x < 1 )
		
		je .part_one									;if sel = 1, jump to the first part of the program
		
		mov eax, [sel]									;moves sel to eax for comparison test
		cmp eax, 2										;compares 2 to eax
		je .part_two									;if sel = 2, jump to the second part of the program
		
		mov eax, [sel]									;move sel to eax for comparison test
		cmp eax, 3										;compares 3 to eax
		je .part_three									;if sel = 3, jump to the third part of the program
		
		mov eax, [sel]									;moves sel to eax for comparison test
		cmp eax, 4										;compares 4 to eax
		je .part_four									;if sel = 4, jump to the fourth part of the program
	
	;	**Function Calls**
	.part_one:
		
		call swap										;calls swap function
		jmp .check_do									;jumps to checker for quit/continue
		
	.part_two:
		
		call shift										;calls shift function
		jmp .check_do									;jumps to checker for quit/continue
		
	.part_three:
		
		call frequency_table							;calls frequency table function
		jmp .check_do									;jumps to checker for quit/continue
		
	.part_four:
		
		call sieve										;calls sieve function
		jmp .check_do									;jumps to checker for quit/continue
		
	;checks for quit or continue
	.check_do:
		
		push dword go?									;asks user if they would like to quit or continue
		call printf										;call C function
		add esp, 4										;move stack pointer
		
		push dword yn									;push yn to be read into
		push dword INPUT								;push the framework for reading value to yn
		call scanf										;call C function
		add esp, 8										;move stack pointer
		
		mov eax, [yn]									;moves value of yn to eax
		cmp eax, 1										;compares 1 to eax
		je .do_loop										;jumps to beginning of function if they are equal
		
		mov		esp, ebp								;take down stack frame
		pop		ebp										;same as "leave" op
		mov		eax,0									;normal, no error, return value
		ret												;return
		
	;swap function
	swap:
	
		push ebp										;set up stack frame
		mov ebp, esp
		
		push dword p1									;print "part one"
		call printf
		add esp, 4
		
		mov eax, 0
		mov [x], eax									;set x to 0
		
		push dword original								;print "original array"
		call printf
		add esp, 4
		
		call print_array								;calls function to print array
		
		mov eax, 0
		mov [x], eax									;set x to 0
		
		mov eax, 15										;set y to 15; will be value for last element in array
		mov [y], eax
		
		.swap_array:
		
		mov eax, [x]
		mov esi, dword [array + 4*eax]					;copes value of xth element of 'array' to esi
		mov ebx, [y]
		mov edi, dword [array + 4*ebx]					;copies value of yth element of 'array' to edi
		
		push esi										;pushes esi
		push edi										;pushes edi
		pop esi											;pops esi to edi
		pop edi											;pops edi to esi, essentially swapping esi and edi
		
		mov eax, [x]									;moves esi, formerly edi, to xth element of 'array'
		mov dword [array + 4*eax], esi					;swapping xth and yth element of 'array'
		mov ebx, [y]									;moves edi, formerly esi, to yth element of 'array'
		mov dword [array + 4*ebx], edi					;swapping yth and xth element of 'array'
	
		mov eax, [y]									;decrements y, upper swap element
		dec eax
		mov [y], eax
		
		mov eax, [x]									;increments x, lower swap element
		inc eax
		mov [x], eax
		
		mov eax, [y]		
		cmp eax, 7
		jne .swap_array									;if y != y, jump back to the start of swapping process
		
		push dword swapped								;print "Swapped Array:"
		call printf
		add esp, 4
		
		mov eax, 0
		mov [x], eax									;set x to 0
		
		call print_array
		
		mov esp, ebp									;take down stack frame
		pop ebp
		
		mov eax, 0
		ret												;goodbye!
		
	shift:
		
		push ebp										;set up stack frame
		mov ebp, esp
		
		push dword original								;print "Original Array:"
		call printf
		add esp, 4
		
		mov eax, 0										;set x=0
		mov [x], eax
		
		call print_array								;print unmodified array
		
		mov eax, 0										;set x=0
		mov [x], eax
		
		call shift_array								;function to shift array
		
		mov esp, ebp									;take down stack frame
		pop ebp
		
		mov eax, 0
		ret
		
	shift_array:
	
		push ebp										;set up stack frame
		mov ebp, esp
		
		mov eax, 0										;set x=0
		mov [x], eax
		
		call shift_left									;call function to shift left
		
		push dword shifted_l							;formatting to show that array was shifted left
		call printf
		add esp, 4
		
		call print_array								;prints shifted left array
		
		mov eax, 0										;set x=0
		mov [x], eax
		
		call shift_right								;call function to shift right - RETURNS TO DEFAULT POSITION
	
		mov eax, 0										;set x=0
		mov [x], eax
		
		call shift_right								;call function to shift right - now actually shifts to right
		
		push dword shifted_r							;prints formatting to show that array was shifted left
		call printf
		add esp, 4
		
		call print_array								;prints array
		
		mov esp, ebp
		pop ebp
		
		mov eax, 0
		ret
	
	shift_left:
	
		push ebp										;set up stack frame
		mov ebp, esp
		
		mov eax, 0										;x=0
		mov [x], eax
		mov ebx, dword [array + 4*eax]					;moves 0th element of array to ebx
		mov [y], ebx									;moves ebx to y; effectively saves 0th element of array in y
		
		mov eax, 0										;x=0
		mov [x], eax
		
		.loop_l:
			
			mov eax, [x]								;set x to eax
			mov esi, dword [array + 4*eax]				;move xth element of array to esi
			inc eax										;increment eax
			mov edi, dword [array + 4*eax]				;moves x+1th element of array to edi
			
			push esi									;pushes esi
			push edi									;pushes edi
			pop esi										;pops esi to edi
			pop edi										;pops edi to esi, essentially swapping esi and edi
			
			mov eax, [x]								;moves x to eax
			mov dword [array + 4*eax], esi				;moves x+1 to x
			inc eax										;moves x+1 to eax
			mov dword [array + 4*eax], edi				;moves x+2 to to x+1
			
			mov eax, [x]								;increments x for rest of function
			inc eax
			mov [x], eax
			
			mov eax, [x]								;compares x to 15; if x != 15, repeat process until condition
			cmp eax, 15									;	is met
			jne .loop_l
		
		mov eax, 15										;set eax to 15
		
		mov dword [array + 4*eax], ebx					;set 16th element of array to value of first one originally
		
		mov esp, ebp									;take down stack frame
		pop ebp
		
		mov eax, 0										;end function
		ret
		
	shift_right:
		
		push ebp										;set up stack frame
		mov ebp, esp
		
		mov eax, 15										;moves 15 to eax
		mov [x], eax									;moves 15 to x
		mov ebx, dword [array + 4*eax]					;moves 15th element of array to ebx
		mov [y], ebx									;'saves' this element in y
		
		mov eax, 15										;x=15
		mov [x], eax
		
		.loop_r:
			
			mov eax, [x]								;sets eax to x
			mov esi, dword [array + 4*eax]				;move xth element of array to esi
			dec eax										;decrement eax
			mov edi, dword [array + 4*eax]				;moves x+1th element of array to edi
			
			push esi									;pushes esi
			push edi									;pushes edi
			pop esi										;pops esi to edi
			pop edi										;pops edi to esi, essentially swapping esi and edi
			
			mov eax, [x]								;copies x to eax
			mov dword [array + 4*eax], esi				;moves x-1 to x
			dec eax										;moves x-1 to eax
			mov dword [array + 4*eax], edi				;moves x-2 to x-1 
			
			mov eax, [x]								;decrements x for rest of loop
			dec eax
			mov [x], eax
			
			mov eax, [x]								;if x != zero, return to beginning of loop
			cmp eax, 0
			jne .loop_r
		
		mov eax, 0										;x = 0
		mov [x], eax
		
		mov dword [array + 4*eax], ebx					;move what was last element of array to the first
		
		mov esp, ebp									;end program
		pop ebp
		
		mov eax, 0
		ret
		
	print_array:
		
		push ebp										;set up stack frame
		mov ebp, esp
		
		mov eax, 0										;x=0
		mov [x], eax
		
		.print_array_loop:
			
			mov eax, [x]								;moves x to eax
			mov eax, dword [array + 4*eax]				;moves the xth element of array to eax
			
			push eax
			push dword OUTPUT							;prints contents of eax
			call printf
			add esp, 8
			
			mov eax, [x]								;increments eax for rest of function
			inc eax
			mov [x], eax
			
			mov eax, [x]								;if x != 16, return to beginning of loop
			cmp eax, 16
			jne .print_array_loop
			
		mov esp, ebp									;end program
		pop ebp
		
		mov eax, 0
		ret
			
	frequency_table:
	
		push ebp										;set up stack frame
		mov ebp, esp
		
		mov eax, 0										;x=0
		mov [x], eax
		
		push dword shw_str								;formats show string
		call printf
		add esp, 4
		
		
	;declare string:
		
		mov eax, 0										;set eax to 0
		
		mov [alpha + 4*eax], byte 'a'					;manually input string 'aaaz'
		inc eax
		
		mov [alpha + 4*eax], byte 'b'
		inc eax
		
		mov [alpha + 4*eax], byte 'c'
		inc eax
		
		mov [alpha + 4*eax], byte 'z'
		inc eax
		
		mov [y], eax									;set y to eax, the number of terms in the string
		
	.show_string:
		
		mov eax, [x]									;sets eax to x
		mov esi, [alpha + 4*eax]						;sets xth element of array to esi
		
		push esi										;prints esi
		push dword OUTPUT_c
		call printf
		add esp, 8
		
		mov eax, 0										;set z to 0
		mov [z], eax

;==================================================================================================
;	Each of these five-line blocks compares esi, containing the current character in the 
;	string, to a lowercase letter; if they are the same, it jumps to the label .inc_table with
;	the current value of z. Otherwise, it increments z and moves on to the next letter.
;==================================================================================================

		cmp esi, byte 'a'			
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'b'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'c'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'd'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'e'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'f'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'g'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'h'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'i'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax

		cmp esi, byte 'j'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'k'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'l'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
;==================================================================================================
;	Each of these five-line blocks compares esi, containing the current character in the 
;	string, to a lowercase letter; if they are the same, it jumps to the label .inc_table with
;	the current value of z. Otherwise, it increments z and moves on to the next letter.
;==================================================================================================

		cmp esi, byte 'm'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'n'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'o'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'p'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'q'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'r'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 's'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 't'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'u'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'v'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'w'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'x'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'y'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
		cmp esi, byte 'z'
		je .inc_table
		mov eax, [z]
		inc eax
		mov [z], eax
		
;==================================================================================================
;	Each of these five-line blocks compares esi, containing the current character in the 
;	string, to a lowercase letter; if they are the same, it jumps to the label .inc_table with
;	the current value of z. Otherwise, it increments z and moves on to the next letter.
;==================================================================================================

		.post_inc:										;area increments eax, then jumps to ending of function
		
		mov eax, [x]							
		inc eax											;increments eax for rest of function
		mov [x], eax
		
		jmp .post_index									;jumps to portion of program at end
		
		.inc_table:
		
		mov eax, [z]									;moves z to eax
		mov esi, dword [freq_table + 4*eax]				;moves zth element of freq_table to esi
		
		;somehow move value from [z] to [freq_table + 4*eax]
		
		push esi										;prints esi
		push OUTPUT
		call printf
		add esp, 8
		
		jmp .post_inc									;jump to increment x
		
		.post_index:									;jump to post-index value
		
		mov eax, [x]									;moves x to eax
		mov ebx, [y]									;moves y [total # of string characters] to ebx
		cmp eax, ebx									;compares eax, ebx
		jne .show_string								;jumps to beginning of function if they are not equal
		
		mov esp, ebp									;end program
		pop ebp
		
		mov eax, 0										
		ret
		
	sieve:
	
		push ebp
		mov ebp, esp
		
		push dword in_progress
		call printf
		add esp, 4
		
		mov esp, ebp
		pop ebp
		
		mov eax, 0
		ret
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	