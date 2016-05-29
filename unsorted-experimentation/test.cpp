#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <dirent.h>
#include "zeropage.h"
#define AT_FDROOTD -101
#define offsetof(type, field) ((unsigned)&((type *)0)->field)
#include "js.h"

str zp("4096");
str tvptr("tvptr");
str statbufptr("statbufptr");
str direntp("direntp");
str fdsptr("fdsptr");
str i("i");

int main(void) {
    std::cout << to_string(fdsptr[i][&pollfd::events]) << "\\n";

    return 0;
}
