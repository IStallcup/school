.part_one:
		
		push dword p1									
		call printf
		add esp, 4
		
		mov al, 0
		mov [cc], al
		mov [aa], al
		mov [x], al
		
		mov al, 15
		mov [bb], al
		
	.make_array_one:
	
		mov eax, work_array
		mov ebx, [x]
		add eax, ebx
		mov eax, ebx
		mov [work_array], eax
		
		mov eax, [x]
		inc eax
		mov [x], eax
		
		mov ah, 16
		mov al, [x]
		cmp al, ah
		jl .make_array_one
		
		push dword original
		call printf
		add esp, 4
		
		mov eax, 0
		mov [x], eax
		
	.print_pre_swap:
		
		mov eax, work_array
		mov ebx, [x]
		add eax, ebx
		mov eax, ebx
		mov [work_array], eax
		
		mov eax, [x]
		inc eax
		mov [x], eax
		
		push dword [work_array]
		push dword OUTPUT
		call printf
		add esp, 8
		
		mov ah, 16
		mov al, [x]
		cmp al, ah
		jl .print_pre_swap		
		
		push dword swapped
		call printf
		add esp, 4
		
		mov eax, 0
		mov [x], eax
		mov [aa], eax
		mov [cc], eax
		
		mov eax, 15
		mov [bb], eax
		
	.swap:
		
		mov eax, work_array
		mov ebx, [x]
		add eax, ebx
		push eax
		
		push dword [x]
		push dword OUTPUT
		call printf
		add esp, 8
		
		;pop eax
		
		push dword eax
		push dword OUTPUT
		call printf
		add esp, 8
		
		mov eax, [x]
		inc eax
		mov [x], eax
		
		mov ah, 16
		mov al, [x]
		cmp al, ah
		jl .swap
		
		
		jmp .check_do
		
	.part_two:
		
		
		
	.part_three:
		
		mov eax, 0
		mov [x], eax
		
		.set_store:
			
			push dword [store]
			push dword OUTPUT
			call printf
			add esp, 8
		
		
		
			mov al, [x]
			inc al
			mov [x], al
			
			mov ah, 52
			mov al, [x]
			cmp al, ah
			jl .set_store
		
	.part_four:
		
		
		
		
		
		II:
		
		
		
		push dword string
		call printf
		add esp, 4
		
		mov eax, 0
		mov [x], eax
		
		.ver_loop:
			
			mov eax, [x]
			mov esi, dword [alpha + eax]
			
			
			
			push esi
			push dword OUTPUT_c
			call printf
			add esp, 8
			
			mov eax, [x]
			inc eax
			mov [x], eax
			
			mov eax, [x]
			cmp eax, LEN_alpha
			jne .ver_loop
			
		.end:
			
		mov eax, 0	
		mov [x], eax
		
		
		III:
		inc eax		
		mov [y], eax
		
		mov eax, 0
		mov [x], eax
		
		push dword shw_str
		call printf
		add esp, 4
		
		.show_string:
		
		mov eax, [x]
		mov esi, [alpha + 4*eax]
		mov [f_tab + 4*eax], esi
		
		push esi
		push dword OUTPUT_c
		call printf
		add esp, 8
		
		mov eax, 0
		mov [z], eax
		
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
		
		.post_inc:
		
		mov eax, [x]
		inc eax
		mov [x], eax
		
		mov eax, [x]
		mov ebx, [y]
		cmp eax, ebx
		jge .post_index
		jl .show_string
		
		.inc_table:
		
		mov edi, [z]
		push edi
		push OUTPUT
		call printf
		add esp, 8
		
		mov eax, [x]
		cmp eax, [y]
		je .post_index
		
		jmp .show_string
		
		.post_index: