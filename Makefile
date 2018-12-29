.PHONY: all clean re

all: main

main:
	g++ -std=c++11 -o main employee.cpp employee_test.cpp

clean:
	/bin/rm main

re: clean all
