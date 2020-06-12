#  include <unistd.h>
#include <stdio.h>
#define D() do { fprintf(stderr, "%s:%d %d %d %d\n", __FILE__, __LINE__, getpid(), pid1, pid2); } while (0)
main()
{
#  define getpgID()	getpgrp()
	int pid1 = 0, pid2 = 0, fds[2];
	int status;
	char ok;

        D();
	switch (pid1 = fork()) {
	  case -1:
            D();
	    exit(1);
	  case 0:
            D();
	    setpgid(0, getpid());
	    exit(0);
	}
        D();
	setpgid(pid1, pid1);

        D();
	sleep(2);	/* let first child die */

        D();
	if (pipe(fds) < 0)
	  exit(2);

        D();
	switch (pid2 = fork()) {
	  case -1:
            D();
	    exit(3);
	  case 0:
            D();
	    setpgid(0, pid1);
            D();
	    ok = getpgID() == pid1;
            D();
	    write(fds[1], &ok, 1);
            D();
	    exit(0);
	}
        D();
	setpgid(pid2, pid1);

        D();
	close(fds[1]);
        D();
	if (read(fds[0], &ok, 1) != 1)
	  exit(4);
        D();
	wait(&status);
        D();
	wait(&status);
        D();
        exit(ok ? 0 : 5);
}

