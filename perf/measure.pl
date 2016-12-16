use Time::HiRes qw(time);

my @flags = ("", "--wasm-always-baseline", "--no-threads", "--wasm-always-baseline --no-threads");
my @progs = ("./build/asmjs/perl/miniperl", "./build/wasm32/perl/miniperl");

while (1)
{
    for my $i (0 .. 7) {
        my $flags = $flags[$i & 3];
        my $prog = $progs[!!($i&4)];

        my $start = time();
        `bash -c 'JSFLAGS=\"$flags\" /usr/bin/time --output="log-$i" $prog /dev/null'`;
        my $stop = time();

        my $time = $stop - $start;

        warn $time;
    }
}
