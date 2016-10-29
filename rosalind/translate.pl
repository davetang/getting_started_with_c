#!/usr/bin/env perl

use strict;
use warnings;

my $usage = "Usage: $0 <infile.txt>\n";
my $infile = shift or die $usage;

open(IN, '<', $infile) || die "Could not open $infile: $!\n";
my $seq = '';
while(<IN>){
   chomp;
   $seq .= $_;
}
close(IN);

$seq = uc($seq);
$seq =~ s/U/T/g;

if ($seq !~ /^[ACGT]+$/i){
   die "Please input only RNA/DNA nucleotides\n";
}

my %genetic_code = init_genetic_code();
my $l = length($seq);

my $aa = '';
for (my $i = 0; $i < $l; $i += 3){
   my $s = substr($seq, $i, 3);
   my $a = codon2aa($s);
   $aa .= $a;
}

print "$aa\n";

sub codon2aa {
   my($codon) = @_;
   if(exists $genetic_code{$codon}) {
      return $genetic_code{$codon};
   } else {
      die "Unknown codon: $codon\n";
   }
}

sub init_genetic_code {
   my %g = (
       'TCA' => 'S',    # Serine
       'TCC' => 'S',    # Serine
       'TCG' => 'S',    # Serine
       'TCT' => 'S',    # Serine
       'TTC' => 'F',    # Phenylalanine
       'TTT' => 'F',    # Phenylalanine
       'TTA' => 'L',    # Leucine
       'TTG' => 'L',    # Leucine
       'TAC' => 'Y',    # Tyrosine
       'TAT' => 'Y',    # Tyrosine
       'TAA' => '_',    # Stop
       'TAG' => '_',    # Stop
       'TGC' => 'C',    # Cysteine
       'TGT' => 'C',    # Cysteine
       'TGA' => '_',    # Stop
       'TGG' => 'W',    # Tryptophan
       'CTA' => 'L',    # Leucine
       'CTC' => 'L',    # Leucine
       'CTG' => 'L',    # Leucine
       'CTT' => 'L',    # Leucine
       'CCA' => 'P',    # Proline
       'CCC' => 'P',    # Proline
       'CCG' => 'P',    # Proline
       'CCT' => 'P',    # Proline
       'CAC' => 'H',    # Histidine
       'CAT' => 'H',    # Histidine
       'CAA' => 'Q',    # Glutamine
       'CAG' => 'Q',    # Glutamine
       'CGA' => 'R',    # Arginine
       'CGC' => 'R',    # Arginine
       'CGG' => 'R',    # Arginine
       'CGT' => 'R',    # Arginine
       'ATA' => 'I',    # Isoleucine
       'ATC' => 'I',    # Isoleucine
       'ATT' => 'I',    # Isoleucine
       'ATG' => 'M',    # Methionine
       'ACA' => 'T',    # Threonine
       'ACC' => 'T',    # Threonine
       'ACG' => 'T',    # Threonine
       'ACT' => 'T',    # Threonine
       'AAC' => 'N',    # Asparagine
       'AAT' => 'N',    # Asparagine
       'AAA' => 'K',    # Lysine
       'AAG' => 'K',    # Lysine
       'AGC' => 'S',    # Serine
       'AGT' => 'S',    # Serine
       'AGA' => 'R',    # Arginine
       'AGG' => 'R',    # Arginine
       'GTA' => 'V',    # Valine
       'GTC' => 'V',    # Valine
       'GTG' => 'V',    # Valine
       'GTT' => 'V',    # Valine
       'GCA' => 'A',    # Alanine
       'GCC' => 'A',    # Alanine
       'GCG' => 'A',    # Alanine
       'GCT' => 'A',    # Alanine
       'GAC' => 'D',    # Aspartic Acid
       'GAT' => 'D',    # Aspartic Acid
       'GAA' => 'E',    # Glutamic Acid
       'GAG' => 'E',    # Glutamic Acid
       'GGA' => 'G',    # Glycine
       'GGC' => 'G',    # Glycine
       'GGG' => 'G',    # Glycine
       'GGT' => 'G',    # Glycine
   );
   return(%g);
}

exit(0);

