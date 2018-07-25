.PHONY: clean build

allocate: allocate.c
	gcc -o allocate -Wall allocate.c

clean:
	rm -f allocate

build:
	docker build -t yotanagai/allocate:test .
