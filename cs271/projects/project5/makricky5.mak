ricky5: ricky5.asm
	nasm -f elf -l ricky5.lst  ricky5.asm
	gcc -m32 -o ricky5 ricky5.o