#!/usr/bin/env perl

use strict;
use warnings;

my $usage = "Usage: $0 <infile>\n";
my $infile = shift or die $usage;

my $f = '';
my $s = '';

open(IN,'<',$infile) || die "Could not open $infile: $!\n";
while(<IN>){
   chomp;
   if ($. == 1){
      $f = $_;
   } elsif ($. == 2){
      $s = $_;
   } else {
      die "More than two lines in $infile\n";
   }
}
close(IN);

my $ed = 0;
if (length($f) == length($s)){
   for (my $i = 0; $i < length($s); ++$i){
      my $fb = substr($f, $i, 1);
      my $sb = substr($s, $i, 1);
      ++$ed if $fb ne $sb;
   }
} else {
   die "Different lengths in the sequences\n";
}

print "$ed\n";

exit(0);
