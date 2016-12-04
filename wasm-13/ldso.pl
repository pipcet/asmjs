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

print "var dyninfo = {\n";

print "    ref: [\n";
my @l;
for my $symbol (keys %ref) {
    for my $addr (keys %{$ref{$symbol}}) {
        push @l, "\t[\"$symbol\", $addr]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "    def: [\n";
my @l;
for my $symbol (keys %def) {
    for my $addr (keys %{$def{$symbol}}) {
        push @l, "\t[\"$symbol\", $addr]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "    defun: [\n";
my @l;
for my $symbol (keys %defun) {
    for my $addr (keys %{$defun{$symbol}}) {
        push @l, "\t[\"$symbol\", $addr]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "};\n";

print <<"EOF";
let defun = {};
let def = {};
let ref = {};

for (let [symbol, addr] of dyninfo.def)
    def[symbol] = addr;
for (let [symbol, addr] of dyninfo.defun)
    defun[symbol] = addr;

for (let [symbol, addr] of dyninfo.ref) {
    if (symbol in def) {
        system.HEAPU32[addr>>2] = def[symbol];
    } else if (symbol in defun) {
        this.HEAPU32[addr>>2] = defun[symbol];
    } else {
        throw "unresolved reference";
    }
}
EOF
exit 0;
