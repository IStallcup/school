; Name:	
; Creation date: 	2/4/15
; Last modified: 	2/8/15
;
; Name of file: a4.asm
; Description: The user can select between: Reversing an array, rotate an array's values left or right,  create a frequency table for a string, or input an integer and receiving list of prime numbers up to that integer.
;
; Assemble:	nasm -f elf a4.lst a4.asm
; Link:		gcc -m32 -o a4  a4.o
; Run:		a4
; Output:	Dependant on which function the user selects. 
;			
; Equivalent C code:
;#include <math.h>
;#include <stdlib.h>
;#include <stdio.h>
;int myarray[10];
;void initarray(){
;   printf( "got to initarray\n");
;   int i = 0;
;   int j = 0;
;	for (i = 0; i < 10; i++){		
;    myarray[i] = i;
;	}
;}
;void swap(){
;   printf( "got to swap \n");
;   int temp;
;   int a = 0;
;   int b = 9;
;   int i = 0;
;   for(i = 0; i < 5; i++){  
;       temp = myarray[a];
;       myarray[a] = myarray[b];
;       myarray[b] = temp;
;       a++;
;       b--;
;   } 
;}
;void rotate(){
;  int i = 0;
;  int temp = 0;
;  int a = 0;
;  int b = 9;
;  printf("got to rotate\n");
; for(i = 0; i < 10; i++){
;    temp = myarray[a];
;    myarray[a] = myarray[b];
;    myarray[b] = temp;
;    a++;
;    b++;
;    b%9;
;    printf("rotated values are %d \n at postion: %d \n", myarray[i], i+1);
; }
;}
;void frequency(){
;   char string[100];
;   int c = 0, count[26] = {0};
;    printf("Enter string (lower case and no spaces please) \n");
;   scanf("%s", &string);
;   if (string[c] < 'a' || string[c] > 'z'){
;    printf("Contains a non lower case letter or space. Ending program.\n");
;  }
;   while ( string[c] != '\0' )
;   { 
;      if ( string[c] >= 'a' && string[c] <= 'z' ) 
;         count[string[c]-'a']++; 
;      c++;
;   }
;   for ( c = 0 ; c < 26 ; c++ )
;   {
;      if( count[c] != 0 )
;         printf("%c occurs %d times in the entered string.\n",c+'a',count[c]);
;   }
;}
;void sieve(){
;   int i;
;   int j;
;   int numbers[100];
;   int primes[25];
;    for (i=0;i<100;i++){
;        numbers[i]=i+2;
;    }
;    for (i=0;i<100;i++){
;        if (numbers[i]!=-1){
;            for (j=2*numbers[i]-2;j<100;j+=numbers[i])
;                numbers[j]=-1;
;        }
;    }
;    j = 0;
;    for (i=0;i<100&&j<25;i++)
;        if (numbers[i]!=-1)
;            primes[j++] = numbers[i];
;    for (i=0;i<25;i++)
;        printf("%d \n",primes[i]);
;}
;void one(){
;   int i;
;   int j; 
;   initarray();
;    for(j = 0; j < 10; j++){    
;    printf( "array: %d \n at postion: %d \n", myarray[j], j + 1);    
;    }
;   swap(); 
;    for(i = 0; i < 10; i++){
;    printf( "swapped values are %d\n at postion: %d \n", myarray[i], i + 1);
;   }
;}
;void two(){
;int i = 0;
;initarray();
;for(i = 0; i < 10; i++){
;    printf( "values start as: %d \n", myarray[i]);
;   }
;rotate();
;}
;void three(){
;  frequency();
;}
;void four(){
;  sieve();
;}
;
;void end(){
;}
;int main(){
;   int i;
;   int choice = 0;
;   while(choice > 5 || choice < 1){   
;   printf( "Please enter which part you wish to do. 1-4 \n");
;   scanf( "%d", &choice);
;   }
;  if(choice == 1){
;	   printf("got to choice 1\n");
;      one();
;   }
;  else if(choice == 2){
;    printf("got to choice 2 \n");
;    two();
;   }
;
;  else if(choice == 3){
;    printf("got to choice 3 \n");
;    three();
;   }
;  else if(choice == 4){
;    printf("got to choice 4 \n");
;    four();
;   }
;   return 0;
;}
;
; Declare needed external functions
;
	extern printf
	extern scanf
	
