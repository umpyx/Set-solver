INSTALLDIR=/usr/bin/


all: SetSolver test

SetSolver: main.c main.h
	gcc -Wall -Wextra -Wpedantic -o test/SetSolver -g main.c

test:
	test/SetSolver

release: main.c main.h
	gcc -o release/SetSolver -03 main.c
	
install: release
	install -m 755 -t $(INSTALLDIR) release/SetSolver

