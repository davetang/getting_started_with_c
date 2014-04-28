Learning how to code in C
--------------------

My repository for learning how to code in C.

To compile

`gcc input_output.c`

How to generate the files
--------------------

<code>
mysql --user=genome --host=genome-mysql.cse.ucsc.edu -A -e \
"select chrom, size from hg19.chromInfo"  > hg19.genome
randomBed -g hg19.genome -n 10 -seed 31 > random.bed
</code>
