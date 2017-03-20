#!/usr/bin/perl
my $col = 0;
sub myprint {
    my $nl = 0;
    my $str = $_[0];
    if ($str =~ s/\n$//) {
        $nl = 1;
    }

    $col += length($str);
    print $str;

    if ($nl) {
        print " " x (76 - $col);
        print "\\\n";
        $col = 0;
    }
}

while (<>) {
    chomp;
    my $signature = $_;
    die unless /^F(.*)E$/;

    my $demangled = `wasm32-virtual-wasm32-c++filt -t $signature`;
    chomp $demangled;

    my $withvars = $demangled;
    my $i = 0;
    $withvars =~ s/([(])/f$1/msg;
    $withvars =~ s/([,)])/" var" . $i++ . $1/mesg;

    my $rettype = $withvars;
    $rettype =~ s/ f.*//;


    myprint "#define IMPORT_NATIVE_$signature(f)\n";
    myprint "extern inline " . $withvars . "\n";
    myprint "{\n";
    myprint "  $rettype ret;\n";
    myprint "  __asm__(";
    unless ($rettype eq "void") {
        myprint "\"\%S0\"\\n\\t\"\n";
        myprint "          ";
    }
    for (my $ii = 0; $ii < $i; $ii++) {
        my $o = $ii+1;
        myprint "\"\%$o\\n\\t\"\n";
        myprint "          ";
    }
    myprint "\"call \" ##f \"\@plt{__sigchar_$signature}\\n\\t\"\n";
    myprint "          ";
    unless ($rettype eq "void") {
        myprint "\"\%R0\"\n";
    }
    myprint "          : \"=r\" (ret)\n";
    myprint "          : ";
    for (my $ii = 0; $ii < $i; $ii++) {
        myprint "\"r\" (var$ii)";
        myprint ", " unless $ii == $i - 1;
    }
    myprint ");\n";
    myprint "  return ret;\n";
    myprint "}";

    print "\n";
}
