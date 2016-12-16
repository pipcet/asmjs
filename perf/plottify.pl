#!/usr/bin/perl
use POSIX qw(pow exp);

while (<>)
{
    if (/^([\d.]*)/) {
        push @vs, $1 if ($1 != 0.0);
    }
}

for (my $x = 0.0; $x < 30.0; $x += .01) {
    my $y = 0.0;

    for my $v (@vs) {
        $y += exp(-pow($x-$v, 2.0));
    }

    print "$x $y\n";
}
