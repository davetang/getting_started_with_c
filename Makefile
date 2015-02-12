OUT = bin/
$(shell mkdir -p $(OUT))

all:
	gcc input_output.c -o bin/choose_number
	gcc command_line.c -o bin/command_line
	gcc data_type.c -o bin/data_type
	gcc function.c -o bin/function
	gcc loop.c -o bin/loop
	gcc read_file.c -o bin/read_file
	gcc reference.c -o bin/ref
	gcc sscanf.c -o bin/sscanf
 
clean:
	rm -rf bin
