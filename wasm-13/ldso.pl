#!/usr/bin/perl
use strict;

my $fh;
my %def;
my %defun;
my %ref;

for my $file (@ARGV) {
    open $fh, "./wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-objdump -T $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) g D ([a-zA-Z0-9._*]*) [0-9a-f]* ([a-zA-Z0-9_]*)$/) {
                my ($defaddr, $sec, $symbol) = (hex $1,$2,$3);
                my $is_function = $sec eq ".wasm.chars.function_index";

                next if $symbol =~ /^__/;

                if ($is_function) {
                    $defun{$symbol}{$defaddr} = 1;
                } else {
                    $def{$symbol}{$defaddr} = 1;
                }
            }
    }

    open $fh, "./wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-objdump -R $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) R_ASMJS_ABS32 +([a-zA-Z0-9_]*)$/) {
                my ($refaddr, $symbol) = (hex $1,$2);

                next if $symbol =~ /^__/;

                $ref{$symbol}{$refaddr} = 1;
            }
    }
}

print "{\n";

print "    ref: [\n";
for my $symbol (keys %ref) {
    for my $addr (keys %{$ref{$symbol}}) {
        print "\t[\"$symbol\", $addr],\n";
    }
}
print "    ],\n";

print "    def: [\n";
for my $symbol (keys %def) {
    for my $addr (keys %{$def{$symbol}}) {
        print "\t[\"$symbol\", $addr],\n";
    }
}
print "    ],\n";

print "    defun: [\n";
for my $symbol (keys %defun) {
    for my $addr (keys %{$defun{$symbol}}) {
        print "\t[\"$symbol\", $addr],\n";
    }
}
print "    ],\n";

print "}\n";
exit 0;
