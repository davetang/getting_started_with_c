#!/usr/bin/env perl

use strict;
use warnings;
use bignum;

# where n = months
# where m = life expectancy
my $usage = "Usage: $0 <n> <m>\n";
my $n = shift or die $usage;
my $m = shift or die $usage;

# size of litter
my $k = 1;

my $gen = [];

# initialise
# no sexually mature rabbits
$gen->[0][0] = 0;
# one pair of premature rabbits
$gen->[0][1] = 1;

for (my $i = 1; $i < $n; ++$i){
   my $death = 0;

   # a rabbit, from prematurity to maturity, lives for $m months
   # for example, if $m=3, the first time this condition is true
   # is when it's generation 4, the premature rabbits from generation zero will die
   if ($i >= $m){
      $death = $gen->[$i - $m][1];
   }

   # number of mature from last generation
   my $mature = $gen->[$i-1][0];

   # number of premature from last generation
   my $premature = $gen->[$i-1][1];

   # sexually mature rabbits from previous generation
   # can reproduce to produce offspring for this generation
   my $offspring = $mature * $k;

   # total mature rabbits = mature rabbits + premature rabbits
   # from previous generation - premature rabbits that reached $m
   $gen->[$i][0] = $mature + $premature - $death;

   # premature rabbits = the offspring of this generation
   $gen->[$i][1] = $offspring;

}

for (my $i = 0; $i < scalar(@{$gen}); ++$i){
   print "Generation $i: $gen->[$i][0] $gen->[$i][1]\n";
}

# minus one because I counted from zero
my $rabbits = $gen->[$n-1]->[0] + $gen->[$n-1]->[1];
print "There are $rabbits rabbits in generation $n\n";

exit(0);

