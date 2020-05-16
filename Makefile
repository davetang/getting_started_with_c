OUT = bin/
$(shell mkdir -p $(OUT))
CC = /usr/bin/gcc

# see https://randu.org/tutorials/c/intro.php
# compiler flags:
# -ansi: Use ANSI C
# -pedantic: Issue all warnings according to strict ANSI standard C
# -Wall: Turn on all Warnings. ALWAYS use this. You will benefit from it.
# -O2: Optimization Level 2, nearly all supported optimizations that do not involve a space-speed tradeoff are performed. Increases compilation time, but produces performance-enhanced code.
# -o: Specify output file to be created
CFLAGS = -ansi -pedantic -Wall -O2

all:
	$(CC) $(CFLAGS) input_output.c -o bin/choose_number
	$(CC) $(CFLAGS) command_line.c -o bin/command_line
	$(CC) $(CFLAGS) data_type.c -o bin/data_type
	$(CC) $(CFLAGS) function.c -o bin/function
	$(CC) $(CFLAGS) loop.c -o bin/loop
	$(CC) $(CFLAGS) read_file.c -o bin/read_file
	$(CC) $(CFLAGS) reference.c -o bin/ref
	$(CC) $(CFLAGS) sscanf.c -o bin/sscanf
	$(CC) $(CFLAGS) hello.c -o bin/say_hello
	$(CC) $(CFLAGS) cond.c -o bin/root_two
	$(CC) $(CFLAGS) switch_case.c -o bin/switch
	$(CC) $(CFLAGS) pointer.c -o bin/pointer
	$(CC) $(CFLAGS) structure.c -o bin/structure
clean:
	rm -rf bin

