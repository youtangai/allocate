.PHONY: clean

allocate: allocate.c
	gcc -o allocate -Wall allocate.c

clean:
	rm -f allocate