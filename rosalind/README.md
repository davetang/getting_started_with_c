Rosalind is a platform for learning bioinformatics and programming through problem solving. Here I'll try to solve the [problems](http://rosalind.info/problems/list-view//) using C.

```
make
make clean
```

DNA

```
bin/count_nuc rosalind_dna.txt 
A C G T Skipped
262 241 255 236 0

time bin/count_nuc ~/genome/hg19.fa 
A C G T Skipped
844868045 585017969 585360436 846097277 234350394

real    1m20.365s
user    1m18.670s
sys     0m1.166s
```
