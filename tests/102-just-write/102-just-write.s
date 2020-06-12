#NO_APP
    .include "/home/pip/git/fauxsembler/gas-include.s"
    .include "/home/pip/git/fauxsembler/tests/import-macro.s"

	.import2 write,__wrap_write
	.import2 malloc,__wrap_malloc
