as4: as4.o
	gcc -g -m32 -o as4 as4.o
as4.o: as4.asm
	nasm -g -f elf as4.asm