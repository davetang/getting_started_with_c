#!/usr/bin/env perl

use strict;
use warnings;

my $usage = "Usage: $0 <infile.mfa>\n";
my $infile = shift or die $usage;

my $id = '';
my @id = ();
my %seq = ();

open(IN, '<', $infile) || die "Could not open $infile: $!\n";
while(<IN>){
   chomp;
   if (/^>(.*)/){
      $id = $1;
      push(@id, $id);
      next;
   } else {
      $seq{$id} .= $_;
   }
}
close(IN);

my $l = length($seq{$id[0]});

my $m = [];
for (my $i = 0; $i < $l; ++$i){
   $m->[$i][0] = 0;
   $m->[$i][1] = 0;
   $m->[$i][2] = 0;
   $m->[$i][3] = 0;
}

foreach my $id (keys %seq){
   for (my $i = 0; $i < length($seq{$id}); ++$i){
      my $n = substr($seq{$id}, $i, 1);
      if ($n eq 'A'){
         $m->[$i][0] += 1;
      } elsif ($n eq 'C'){
         $m->[$i][1] += 1;
      } elsif ($n eq 'G'){
         $m->[$i][2] += 1;
      } elsif ($n eq 'T'){
         $m->[$i][3] += 1;
      } else {
         die "Unrecognised letter: $n\n";
      }
   }
}

my @n = qw/A C G T/;
for (my $i = 0; $i < scalar(@{$m}); ++$i){
   my $max = 0;
   my $index = 0;
   for (my $n = 0; $n < 4; ++$n){
      if ($m->[$i][$n] > $max){
         $max = $m->[$i][$n];
         $index = $n;
      }
   }
   print "$n[$index]";
}
print "\n";

for (my $n = 0; $n < 4; ++$n){
   print "$n[$n]: ";
   for (my $i = 0; $i < scalar(@{$m}); ++$i){
      print "$m->[$i][$n] ";
   }
   print "\n";
}

exit(0);

