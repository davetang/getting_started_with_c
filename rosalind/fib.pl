#!/usr/bin/env perl

use strict;
use warnings;
use List::Util qw(sum);

# where n = months
# where k = size of litter
my $usage = "Usage: $0 <n> <k>\n";
my $n = shift or die $usage;
my $k = shift or die $usage;

# first generation produces a pair of offspring
# @a stores number of newly matured rabbits
# @b stores number of new premature rabbits
my @a = (0);
my @b = (1);

# after the first generation
print "Generation 1\n";
# last element of arrays
print "\tMature = $a[-1]\n";
print "\tImmature = $b[-1]\n";

for (my $i = 2; $i <= $n; ++$i){
   print "Generation $i\n";

   # sexually mature rabbits produce k offspring
   my $nb = $a[-1] * $k;

   # all premature rabbits become sexually mature
   my $na = sum @b;

   print "\tMature: $na\n";
   print "\tImmature: $nb\n";

   push(@a, $na);
   push(@b, $nb);
}

print "Mature:   @a\n";
print "Immature: @b\n";

my $total = $a[-1] + $b[-1];
print "$total\n";

# method two using an array of array
my $gen = [];

# generation 0 has 1 pair of sexually mature rabbits
$gen->[0][0] = 1;
# generation 0 has no premature rabbits
$gen->[0][1] = 0;

for (my $i = 1; $i < $n; ++$i){
   # sexually mature rabbits from previous generation
   # can reproduce to produce offspring
   my $offspring = $gen->[$i-1][0] * $k;

   # mature rabbits = mature rabbits + premature rabbits
   # from previous generation
   $gen->[$i][0] = $gen->[$i-1][0] + $gen->[$i-1][1];

   # premature rabbits = the offspring of this generation
   $gen->[$i][1] = $offspring;
}

for (my $i = 0; $i < scalar(@{$gen}); ++$i){
   print "Generation $i: $gen->[$i][0] $gen->[$i][1]\n";
}

# minus one because I counted from zero
# minus another one because at generation $n
# rabbits have not multiplied yet
my $rabbits = $gen->[$n-2]->[0] + $gen->[$n-2]->[1];
print "There are $rabbits rabbits in generation $n\n";

exit(0);

