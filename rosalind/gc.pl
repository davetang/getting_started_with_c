#!/usr/bin/env perl

use strict;
use warnings;

my $usage = "Usage: $0 <infile>\n";
my $infile = shift or die $usage;

my %seq = ();
my $cur = '';
my @id = ();

open(IN,'<',$infile) || die "Could not open $infile: $!\n";
while(<IN>){
   chomp;
   if (/^>(.*)$/){
      $cur = $1;
      push(@id, $cur);
   } else {
      $seq{$cur} .= $_;
   }
}
close(IN);

foreach my $id (@id){
   my $per = gc($seq{$id});
   print "$id\n$per\n";
}

sub gc {
   my ($seq) = @_;
   $seq = uc($seq);
   my $gc = 0;
   my $total = 0;
   for(my $i=0; $i<length($seq); ++$i){
      my $s = substr($seq,$i,1);
      if ($s eq 'G' || $s eq 'C'){
         ++$gc;
      }
      ++$total;
   }
   my $per = $gc * 100 / $total;
   return($per);
}

exit(0);

