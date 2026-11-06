bcc -ansi -c -o tstpr1.o tstpr1.c

bcc -ansi -c -o tstpr2.o tstpr2.c

as86 -o userlib.o userlib.asm

ld86 -d -o tstpr1 tstpr1.o userlib.o

ld86 -d -o tstpr2 tstpr2.o userlib.o

bcc -ansi -c -o kernel_c.o kernel.c

as86 kernel_asm.s -o kernel_asm.o

ld86 -o kernel -d kernel_c.o kernel_asm.o

bcc -ansi -c -o shell_c.o shell.c

as86 userlib.asm -o  userlib_asm.o

ld86 -o shell -d shell_c.o userlib_asm.o

gcc -o loadFile loadFile.c

./loadFile kernel
./loadFile shell
#./loadFile messag.txt
./loadFile tstpr1
./loadFile tstpr2
