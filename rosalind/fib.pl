#!/usr/bin/env perl

use strict;
use warnings;
use List::Util qw(sum);

my $usage = "Usage: $0 <n> <k>\n";
my $n = shift or die $usage;
my $k = shift or die $usage;

#first generation has one pair of babies
my @b = qw/1/;
my @a = qw/0/;

print "Generation 1\n";
print "\tAdults = $a[-1]\n";
print "\tBabies = $b[-1]\n";

for (my $i = 2; $i <= $n; ++$i){
   print "Generation $i\n";
   #adults produce k offspring
   my $nb = $a[-1] * $k;
   #babies become adults
   my $na = sum @b;
   print "\tAdults: $na\n";
   print "\tBabies: $nb\n";
   push(@a,$na);
   push(@b,$nb);
}

print "Adult: @a\n";
print "Baby:: @b\n";

my $total = $a[-1] + $b[-1];
print "$total\n";

exit(0);

