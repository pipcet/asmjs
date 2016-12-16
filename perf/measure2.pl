use Time::HiRes qw(time);

my @flags = ("", "--wasm-always-baseline", "--no-threads", "--wasm-always-baseline --no-threads");
my @progs = ("./build/asmjs/perl/miniperl", "./build/wasm32/perl/miniperl", "/usr/bin/perl");

my @fhs;
for my $i (0 .. 11) {
    open $fhs[$i], ">log-$i";
}
while (1)
{
    my $e = 16+rand(2)*rand(2);
    my $i = int(rand(9));
    my $flags = $flags[$i & 3];
    my $prog = $progs[int($i/4)];

    my $start = time();
    `bash -c 'JSFLAGS=\"$flags\" /usr/bin/time $prog -e "for my \\\$i (0 .. exp($e)) { }"'`;
    my $stop = time();

    my $time = $stop - $start;

    warn "$i $e $time";
    $fhs[$i]->print("$e $time\n");
    $fhs[$i]->flush;
}
