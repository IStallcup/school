p5prg: p5.asm
	nasm  -f elf -l p5.lst p5.asm
	gcc  -m32 -o p5 p5.o
#Program: p5.o
#	gcc -m32 -o p5 p5.o
#p5.o: p5.asm
#	nasm -f elf p5.asm