CC=gcc
CFLAGS=-Wall -g -DNDEBUG
# 请注意，在编写Makefile时，顺序是重要的。特定的规则应该在它们可能被通用模式规则覆盖的地方之前给出。
8: 8_cond.c
	$(CC) ${CFLAGS} 8_cond.c -o 8
22: 22.c 22_main.c
	${CC} -c -o 22.o 22.c ${CFLAGS}
	${CC} 22_main.c 22.o   -o 22 ${CFLAGS}
%: %.c
	${CC} ${CFLAGS} $*.c -o $*
clean:
	rm -f 22 22.o 8 14 15
