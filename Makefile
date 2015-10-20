CC = clang
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror

test: bloom.o test.o
	${CC} ${CFLAGS} -o $@ $^

test.o: bloom.h
bloom.o: bloom.h

clean:
	$(RM) test *.o