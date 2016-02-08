.zero_table:
	
		mov		eax, 0
		mov		[ft_counter], eax
		
		mov		eax, [ft_counter]
	
		push	dword [cm_str+4*eax]
		push	dword cm_str_out
		call	printf
		add		esp, 8
	
		fld		qword [zero_f]
		fstp	qword [frq_tab+4*eax]
		
		push	dword [ft_counter]
		push	dword number_ft
		call	printf
		add		esp, 8
		
		push	dword [frq_tab+4*eax]
		push	dword [frq_tab+4*(eax-1)]
		push	dword frq_tab_prt
		call	printf
		add		esp, 12
		
		mov		eax, [ft_counter]
		inc		eax
		mov		[ft_counter], eax
		
		push	dword [counter]
		push	dword numma
		call	printf
		add		esp, 8	
	
		mov		eax, [counter]
		mov		ebx, [ft_counter]
		cmp		eax, ebx
		;jne		.zero_table
		
		
		