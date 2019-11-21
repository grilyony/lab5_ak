all: compile run_test

compile:
	g++ -std=c++11 parse.cpp

run_test:
	./a.out --list --version=6 -V6 -hl -Cu --comment --update

clean:
	rm a.out
