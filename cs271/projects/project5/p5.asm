	; Name:				Isaac Stallcup
	; Creation date: 	Feb 22, '15
	; Last modified: 	March 1, '15
	;
	; 
	; Name of file: p5.asm
	; Description: Performs 4 functions as required in prompt
		
	; Assemble:	nasm -f elf -l p5.lst  p5.asm
	; Link:		gcc -m32 -o p5 p5.o
	; Run:		./p5
	; Output:	

	; Equivalent C code
		;#include <stdio.h>
	;#include <math.h>
	;#include <stdlib.h>
	;
	;void calculate_e()
	;{
	;	int a;
	;	float b, c, e, z;
	;	a = 1;
	;	b = 1;
	;	c = 1;
	;	float y = 1.0;
	;	float e_6 = 2.718281;
	;	float prec = 0.00001;
	;	
	;	while (a <= 9)
	;	{
	;		printf("\n\nIteration number %d\n", a);
	;		c = c*a;
	;		z = b/c;
	;		a++;
	;		y=z+y;
	;		printf("Sum of fractions so far:	%f\n", y);
	;		printf("Actual value of e:		%f\n", e_6);
	;		e = e_6-y;
	;		printf("Difference:			%f\n", e);
	;		printf("Precision value:		%f\n", prec);
	;	}
	;}
	;
	;void average_nums()
	;{
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
	;}
	;
	;void matrix_mul()
	;{
	;	float matrix_1[4] = {0.4, 0.3, 0.2, 0.1};
	;	float matrix_2[4] = {0.6, 0.7, 0.8, 0.9};
	;	float temp_matrix[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	;	float end_matrix[4] = {0.0, 0.0, 0.0, 0.0};
	;	
	;	printf("Matrix One:\n%lf %lf\n%lf %lf\n\n", matrix_1[0], matrix_1[1], matrix_1[2], matrix_1[3]);
	;	
	;	printf("Matrix Two:\n%lf %lf\n%lf %lf\n\n", matrix_2[0], matrix_2[1], matrix_2[2], matrix_2[3]);
	;	
	;	int a_counter=0, b_counter=0, c_counter=0, d_counter=0, counter=0;
	;	
	;	while (counter < 4)
	;	{
	;		temp_matrix[c_counter] = matrix_1[a_counter] * matrix_2[b_counter];
	;		b_counter++;
	;		c_counter++;
	;		temp_matrix[c_counter] = matrix_1[a_counter] * matrix_2[b_counter];
	;		a_counter++;
	;		b_counter++;
	;		c_counter++;
	;		if (b_counter==2)
	;		{
	;			b_counter = 0;
	;		}
	;		counter++;
	;	}
	;	
	;	counter = 0;
	;	c_counter = 0;
	;	d_counter = 0;
	;	
	;	while (counter < 4)
	;	{
	;		end_matrix[d_counter] = temp_matrix[c_counter] + temp_matrix[c_counter+2];
	;		c_counter++;
	;		d_counter++;
	;		counter++;
	;		if (counter == 2)
	;		{
	;			c_counter = 4;
	;		}
	;	}
	;	
	;	printf("End Matrix:\n%lf %lf\n%lf %lf\n\n", end_matrix[0], end_matrix[1], end_matrix[2], end_matrix[3]);
	;}
	;
	;void freq_table()
	;{
	;	int freq_tab[27] = {0};
	;	char cm_str[7] = {"APP LE"};
	;	int counter = 6;
	;	printf("String:			%s\n", cm_str);
	;	int ft_counter = 0, thing = 0;
	;	float numletts = counter;
	;	float frq_val_max = 1/numletts;
	;	printf("Single letter frequency: %lf\n", frq_val_max);
	;	int start = 65;
	;	while (start > 64)
	;	{
	;		if (cm_str[ft_counter] == start)
	;		{
	;			printf("Letter: %c", cm_str[ft_counter]);
	;			freq_tab[thing] = freq_tab[thing] + frq_val_max;
	;		}
	;		ft_counter++;
	;		thing++;
	;		start++;
	;		if (start == 91)
	;			break;
	;	}
	;}
	;
	;int main()
	;{
	;	int sel;
	;	do {
	;	printf("Welcome to Isaac Stallcup's Program 5.\n");
	;	printf("Please select the function you wish to perform (1-4).\n");
	;	printf("1 Approximate e\t\t\t2 Average numbers\n3 Float matrx multiplication\t4 Frequency Table\n");
	;	scanf("%d", &sel);
	;	} while (sel > 5 && sel < 0);
	;	
	;	if (sel == 1)
	;	{
	;		calculate_e();
	;	}
	;	
	;	if (sel == 2)
	;	{
	;		average_nums();
	;	}
	;	
	;	if (sel == 3)
	;	{
	;		matrix_mul();
	;	}
	;	
	;	if (sel == 4)
	;	{
	;		freq_table();
	;	}
	;	
	;	return 0;
	;	
	;}
	;

	extern	printf												;allows for use of C functions	
	extern 	scanf	
	
;==================================================================================================
;	Initialized Variables
;==================================================================================================	
	
SECTION .data

;=================================================
;	Misc. Re-used inputs/outputs
;=================================================

INPUT_str:	db	"%s", 0											;value used to input a string

INPUT_int:	db	"%d", 0											;value used to input an int

INPUT_flt:	dq	"%lf", 0										;value used to input a float

OUTPUT_int:	db	"%d", 10, 0										;value used to output an int

counter:	dd 0												;misc counter variable

zero_f:		dd 0.0												;constant 0 for floats

zero:		dq	0												

one:		dq	1

one_f:		dq	1.0

;=================================================
;	Formatting for menu navigation
;=================================================

welcome:	db	"Welcome to Isaac Stallcup's Program 5.", 10, 0

select:		db	"Please select the function you wish to perform (1-4).", 10, 0

options:	db	"1 Approximate e", 9, 9, 9, "2 Average numbers", 10, "3 Float matrix multiplication", 9, "4 Frequency Table", 10, 0

;=================================================
;	Values for approximating e
;=================================================

number:		db	10, 10, "Iteration number %d", 10, 0					;Iterative formatting

prec:		dq	0.00001											;precision value for e approximation

e_6:		dq	2.718281										;value of e to 6 decimal places

print_flt_f:db	"Calculated Fraction:		%f", 10, 0			;formatting for displaying approx of e

print_flt_s:db	"Sum of fractions so far:	%f", 10, 0			;formatting for displaying approx of e

print_flt_p:db	"Precision value:		%f", 10, 0				;formatting for displaying approx of e

print_flt_d:db	"Difference:			%f", 10, 0				;formatting for displaying approx of e

print_flt_e:db	"Actual value of e:		%f", 10, 0				;formatting for displaying approx of e

;=================================================
;	Values for float-enabled averaging
;=================================================

go?:		db	"Would you like to run the program again?", 10, "1 for yes, 0 for no.", 10, 0 ;formatting

get_name:	db	"What is your name?", 10, 0						;formatting

hello:		db	"Hello, %s.", 10, 0								;formatting

instr_1:	db "Please enter numbers (integer and floating point) you wish to average.", 10, 0 ;formatting

instr_2:	db "*Negative numbers will end the averaging process and display the average.*", 10, 0 ;formatting

instr_3:	db "-*Input numbers between 0 and 100.*-", 10, 0	;formatting

instr_4:	db "Enter a number:		", 0						;formatting

avging:		db "Negative detected.", 10, "Averaging...", 10, 0	;formatting

show_count:	db "Numbers found:			%d", 10, 0				;formatting

show_sum:	db "Sum of %d numbers:		%lf", 10, 0				;formatting

avg:		db "Average:			%lf", 10, "Goodbye, %s.", 10, 0 ;formatting

current_sum:db "Current sum: 		%f", 10, 0					;formatting

upper_b:	dq	100.0											;upper bound value

lower_b:	dq	0.0												;lower bound value

sum:		dq	0.0												;holds the sum as numbers are entered

averageval:	dq	0.0												;holds the average value after it is calculated

;=================================================
;	Values for matrix multiplication
;=================================================

dis_mat_1:	db	"Matrix One:", 10, 0							;formatting

dis_mat_2:	db	"Matrix Two:", 10, 0							;formatting

dis_mt_end:	db	"End Matrix:", 10, 0							;formatting

matrix_1:	dq	0.1, 0.2, 0.3, 0.4								;first matrix to multiply

matrix_2:	dq	0.9, 0.8, 0.7, 0.6								;second matrix to multiply

temp_matrix:dq	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0			;temporary storage matrix for products

end_matrix:	dq	0.0, 0.0, 0.0, 0.0								;end result matrix

element_prt:db	"%lf", 10, 0									;framework to print single element

print_array:db	"%lf %lf", 10, "%lf %lf", 10, 10, 0				;framework to print array

count_prt:	db	"%d %d %d %d:", 0								;unused formatting

;=================================================
;	Values for frequency table
;=================================================

frq_tab_prt:db	"Frequency: %lf ", 10, 0						;formatting

number_ft:	db	"Iteration number %d: ", 0						;formatting

ft_counter:	dd	0												;counter for frequency table

thing:		dd	0												;alpha counter, determines which letter of alphabet we are on

numletts:	dq	0.0												;number of letters in string

cm_nos:		db	"%c", 0											;no space char output

cm_str_out:	db	"Letter: %c	", 0								;formatted char output

frq_val_max:dq	0.0												;maximum value for normalized fraction

val_max_out:db 10, "Single letter frequency:   %lf", 10, 0		;formatted float output

label_string:db	"String:			", 0						;

;==================================================================================================
;
;	Uninitialized Variables
;
;==================================================================================================

SECTION .bss	

;=================================================				
;	Values for menu navigation
;=================================================

yn:			resd	1											;unused looping variable

sel:		resd	1											;selection for which part of program to run

;=================================================
;	Values for approximating e
;=================================================

a:			resq	1											;value used to increment approximation summation

b:			resq	1											;value used as one

c:			resq	1											;value used to calculate factorial

d:			resq	1											;unused iterative variable									

e:			resq	1											;reperesents approximation of e

y:			resq	1											;difference between approximation and actual value

z:			resq	1											;represents calculated value

;=================================================
;	Values for float-enabled averaging
;=================================================

name_in:	resd 	1											;collects name

num_temp:	resq 	1											;collects placeholder numbers to sum

;=================================================
;	Values for matrix multiplication
;=================================================

a_counter:	resd	1											;counts eax

b_counter:	resd	1											;counts ebx

c_counter:	resd	1											;counts ecx

d_counter:	resd	1											;counts edx

;=================================================
;	Values for frequency table
;=================================================

cm_str:		resd	64											;64 character input string

frq_tab:	resq	27											;27-element frequency table

SECTION .text				

	global main				

;==================================================================================================
;
;	Main function
;
;==================================================================================================	

main:
	
		push	ebp												;set up stack
		mov		ebp,esp
		
	.main_loop:
	
		mov 	al, 0											;set selection to 0
		mov 	[sel], al
		
	.main_menu:
	
		push	dword welcome									;prints hello
		call	printf
		add		esp, 4
	
		push	dword select									;asks you to select an option
		call 	printf
		add 	esp, 4
		
		push 	dword options									;prints options
		call 	printf
		add 	esp, 4
		
		push 	dword sel										;gets sel
		push 	dword INPUT_int
		call 	scanf
		add 	esp, 8
		
		mov 	eax, [sel]										;moves sel to eax for comparison test
		cmp 	eax, 4											;compares 4 to eax
		jg 		.main_menu										;if 4 > sel, return to the main menu; equivalent to while( x > 4 )
		
		mov 	ebx, [sel]										;moves sel to eax for comparison test
		cmp 	eax, 1											;compares 1 to eax
		jl 		.main_menu										;if 1 < sel, return to the main menu; equivalent to while( x < 1 )
			
		je 		.part_one										;if sel = 1, jump to the first part of the program
		
		mov		eax, [sel]										;moves sel to eax for comparison test
		cmp		eax, 2											;compares 2 to eax
		je 		.part_two										;if sel = 2, jump to the second part of the program
		
		mov 	eax, [sel]										;move sel to eax for comparison test
		cmp		eax, 3											;compares 3 to eax
		je		.part_three										;if sel = 3, jump to the third part of the program
		
		mov		eax, [sel]										;moves sel to eax for comparison test
		cmp 	eax, 4											;compares 4 to eax
		je		.part_four										;if sel = 4, jump to the fourth part of the program
		
	.part_one:

		call 	calculate_e										;calls approx e function
		jmp 	.check_do
		
	.part_two:

		call 	average_nums									;calls average function
		jmp 	.check_do
		
	.part_three:

		call 	matrix_mul										;calls matrix multiplication function
		jmp 	.check_do
		
	.part_four:

		call 	freq_table										;calls frequency table function
		jmp 	.check_do
		
	.check_do:
		
		mov		esp, ebp										;take down stack frame
		pop		ebp												;same as "leave" op
		
		mov		eax,0											;normal, no error, return value
		ret														;return
		
		
		
		
;==================================================================================================
;
;	E approximation
;
;==================================================================================================
	
calculate_e:
	
		push	ebp												;set up stack frame			
		mov		ebp,esp
		
		mov 	eax, 1											;set a, b, c to 1
		mov 	[a], eax
		mov 	[b], eax
		mov 	[c], eax
		
		fld 	qword [y]										;set y to 1
		fild	qword [one]
		faddp	
		fstp	qword [y]		
		
	.loop_e:
	
		push 	dword [a]										;prints the number of iteration
		push 	dword number
		call 	printf
		add 	esp, 8
		
		mov 	eax, [c]										;sets c equal to its previous value times a
		mov 	ebx, [a]										;effectively calculates a!
		mul		ebx
		mov		[c], eax	
		
		fld		qword [b]										;finds the inverse of a!
		fld		qword [c]
		fdivp
		fstp	qword [z]										;stores it in z
		
		;push 	dword [z+4]
		;push 	dword [z]
		;push 	dword print_flt_f
		;call 	printf
		;add 	esp, 12	
		
		mov		eax, [a]										;increments a
		inc	 	eax
		mov 	[a], eax
		
		fld		qword [z]										;adds z to y, the accumulated fraction
		fld		qword [y]
		faddp	
		fstp	qword [y]
		
		push 	dword [y+4]										;prints y as the sum of fractions so far
		push 	dword [y]
		push 	dword print_flt_s
		call 	printf
		add 	esp, 12
		
		fld		qword [e_6]										;prepares the actual value of e to 6 decimal places
		fstp	qword [e_6]
		
		push	dword [e_6+4]									;prints the actual value of e
		push	dword [e_6]
		push 	dword print_flt_e
		call	printf
		add		esp, 12
		
		fld		qword [e_6]										;subtracts y from the actual value of e, stores difference
		fld		qword [y]										;in the value of the variable e
		fsubp
		fstp	qword [e]
		
		push 	dword [e+4]										;prints the variable e, the difference between apprx and actual values of e
		push 	dword [e]
		push 	dword print_flt_d
		call 	printf
		add 	esp, 12
		
		fld		qword [prec]									;prepares the value of precision for writing
		fstp	qword [prec]
		
		push	dword [prec+4]									;displays precision value for comparison
		push	dword [prec]
		push 	dword print_flt_p
		call	printf
		add		esp, 12
		
		mov eax, [a]											;loops until precision is larger than the difference value
		mov ebx, 9
		cmp eax, ebx
		jl .loop_e
	
		mov		esp, ebp										;end function
		pop		ebp

		mov		eax,0
		ret
		
;==================================================================================================
;
;	Input Averaging
;
;==================================================================================================

average_nums:

		push	ebp
		mov		ebp,esp
		
		push 	dword get_name
		call 	printf
		add 	esp, 4
		
		push 	dword name_in
		push 	dword INPUT_str
		call 	scanf
		add 	esp, 8
		
		push 	dword name_in
		push 	dword hello
		call 	printf
		add 	esp, 8
		
		push 	dword instr_1
		call 	printf
		add 	esp, 4
		
		push 	dword instr_2
		call 	printf
		add 	esp, 4
		
		mov		ebx, 0
		mov		[sum], ebx
		mov		[num_temp], ebx
		mov		[counter], ebx
		
	.error:
		
		push 	dword instr_3
		call 	printf
		add 	esp, 4
		
	.prep_num:
		
		push 	dword instr_4
		call 	printf
		add 	esp, 4
		
		push 	num_temp
		push	INPUT_flt
		call 	scanf
		add 	esp, 8
		
		fld		qword [num_temp]
		fcomp	qword [upper_b]
		wait
		fstsw	ax
		sahf
		ja		.error
		
		fld		qword [num_temp]
		fcomp	qword [lower_b]
		wait
		fstsw	ax
		sahf
		jb		.end
		
		jmp		.get_num
		
	.get_num:
		
		fld		qword [sum]
		fadd 	qword [num_temp]	
		fstp	qword [sum]
		
		;push 	dword [sum+4]
		;push	dword [sum]
		;push	dword current_sum
		;call	printf
		;add		esp, 12
		
		mov		edx, [counter]
		inc		edx
		mov		[counter], edx
		
		jmp		.prep_num
		
	
	.end:
	
		
	
		push	dword [counter]
		push	dword show_count
		call	printf
		add		esp, 8
		
		xor		ah, ah
		
		mov		ebx, [counter]
		sub		ebx, 0
		jz		.bye
		
		fld		qword [sum]
		fild	qword [counter]
		fdivp	st1, st0
		fstp	qword [averageval]
		
		push	dword name_in
		push	dword [averageval+4]
		push	dword [averageval]
		push	dword avg
		call	printf
		add		esp, 16
		
	.bye:
	
		mov		eax, 0
		mov		[sum], eax
		mov		[averageval], eax
		mov		[num_temp], eax
		mov		[counter], eax
	
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	

;==================================================================================================
;
;	Matrix multiplication
;
;==================================================================================================

matrix_mul:
		
		push	ebp
		mov		ebp,esp
		
		push	dword dis_mat_1
		call	printf
		add		esp, 4
		
		push	dword [matrix_1+4]
		push	dword [matrix_1]
		push	dword [matrix_1+12]
		push	dword [matrix_1+8]
		push	dword [matrix_1+20]
		push	dword [matrix_1+16]
		push	dword [matrix_1+28]
		push	dword [matrix_1+24]
		push	dword print_array
		call	printf
		add		esp, 36
		
		push	dword dis_mat_2
		call	printf
		add		esp, 4
		
		push	dword [matrix_2+4]
		push	dword [matrix_2]
		push	dword [matrix_2+12]
		push	dword [matrix_2+8]
		push	dword [matrix_2+20]
		push	dword [matrix_2+16]
		push	dword [matrix_2+28]
		push	dword [matrix_2+24]
		push	dword print_array
		call	printf
		add		esp, 36
		
		mov		eax, 0
		mov		[counter], eax
		mov		[a_counter], eax
		mov		[c_counter], eax
		
	.b_set:	
		
		mov		eax, 0
		mov		[b_counter], eax
		
	.mul_loop:
	
		mov		eax, [a_counter]
		mov		ebx, [b_counter]
		mov		ecx, [c_counter]
		mov		edx, [counter]
		
		fld		qword [matrix_1+eax]
		fld		qword [matrix_2+ebx]
		fmulp	st1, st0
		fstp	qword [temp_matrix+ecx]
		
		;mov		[a_counter], eax
		;mov		[b_counter], ebx
		;mov		[c_counter], ecx
		;mov		[counter], edx
		
		;push	dword [a_counter]
		;push	dword [b_counter]
		;push	dword [c_counter]
		;push	dword [counter]
		;push	dword count_prt
		;call	printf
		;add		esp, 20
		
		;push	dword [temp_matrix+ecx+4]
		;push	dword [temp_matrix+ecx]
		;push	dword element_prt
		;call	printf
		;add		esp, 12

		mov		ebx, [b_counter]
		add		ebx, 8
		mov		[b_counter], ebx
		
		mov		ecx, [c_counter]
		add		ecx, 8
		mov		[c_counter], ecx
		
		
		
		mov		eax, [a_counter]
		mov		ebx, [b_counter]
		mov		ecx, [c_counter]
		mov		edx, [counter]
		
		fld		qword [matrix_1+eax]
		fld		qword [matrix_2+ebx]
		fmulp	st1, st0
		fstp	qword [temp_matrix+ecx]
		
		;mov		[a_counter], eax
		;mov		[b_counter], ebx
		;mov		[c_counter], ecx
		;mov		[counter], edx
		
		;push	dword [a_counter]
		;push	dword [b_counter]
		;push	dword [c_counter]
		;push	dword [counter]
		;push	dword count_prt
		;call	printf
		;add		esp, 20
		
		;push	dword [temp_matrix+ecx+4]
		;push	dword [temp_matrix+ecx]
		;push	dword element_prt
		;call	printf
		;add		esp, 12
		
		mov		eax, [a_counter]
		add		eax, 8
		mov		[a_counter], eax
		
		mov		ebx, [b_counter]
		add		ebx, 8
		mov		[b_counter], ebx
		
		mov		ecx, [c_counter]
		add		ecx, 8
		mov		[c_counter], ecx
		
		mov		edx, [counter]
		inc		edx
		mov		[counter], edx
		
		mov		eax, [counter]
		cmp		eax, 2
		je		.b_set
		
		
		mov		eax, [counter]
		cmp		eax, 4
		jne		.mul_loop
		
	.add_loop_set_all:
	
		mov		eax, 0
		mov		[counter], eax
		mov		[c_counter], eax
		mov		[d_counter], eax
		
		jmp		.add_loop
		
	.add_loop_set:
	
		mov		eax, 32
		mov		[c_counter], eax
		jmp		.add_loop
		
	.add_loop:
	
		mov		eax, [c_counter]
		mov		ebx, [c_counter]
		add		ebx, 16
		mov		ecx, [d_counter]
		mov		edx, [counter]
	
		fld		qword [temp_matrix+eax]
		fld		qword [temp_matrix+ebx]
		faddp
		fstp	qword [end_matrix+ecx]
		
		;push	dword [end_matrix+ecx+4]
		;push	dword [end_matrix+ecx]
		;push	dword element_prt
		;call	printf
		;add		esp, 12
		
		mov		eax, [c_counter]
		add		eax, 8
		mov		[c_counter], eax
		
		mov		ecx, [d_counter]
		add		ecx, 8
		mov		[d_counter], ecx
		
		mov		edx, [counter]
		inc		edx
		mov		[counter], edx
		
		mov		eax, [counter]
		cmp		eax, 2
		je		.add_loop_set
		
		mov		eax, [counter]
		cmp		eax, 4
		jne		.add_loop
		
		push	dword dis_mt_end
		call	printf
		add		esp, 4
		
		push	dword [end_matrix+4]
		push	dword [end_matrix]
		push	dword [end_matrix+12]
		push	dword [end_matrix+8]
		push	dword [end_matrix+20]
		push	dword [end_matrix+16]
		push	dword [end_matrix+28]
		push	dword [end_matrix+24]
		push	dword print_array
		call 	printf
		add		esp, 36
		
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	

;==================================================================================================
;
;	Frequency Table
;
;==================================================================================================

freq_table:

		push	ebp
		mov		ebp,esp
		
		mov		eax, 0
		
;=================================================
;	Manually input string
;=================================================
		
		
		
		mov		[cm_str+4*eax], byte 'A'
		inc		eax
		
		mov		[cm_str+4*eax], byte 'P'
		inc		eax
		
		mov		[cm_str+4*eax], byte 'P'
		inc		eax
		
		mov		[cm_str+4*eax], byte ' '
		inc		eax
		
		mov		[cm_str+4*eax], byte 'L'
		inc		eax
		
		mov		[cm_str+4*eax], byte 'E'
		inc		eax
		
		mov		[counter], eax
		
		
		push	dword label_string
		call	printf
		add		esp, 4
	
		
	.zero_table:
	
		mov		eax, [ft_counter]
		
		push	dword [cm_str+4*eax]
		push	dword cm_nos
		call	printf
		add		esp, 8
	
		fld		qword [zero_f]
		fstp	qword [frq_tab+4*eax]
		
		;push	dword [ft_counter]
		;push	dword number_ft
		;call	printf
		;add		esp, 8
		
		;push	dword [frq_tab+4*eax]
		;push	dword [frq_tab+4*(eax-1)]
		;push	dword frq_tab_prt
		;call	printf
		;add		esp, 12
		
		mov		eax, [ft_counter]
		inc		eax
		mov		[ft_counter], eax
	
		mov		eax, [counter]
		mov		ebx, [ft_counter]
		cmp		eax, ebx
		jne		.zero_table
		
	.calc_freqs:
	
		fild	qword [counter]
		fstp	qword [numletts]
	
		fld		qword [one_f]
		fdiv	qword [numletts]
		fstp	qword [frq_val_max]
		
		push	dword [frq_val_max+4]
		push	dword [frq_val_max]
		push	dword val_max_out
		call	printf
		add		esp, 12
		
		mov		eax, 0
		mov		[ft_counter], eax
		
	.check_alpha:
		
		mov		eax, [ft_counter]
		mov		esi, [cm_str+4*eax]
		
		mov		ecx, 0
		
		cmp 	esi, byte 'A'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'B'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'C'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'D'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'E'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'F'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'G'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'H'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'I'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'J'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'K'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'L'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'M'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'N'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'O'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'P'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'Q'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'R'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'S'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'T'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'U'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'V'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'W'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'X'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'Y'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte 'Z'
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx
		
		cmp 	esi, byte ' '
		mov		[thing], ecx
		je 		.set_table
		inc 	ecx

		jmp		.end
		
	.set_table:
	
		mov		eax, [ft_counter]
		
		push	dword [cm_str+4*eax]
		push	dword cm_str_out
		call	printf
		add		esp, 8
		
		
		;push	dword [thing]
		;push	dword OUTPUT_int
		;call	printf
		;add		esp, 8
		
		mov		eax, [thing]
		
		fld		qword [frq_tab+4*eax]
		fadd	qword [frq_val_max]
		fstp	qword [frq_tab+4*eax]
		
		mov		eax, [thing]
		
		push	dword [frq_tab+4*(eax+1)]
		push	dword [frq_tab+4*eax]
		push	dword frq_tab_prt
		call	printf
		add		esp, 12
		
		mov		eax, [ft_counter]
		inc		eax
		mov		[ft_counter], eax
		
		jmp 	.check_alpha
		
	.extra:
		
		mov		eax, 0
		mov		[ft_counter], eax
		
		jmp .extraloop
		
	.inc_ft:
	
		mov		eax, [ft_counter]
		inc		eax
		mov		[ft_counter], eax
		
		jmp .extraloop
		
	.extraloop:
		
		mov		eax, [ft_counter]
		
		mov		eax, [ft_counter]
		
		push	dword [ft_counter]
		push	dword number_ft
		call	printf
		add		esp, 8
		
		mov		eax, [ft_counter]
		
		push	dword [frq_tab+4*(eax+1)]
		push	dword [frq_tab+4*eax]
		push	dword frq_tab_prt
		call	printf
		add		esp, 12
		
		mov		eax, [ft_counter]
		inc		eax
		mov		[ft_counter], eax
		
		mov		eax, [ft_counter]
		cmp		eax, 27
		jne 	.extraloop
		
		
	.end:
		
		mov		esp, ebp
		pop		ebp

		mov		eax,0
		ret	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		