#!/usr/bin/perl
use strict;

my $flag_lazy = 0; # disabled for now

my $fh;
my %def;
my %defun;
my %ref;
my %refun;
my %fixup;
my %fixupfun;
my %cachedsize;
my %copy;
my %lazy;
my $plt_bias;
my $plt_end;
my $data;
my $data_end;
my $pc_end;
my $entry = -1;
my @rawlibs;
my @libs;

for my $file (@ARGV) {
    open $fh, "wasm32-virtual-wasm32-objdump -T $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) [gw] D[OF]? ([a-zA-Z0-9._*]*) ([0-9a-f]*) (\.protected |\.hidden |([A-Za-z0-9_@.]*) )*([a-zA-Z0-9_\$]*)$/) {
                my ($defaddr, $sec, $version, $symbol, $size) = (hex $1, $2, $5, $6, hex $3);
                next if $sec eq "*UND*";
                my $is_function = ($sec eq ".space.function_index");

                $cachedsize{$symbol} = $size;
                if ($is_function) {
                    $defun{$symbol}{$defaddr} = 1;
                } else {
                    $def{$symbol}{$defaddr} = 1;
                }

                if ($symbol eq "_start") {
                    $entry = $defaddr;
                }
            } else {
                #warn("unhandled dynsym " . $_);
            }
    }

    open $fh, "wasm32-virtual-wasm32-objdump -R $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) R_ASMJS_ABS32(_CODE)? ([@.a-zA-Z0-9_\$]*)$/) {
                my ($refaddr, $symbol) = (hex $1,$3);
                my $version;
                $symbol =~ s/@+(.*)// and $version = $1;

                $ref{$symbol}{$refaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_(ABS|REL)32 \*ABS\*\+0x([0-9a-f]*)$/) {
                my ($refaddr, $defaddr) = (hex $1, hex $3);

                $fixup{$refaddr}{$defaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_ABS32 ([@.a-zA-Z0-9_\$]*)\+0x([0-9a-f]*)$/) {
                my ($refaddr, $defaddr) = (hex $1, hex $3);

                $fixup{$refaddr}{$defaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_ABS32_CODE ([@.a-zA-Z0-9_\$]*)\+0x([0-9a-f]*)$/) {
                my ($refaddr, $defaddr) = (hex $1, hex $3);

                $fixupfun{$refaddr}{$defaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_ABS32_CODE (\*ABS\*)\+0x([0-9a-f]*)$/) {
                my ($refaddr, $defaddr) = (hex $1, hex $3);

                $fixupfun{$refaddr}{$defaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_(LEB128_)?PLT_INDEX ([@.a-zA-Z0-9_\$]*)$/) {
                my ($refaddr, $symbol) = (hex $1,$3);
                my $version;
                $symbol =~ s/@+(.*)// and $version = $1;

                if ($symbol eq "_start") {
                    $entry = $refaddr;
                }

                $refun{$symbol}{$refaddr} = 1;
            } elsif (/^([0-9a-f]*) R_ASMJS_PLT_LAZY ([@.a-zA-Z0-9_\$]*)$/) {
                my ($refaddr, $symbol) = (hex $1, $2);
                my $version;
                $symbol =~ s/@+(.*)// and $version = $1;

                $lazy{$symbol}{$refaddr} = $version;

                if (!defined($version)) {
                    warn "undefined version for lazy symbol $symbol";
                    $flag_lazy = 0;
                }
            } elsif (/^([0-9a-f]*) R_ASMJS_COPY ([a-zA-Z0-9_\$]*)$/) {
                my ($refaddr, $symbol) = (hex $1,$2);
                $symbol =~ s/@+.*//;

                $copy{$symbol}{$refaddr} = $cachedsize{$symbol};
            } elsif (/^00000000 R_ASMJS_NONE /) {
            } else {
                #warn("unhandled dynreloc " . $_);
            }
    }

    open $fh, "wasm32-virtual-wasm32-objdump -t $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^([0-9a-f]*) [gl] ([a-zA-Z0-9._*]*) [0-9a-f]* ([a-zA-Z0-9_.\$]*)$/) {
                my ($value, $symbol) = (hex $1,$3);

                if ($symbol eq ".wasm.plt_bias") {
                    $plt_bias = $value;
                } elsif ($symbol eq ".wasm.plt_end") {
                    $plt_end = $value;
                } elsif ($symbol eq ".wasm.data") {
                    $data = $value;
                } elsif ($symbol eq ".wasm.data_end") {
                    $data_end = $value;
                } elsif ($symbol eq ".wasm.pc_end") {
                    $pc_end = $value;
                } elsif ($symbol eq "_start") {
                    $entry = $value;
                }
            }
    }

    open $fh, "wasm32-virtual-wasm32-readelf -d $file|" or die;

    while (<$fh>) {
        s/[ \t]+/ /g;
        s/[ \t]+/ /g;
        chomp;
            if (/^ ?0x([0-9a-f]*) \(NEEDED\) Shared library: \[([-a-zA-Z0-9._*]*)\]$/) {
                my ($lib) = ($2);
                push @rawlibs, $lib;
                $lib =~ s/[0-9.]*$//;
                $lib =~ s/\.so$/.wasm/;

                push @libs, $lib;
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

if ($flag_lazy) {
    print "    lazy: [\n";
    my @l;
    for my $symbol (keys %lazy) {
        for my $addr (keys %{$lazy{$symbol}}) {
            push @l, "\t[\"$symbol\", $addr, \"$lazy{$symbol}{$addr}\"]";
        }
    }
    print join(",\n", @l);
    print "    ],\n";
}

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

print "    copy: [\n";
my @l;
for my $symbol (keys %copy) {
    for my $addr (keys %{$copy{$symbol}}) {
        push @l, "\t[\"$symbol\", $addr, $copy{$symbol}{$addr}]";
    }
}
print join(",\n", @l);
print "    ],\n";

print "    libs: [\n";
print join(",\n", map { "\t\"$_\"" } (@libs));
print "    ],\n";

print "    plt_bias: $plt_bias,\n";
print "    plt_end: $plt_end,\n";
print "    data: $data,\n";
print "    data_end: $data_end,\n";
print "    pc_end: $pc_end,\n";
print "    entry: $entry\n";
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