SECTION .data				; Data section, initialized variables
	
	;; MESSAGE STATEMENTs
	print1: 		db	10, 10, "Welcome to my cs271 assignment4 program", 10, 0		; welcome
	instructions:		db 	10, "1 to reverse an array in place.", 10, "2 to shift values in an array", 10, "3 to create a frequency table.", 10, "or 4 to do the Sieve of Eratosthenes.", 10, 10, 0
	input1:	db 	"Please enter an integer (1-4): ", 0
	originalarray:		db 	"array before reverse: ", 0
	reversedarray:	db	"array after reverse: ", 0
	norotation:	db	"original array: ", 0
	rotatedarray:	db  "array after rotation: ", 0
	shift:	db 	"Which direction do you want? (0 for left and 1 for right): ", 0
	stringmess: db "String is: ", 0
	
	;; ERRORs AND FMTs
	error1:		db  "error - your input is invalid", 10, 10, 0
	line:	db 	" ", 10, 0
	test:	db 	10, "test", 10, 0
	int: 	db 	"%d", 0 
	ints:	db 	"%d ", 0
	stringp: db "%c ", 0
	stringprint: db "%s", 0
	tablep: db "Table is: ", 0
	tableprint: db "%d ",  0
	finalprint: db "Amount: %d Letter: %c", 10, 0
	
	;; ARRAYs AND INDEXs
	intarray:	dd	1, 2, 3, 4, 5, 6, 7, 8, 9, 10	
	size:	dd 	10
	counter:	dd	0
	last:	dd	4
	
SECTION .bss				; BSS, uninitialized variables
	
	input: resd 1 		; input int
	temp: resd 1		; temp holder for rotate function
	primearray: resd 20
	table: resd 128
	string: resd 10
	count2: resd 1
		
