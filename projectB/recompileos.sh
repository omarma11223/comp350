dd if=/dev/zero of=diskc.img bs=512 count=1000

dd if=bootload of=diskc.img bs=512 count=1 conv=notrunc


