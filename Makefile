CC = clang
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror

test: bloom.o test.o hash.o
	${CC} ${CFLAGS} -o $@ $^

test.o: bloom.h
bloom.o: bloom.h hash.h
hash.o: hash.h

clean:
	$(RM) test *.o