SECTION .text				; Code section.
	
	global main				; declare global start
	global reverse			; and functions as global
	global rotation
	global freqTable
	global printPrimes
		
	main:	
		push	ebp			; set up stack frame
		mov		ebp,esp

		push dword print1		; print1 msg
		call printf
		add esp, 4
		jmp .clear

	;clears array in case user started another function involving int array
	.clear: 
		mov eax, [counter]
		add eax, 1					; resets array to original values 
		mov [counter], eax			; 
		jmp .input1
	
	; input function
	.input1:	
		push dword instructions		; instructions statements
		call printf
		push dword input1		; "Please enter an int (1-4): "
		call printf
		add esp, 8
		
		push dword input
		push dword int		; get an int for function selection
		call scanf
		add esp, 8
		
		mov eax, [input]
		cmp eax, 1
		je .reverse				; enter REVERSE ARRAY function
		
		mov eax, [input]
		cmp eax, 2
		je .rotation			; enter ROTATE ARRAY function
		
		mov eax, [input]
		cmp eax, 3
		je .frequency			; enter FREQ TABLE function
		
		mov eax, [input]
		cmp eax, 4
		je .primes				; enter PRIME NUMBERS function
		
		push dword error1		
		call printf				; error message and jump to re-enter input
		add esp, 4
		jmp .input1		
	
	; function switch statement
	.reverse:					; these are the function calls (1-4)
		call reverse
		jmp .end
	.rotation:
		call rotation
		jmp .end
	.frequency:
		call freqTable
		jmp .end
	.primes:
		call printPrimes
		jmp .end

	;ends program
	.end:
		mov		esp, ebp		; takedown stack frame
		pop		ebp				; same as "leave" op
		mov		eax,0			; normal, no error, return value
		ret						; return	
	
	;-------------
	; FUNCTIONS	
	;-------------
	
	; simply reverses the array intarray
	reverse:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		push dword line
		call printf
		push dword originalarray	
		call printf			; "original array: "
		add esp, 8
		
		mov eax, 0
		mov [counter], eax			; reset counter = 0
		call printArray				; print array before reverse
		
		push dword line
		call printf
		push dword reversedarray	
		call printf					; "Array after reverse: "
		add esp, 8
		
		mov eax, 0
		mov [counter], eax			; reset counter = 0
		mov eax, 9
		mov [last], eax		; reset last index counter
		call revArr					; reverse the array
		
		mov eax, 0
		mov [counter], eax			; reset [counter] = 0
		call printArray			; print array after reverse
		
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
	ret						; return	
	
	; prints intarray
	printArray:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		.printLoop:	
			mov eax, [counter]			; counter into eax
			mov eax, dword [intarray + 4*eax]
			push eax
			push dword ints
			call printf					; 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
			add esp, 8
			
			mov eax, [counter]
			add eax, 1					; inc array counter 
			mov [counter], eax			; safe keeping
		
			mov eax, [counter]
			cmp eax, [size]					; loops
			jne .printLoop
	
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
	ret					; return
	
	; actually reverses intarray
	revArr:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		.revArr:				
			mov eax, [counter]
			mov esi, dword[intarray + 4*eax]			; set esi to array's "next" value based off the loop counter		
			mov ebx, [last]
			mov edi, dword[intarray + 4*ebx]			; set edi to arrays "next" value from the back
	
			push esi
			push edi			; switch edi and edi values
			pop esi
			pop edi
			
			mov eax, [counter]
			mov dword [intarray + 4*eax], esi
			mov ebx, [last]
			mov dword[intarray + 4*ebx], edi		; set edi to arrays "next" value from the back
			
			mov eax, [last]
			sub eax, 1
			mov [last], eax			; dec back index
			mov eax, [counter]
			add eax, 1						; inc front index
			mov [counter], eax
			
			cmp eax, 2		;
			jne .revArr
	
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
	ret					; return
	
	; rotates the array left or right based on user input
	rotation:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		push dword line			; new line
		call printf
		push dword norotation		; "original array: "
		call printf
		add esp, 8
		
		mov eax, 0
		mov [counter], eax			; reset counter = 0
		call printArray				; print array before reverse
		
		; get input for left or right
		push dword line
		call printf
		push dword line
		call printf
		
		.getInput:
		push dword shift
		call printf					; 0=left, 1=right
		add esp, 12
		
		push dword input			; get input
		push dword int
		call scanf
		add esp, 8
		
		; jump to correct rotation call
		mov eax, [input]
		cmp eax, 0
		je .left					; jump to leftRotation call
		
		mov eax, [input]
		cmp eax, 1
		je .right					; jump to rightRotation call
		
		push dword error1			; input != 0 OR 1  ...  jump to getInput
		call printf
		add esp, 4
		jmp .getInput
		
		; rotate left or right
		.left:
			call rotLeft
			jmp .postRot
		.right:
			call rotRight
			jmp .postRot
		
		; prints final array
		.postRot:
			push dword line			; new line
			call printf
			push dword rotatedarray		; "original array: "
			call printf
			add esp, 8
			
			mov eax, 0
			mov [counter], eax			; reset counter = 0
			call printArray				; print array before reverse
	
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
	ret					; return
	
	; rotate intarray left
	rotLeft:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		mov eax, 0
		mov [counter], eax		; reset loop counter to zero
		mov eax, dword [intarray + 4*eax]		
		mov [temp], eax				; initialize temp to hold first value in array		
		
		.leftLoop:	
			mov eax, [counter]
			mov esi, dword [intarray + 4*eax]		; esi holds value in array		
			inc eax								
			mov edi, dword[intarray + 4*eax]		; edi holds following value in array
	
			push esi
			push edi			; switch edi and edi values
			pop esi
			pop edi
			
			mov eax, [counter]
			mov dword [intarray + 4*eax], esi
			inc eax
			mov dword[intarray + 4*eax], edi
			
			mov eax, [counter]
			add eax, 1					; inc array counter 
			mov [counter], eax			; safe keeping
		
			mov eax, [counter]
			cmp eax, 9					; loop 10 times
			jne .leftLoop
		
		mov eax, [counter]
		mov ebx, [temp]					; wrap around (set last value)
		mov dword [intarray + 4*eax], ebx
		
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
	ret					; return
	
	; rotate intarray right
	rotRight:
		push	ebp			; set up stack frame
		mov		ebp,esp
		
		mov eax, 9
		mov [counter], eax		; reset loop counter to zero
		mov eax, dword [intarray + 4*eax]		
		mov [temp], eax				; initialize temp to hold last value in array		
		
		.rightLoop:	
			mov eax, [counter]
			mov esi, dword [intarray + 4*eax]		; esi holds value in array		
			dec eax								
			mov edi, dword[intarray + 4*eax]		; edi holds previous value in array
	
			push esi
			push edi			; switch edi and edi values
			pop esi
			pop edi
			
			mov eax, [counter]
			mov dword [intarray + 4*eax], esi
			dec eax
			mov dword[intarray + 4*eax], edi
			
			mov eax, [counter]
			sub eax, 1					; inc array counter 
			mov [counter], eax			; safe keeping
		
			mov eax, [counter]
			cmp eax, 0					; loop 10 times
			jne .rightLoop
		
		mov eax, [counter]
		mov ebx, [temp]					; wrap around (set last value)
		mov dword [intarray + 4*eax], ebx
		
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
	ret					; return
	
	; create a frequency table from a char array
	freqTable:
		push	ebp			; set up stack frame
		mov		ebp,esp
	
	.manualfill:
		mov ecx, 0
		
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
		mov [string + 4 * ecx], byte 'F'
		add ecx, 1
		mov [string + 4 * ecx], byte 'F'
		add ecx, 1
		mov [string + 4 * ecx], byte 'E'
		add ecx, 1
		mov [string + 4 * ecx], byte 'R'
		add ecx, 1
		mov [string + 4 * ecx], byte 'S'
		add ecx, 1

	push tablep
	call printf
	add esp, 4

	.tableprint:
		mov eax, [count2]
		push dword [table + 4 * eax]
		push dword tableprint
		call printf
		add esp, 8

		mov ebx, 0
		mov [counter], ebx

		mov eax, [count2]
		inc eax
		mov [count2], eax
		cmp dword [count2], 10
		jl .tableprint
		mov eax, [count2]
		mov eax, 0
		mov [count2], eax

	.zero:
		mov eax, 0
		mov ecx, 0

		push dword stringmess
		call printf
		add esp, 4
		jmp .originprint

	.originprint:
		mov eax, [count2]
		push dword [string + 4 * eax]
		push dword stringp
		call printf
		add esp, 8

		mov ebx, 0
		mov [counter], ebx

		mov eax, [count2]
		inc eax
		mov [count2], eax
		cmp dword [count2], 10
		jl .originprint

	.counts:
		push dword test
		call printf
		add esp, 4

		mov ecx, [counter]
		mov ecx, dword [string + 4 * ecx]
		add [table + 4 * ecx], dword 1
		jmp .printstatement

	.printstatement:
		push dword [table + 4 * ecx]
		push dword [string + 4 * ecx]
		push dword finalprint
		call printf
		add esp, 12

	.incloop:
		mov ecx, [counter]
		inc ecx
		mov [counter], ecx
		cmp dword [counter], 10
		jne .counts
		mov eax, 0
		mov [count2], eax
		mov eax, 0
		jmp .tabletest

	.tabletest:
		mov eax, [count2]

		push dword tablep
		call printf
		add esp, 4

		push dword [table + 4 * eax]
		push dword tableprint
		call printf
		add esp, 8

		mov ebx, 0
		mov [counter], ebx

		mov eax, [count2]
		inc eax
		mov [count2], eax
		cmp dword [count2], 128
		jl .tabletest
		jmp .end


	.end:
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
		ret					; return
	
	printPrimes:
		push	ebp			; set up stack frame
		mov		ebp,esp


	.end:
		mov		esp, ebp	; takedown stack frame
		pop		ebp			; same as "leave" op
		mov		eax,0		; normal, no error, return value
		ret					; return