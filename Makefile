CPPFLAGS = -Wall -Wpedantic -std=c++11

.PHONY: all clean re

all: main

main:
	g++ ${CPPFLAGS} -o main employee.cpp employee_test.cpp

clean:
	/bin/rm main

re: clean all
