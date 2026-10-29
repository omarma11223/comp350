


bcc -ansi -c -o kernel_c.o kernel.c

as86 kernel_asm.s -o kernel_asm.o

ld86 -o kernel -d kernel_c.o kernel_asm.o

gcc -o loadFile loadFile.c

./loadFile kernel
./loadFile messag.txt

