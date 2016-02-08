Program: math.o
	gcc -m32 -o math math.o
math.o: math.asm
	nasm -f elf math.asm