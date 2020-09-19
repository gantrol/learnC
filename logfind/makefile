CC=cc
CFLAGS=-Wall -g -DNDEBUG
26: logfind.c
	${CC} ${CFLAGS} logfind.c   -o logfind
22: 22.c 22_main.c
	${CC} -c -o 22.o 22.c ${CFLAGS}
	${CC} 22_main.c 22.o   -o 22 ${CFLAGS}
clean:
	rm -f 22 22.o