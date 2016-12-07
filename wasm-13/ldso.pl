#!/usr/bin/perl
use strict;

my $fh;
my %def;
my %defun;
my %ref;
my %refun;
my %fixup;
my %fixupfun;
my $plt_bias;
my $plt_end;
my $data;
my $data_end;

for my $file (@ARGV) {
    open $fh, "./wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-objdump -T $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) g D ([a-zA-Z0-9._*]*) [0-9a-f]* (\.protected |\.hidden )*([a-zA-Z0-9_\$]*)$/) {
                my ($defaddr, $sec, $symbol) = (hex $1, $2, $4);
                my $is_function = $sec eq ".wasm.chars.function_index";

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
            if (/^([0-9a-f]*) R_ASMJS_ABS32 +([a-zA-Z0-9_\$]*)$/) {
                my ($refaddr, $symbol) = (hex $1,$2);

                $ref{$symbol}{$refaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_ABS32 \*ABS\*\+0x([0-9a-f]*)$/) {
                my ($refaddr, $defaddr) = (hex $1, hex $2);

                $fixup{$refaddr}{$defaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_ABS32 ([a-zA-Z0-9_\$]*)\+0x([0-9a-f]*)$/) {
                my ($refaddr, $defaddr) = (hex $1, hex $3);

                $fixup{$refaddr}{$defaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_LEB128_PLT_INDEX ([a-zA-Z0-9_\$]*)$/) {
                my ($refaddr, $symbol) = (hex $1,$2);

                $refun{$symbol}{$refaddr} = 1;
            }
    }

    open $fh, "./wasm32-virtual-wasm32/bin/wasm32-virtual-wasm32-objdump -t $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) g ([a-zA-Z0-9._*]*) [0-9a-f]* ([a-zA-Z0-9_.\$]*)$/) {
                my ($value, $symbol) = (hex $1,$3);

                if ($symbol eq ".wasm.plt_bias") {
                    $plt_bias = $value;
                } elsif ($symbol eq ".wasm.plt_end") {
                    $plt_end = $value;
                } elsif ($symbol eq ".wasm.data") {
                    $data = $value;
                } elsif ($symbol eq ".wasm.data_end") {
                    $data_end = $value;
                }
            }
    }
}

print "var dyninfo; dyninfo = {\n";

print "    ref: [\n";
my @l;
for my $symbol (keys %ref) {
    for my $addr (keys %{$ref{$symbol}}) {
        push @l, "\t[\"$symbol\", $addr]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "    refun: [\n";
my @l;
for my $symbol (keys %refun) {
    for my $addr (keys %{$refun{$symbol}}) {
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

print "    fixup: [\n";
my @l;
for my $addr1 (keys %fixup) {
    for my $addr2 (keys %{$fixup{$addr1}}) {
        push @l, "\t[$addr1, $addr2]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "    fixupfun: [\n";
my @l;
for my $addr1 (keys %fixupfun) {
    for my $addr2 (keys %{$fixupfun{$addr1}}) {
        push @l, "\t[$addr1, $addr2]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "    plt_bias: $plt_bias,\n";
print "    plt_end: $plt_end,\n";
print "    data: $data,\n";
print "    data_end: $data_end\n";
print "};\n";


print <<"EOF" if 0;
let defun = {};
let def = {};
let ref = {};

for (let [symbol, addr] of dyninfo.def)
    def[symbol] = addr;
for (let [symbol, addr] of dyninfo.defun)
    defun[symbol] = addr;

for (let [symbol, addr] of dyninfo.ref) {
    if (symbol in def) {
        this.HEAPU32[addr>>2] = def[symbol];
    } else if (symbol in defun) {
        this.HEAPU32[addr>>2] = defun[symbol];
    } else {
        throw "unresolved reference";
    }
}
EOF
exit 0;
