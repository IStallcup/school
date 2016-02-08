SECTION .text

	global main
	
main:
		
		push ebp
		mov ebp, esp
		
		mov eax, 5
		mov ebx, 4
		
		add	eax, ebx
		mov ecx, eax
		
		mov eax, 0
		ret