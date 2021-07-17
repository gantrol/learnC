CC=cc
CFLAGS=-Wall -g -DNDEBUG
8: 8_cond.c
	$(CC) -Wall -g 8_cond.c -o 8
22: 22.c 22_main.c
	${CC} -c -o 22.o 22.c ${CFLAGS}
	${CC} 22_main.c 22.o   -o 22 ${CFLAGS}
clean:
	rm -f 22 22.o 8