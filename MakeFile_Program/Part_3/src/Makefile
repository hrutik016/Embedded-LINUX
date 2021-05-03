all: Tooltip

Tooltip: main.c
	gcc -g -O0 -o $@ main.c

check all:
	./Tooltip  | grep "Hello from . *Tool tip!"
	@echo "*** ALL TEST PASSED ***"

install:
	cp  Tooltip /usr/bin
	chown root:root /usr/bin/Tooltip
	chmod +x /usr/bin/Tooltip

clean:
	rm -f Tooltip

.PHONY: all clean check install
