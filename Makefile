CC = clang
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror

test: test.o bloom.o hash.o
	${CC} ${CFLAGS} -o $@ $^

test.o: bloom.h main.h
bloom.o: bloom.h hash.h main.h
hash.o: hash.h main.h

clean:
	$(RM) test *.o