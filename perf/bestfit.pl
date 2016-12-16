#!/usr/bin/perl
use POSIX qw(pow);

while (<>) {
    if (/^([\d.]*) ([\d.]*)$/) {
        push @dps, [$1, $2]
    }
}

sub badness
{
    my ($a, $b) = @_;

    my $sum = 0;

    for my $dp (@dps) {
        $sum += pow($a + $b * exp($dp->[0]) - $dp->[1], 2.0);
        #print "$sum $a $b " . $dp->[0] . " " . $dp->[1] . "\n";
    }

    return $sum;
}

my $a = 1;
my $b = 0;

for (my $epsilon = .5; $epsilon > 1e-7; $epsilon *= .9999) {
    my $s1 = (rand()-.5);
    my $s2 = 1e-6 * (rand()-.5);
    if (rand() < .5) {
        $s1 = 0; 
    } else {
        $s2 = 0;
    }
    if (badness($a+$s1*$epsilon, $b+$s2*$epsilon) < badness($a, $b)) {
        $a += $s1*$epsilon;
        $b += $s2*$epsilon;
    }
}

print "$a + exp($b * x)\n"
