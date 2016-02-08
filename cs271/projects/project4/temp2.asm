mov ecx	, 0
		
		mov [alpha + 4 * ecx], byte 'A'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'B'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'C'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'E'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'E'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'F'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'F'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'E'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'R'
		add ecx, 1
		mov [alpha + 4 * ecx], byte 'S'
		add ecx, 1
		mov [alpha + 4 * eax], byte 'S'
		add ecx, 1
		
;		mov [alpha + 4*eax], byte 't'
;		inc ecx
		
;		mov [alpha + 4*eax], byte 'r'
;		inc ecx
		
;		mov [alpha + 4*eax], byte 'i'
;		inc ecx
		
;		mov [alpha + 4*eax], byte 'n'
;		inc ecx
		
;		mov [alpha + 4*eax], byte 'g'
;		inc ecx
		
;		mov [alpha + 4*eax], byte ' '
;		inc ecx
;		
;		mov [alpha + 4*eax], byte 'b'
;		inc ecx
;		
;		mov [alpha + 4*eax], byte 'e'
;		inc ecx
;		
;		mov [alpha + 4*eax], byte 'a'
;		inc ecx
;		
;		mov [alpha + 4*eax], byte 'n'
;		inc ecx
;		
		mov [z], ecx

	.print_table:
	
		mov eax, [y]
		push dword [alpha + 4*eax]
		push dword OUTPUT_c
		call printf
		add esp, 8
		
		mov ebx, 0
		mov [x], ebx
		
		mov eax, [y]
		inc eax
		mov [y], eax
		mov eax, [y]
		mov ebx, [z]
		cmp eax, ebx		
		jl .print_table
		
		mov eax, 0
		mov [y], eax
	
		mov eax, 0
		mov ecx, 0
		
		.count_loop:
		
		mov ecx, [x]
		mov ecx, dword [alpha + 4*ecx]
		add [f_tab + 4*ecx], dword 1
		
		
		push dword [alpha + 4*ecx]
		push dword [f_tab + 4*ecx]
		push dword finalprint
		call printf
		add esp, 12
		
		mov ecx, [x]
		inc ecx
		mov [x], ecx
		mov ebx, [z]
		cmp dword [x], ebx
		jne .count_loop
		
		mov eax, 0
		mov [y], eax
		mov eax, 0