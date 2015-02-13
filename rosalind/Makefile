OUT = bin/
$(shell mkdir -p $(OUT))

all:
	gcc dna.c -o bin/count_nuc
	gcc rna.c -o bin/dna_to_rna
	gcc revcom.c -o bin/revcom
 
clean:
	rm -rf bin
