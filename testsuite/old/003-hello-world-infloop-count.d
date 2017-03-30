#source: 003-hello-world-infloop-count.c
#gcc:
#run: | head -10
hello world: %d %%f %s %c

hello world: 0 %f string x
hello world: %d %%f %s %c

hello world: 27 %f string x
hello world: %d %%f %s %c

hello world: 55 %f string x
hello world: %d %%f %s %c
#pass