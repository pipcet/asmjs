# 1 "../sysdeps/posix/readv.c"
# 1 "/home/pip/git/glibc/misc//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "../include/stdc-predef.h" 1
# 1 "<command-line>" 2
# 1 "/home/pip/build/glibc/asmjs-20160214/libc-modules.h" 1
# 1 "<command-line>" 2
# 1 "./../include/libc-symbols.h" 1
# 58 "./../include/libc-symbols.h"
# 1 "/home/pip/build/glibc/asmjs-20160214/config.h" 1
# 59 "./../include/libc-symbols.h" 2
# 702 "./../include/libc-symbols.h"
# 1 "../sysdeps/asmjs/symbol-hacks.h" 1
# 703 "./../include/libc-symbols.h" 2
# 1 "<command-line>" 2
# 1 "../sysdeps/posix/readv.c"
# 18 "../sysdeps/posix/readv.c"
# 1 "../include/stdlib.h" 1







# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 149 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 3 4

# 149 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 216 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 328 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 3 4
typedef int wchar_t;
# 426 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
# 9 "../include/stdlib.h" 2

# 1 "../stdlib/stdlib.h" 1
# 24 "../stdlib/stdlib.h"
# 1 "../include/features.h" 1
# 368 "../include/features.h"
# 1 "../include/sys/cdefs.h" 1


# 1 "../misc/sys/cdefs.h" 1
# 410 "../misc/sys/cdefs.h"
# 1 "../sysdeps/wordsize-32/bits/wordsize.h" 1
# 411 "../misc/sys/cdefs.h" 2
# 4 "../include/sys/cdefs.h" 2
# 12 "../include/sys/cdefs.h"

# 12 "../include/sys/cdefs.h"
extern void __chk_fail (void) __attribute__ ((__noreturn__));


# 369 "../include/features.h" 2
# 392 "../include/features.h"
# 1 "../include/gnu/stubs.h" 1
# 393 "../include/features.h" 2
# 25 "../stdlib/stdlib.h" 2







# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 33 "../stdlib/stdlib.h" 2








# 1 "../bits/waitflags.h" 1
# 42 "../stdlib/stdlib.h" 2
# 1 "../bits/waitstatus.h" 1
# 64 "../bits/waitstatus.h"
# 1 "../include/endian.h" 1
# 1 "../string/endian.h" 1
# 36 "../string/endian.h"
# 1 "../sysdeps/asmjs/bits/endian.h" 1
# 37 "../string/endian.h" 2
# 60 "../string/endian.h"
# 1 "../bits/byteswap.h" 1
# 27 "../bits/byteswap.h"
# 1 "../bits/types.h" 1
# 27 "../bits/types.h"
# 1 "../sysdeps/wordsize-32/bits/wordsize.h" 1
# 28 "../bits/types.h" 2


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 121 "../bits/types.h"
# 1 "../bits/typesizes.h" 1
# 122 "../bits/types.h" 2


__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef void * __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;


__extension__ typedef int __fsword_t;

__extension__ typedef int __ssize_t;


__extension__ typedef long int __syscall_slong_t;

__extension__ typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
# 28 "../bits/byteswap.h" 2






# 1 "../bits/byteswap-16.h" 1
# 35 "../bits/byteswap.h" 2
# 43 "../bits/byteswap.h"
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
# 74 "../bits/byteswap.h"
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
# 61 "../string/endian.h" 2
# 2 "../include/endian.h" 2
# 65 "../bits/waitstatus.h" 2

union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 43 "../stdlib/stdlib.h" 2
# 67 "../stdlib/stdlib.h"
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 95 "../stdlib/stdlib.h"


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 139 "../stdlib/stdlib.h"
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ )) ;




extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;





__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;





extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ )) ;





extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ )) ;

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ )) ;





extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) ;

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) ;




__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) ;

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) ;





__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) ;

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) ;

# 235 "../stdlib/stdlib.h"
# 1 "../include/xlocale.h" 1
# 1 "../locale/xlocale.h" 1
# 27 "../locale/xlocale.h"
typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 1 "../include/xlocale.h" 2
# 236 "../stdlib/stdlib.h" 2



extern long int strtol_l (const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     __locale_t __loc) __attribute__ ((__nothrow__ )) ;

extern unsigned long int strtoul_l (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, __locale_t __loc)
     __attribute__ ((__nothrow__ )) ;

__extension__
extern long long int strtoll_l (const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    __locale_t __loc)
     __attribute__ ((__nothrow__ )) ;

__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, __locale_t __loc)
     __attribute__ ((__nothrow__ )) ;

extern double strtod_l (const char *__restrict __nptr,
   char **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__ )) ;

extern float strtof_l (const char *__restrict __nptr,
         char **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__ )) ;

extern long double strtold_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         __locale_t __loc)
     __attribute__ ((__nothrow__ )) ;





extern __inline int
__attribute__ ((__nothrow__ )) atoi (const char *__nptr)
{
  return (int) strtol (__nptr, (char **) 
# 280 "../stdlib/stdlib.h" 3 4
                                        ((void *)0)
# 280 "../stdlib/stdlib.h"
                                            , 10);
}
extern __inline long int
__attribute__ ((__nothrow__ )) atol (const char *__nptr)
{
  return strtol (__nptr, (char **) 
# 285 "../stdlib/stdlib.h" 3 4
                                  ((void *)0)
# 285 "../stdlib/stdlib.h"
                                      , 10);
}




__extension__ extern __inline long long int
__attribute__ ((__nothrow__ )) atoll (const char *__nptr)
{
  return strtoll (__nptr, (char **) 
# 294 "../stdlib/stdlib.h" 3 4
                                   ((void *)0)
# 294 "../stdlib/stdlib.h"
                                       , 10);
}

# 305 "../stdlib/stdlib.h"
extern char *l64a (long int __n) __attribute__ ((__nothrow__ )) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;




# 1 "../include/sys/types.h" 1
# 1 "../posix/sys/types.h" 1
# 27 "../posix/sys/types.h"






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;




typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 132 "../posix/sys/types.h"
# 1 "../include/time.h" 1


# 1 "../time/time.h" 1
# 57 "../time/time.h"


typedef __clock_t clock_t;



# 73 "../time/time.h"


typedef __time_t time_t;



# 91 "../time/time.h"
typedef __clockid_t clockid_t;
# 103 "../time/time.h"
typedef __timer_t timer_t;
# 4 "../include/time.h" 2
# 133 "../posix/sys/types.h" 2



typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 147 "../posix/sys/types.h" 2



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 194 "../posix/sys/types.h"
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 216 "../posix/sys/types.h"
# 1 "../include/endian.h" 1
# 217 "../posix/sys/types.h" 2


# 1 "../include/sys/select.h" 1

# 1 "../misc/sys/select.h" 1
# 30 "../misc/sys/select.h"
# 1 "../bits/select.h" 1
# 31 "../misc/sys/select.h" 2


# 1 "../bits/sigset.h" 1
# 22 "../bits/sigset.h"
typedef int __sig_atomic_t;


typedef unsigned long int __sigset_t;
# 34 "../misc/sys/select.h" 2



typedef __sigset_t sigset_t;





# 1 "../include/time.h" 1


# 1 "../time/time.h" 1
# 120 "../time/time.h"
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };
# 4 "../include/time.h" 2
# 44 "../misc/sys/select.h" 2

# 1 "../bits/time.h" 1
# 74 "../bits/time.h"
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 46 "../misc/sys/select.h" 2
# 54 "../misc/sys/select.h"
typedef long int __fd_mask;
# 64 "../misc/sys/select.h"
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 96 "../misc/sys/select.h"

# 106 "../misc/sys/select.h"
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 118 "../misc/sys/select.h"
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 131 "../misc/sys/select.h"

# 3 "../include/sys/select.h" 2



extern int __pselect (int __nfds, fd_set *__readfds,
        fd_set *__writefds, fd_set *__exceptfds,
        const struct timespec *__timeout,
        const __sigset_t *__sigmask);

extern int __select (int __nfds, fd_set *__restrict __readfds,
       fd_set *__restrict __writefds,
       fd_set *__restrict __exceptfds,
       struct timeval *__restrict __timeout);

# 220 "../posix/sys/types.h" 2


# 1 "../sysdeps/asmjs/sys/sysmacros.h" 1
# 223 "../posix/sys/types.h" 2





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 262 "../posix/sys/types.h"
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;





# 1 "../bits/pthreadtypes.h" 1
# 271 "../posix/sys/types.h" 2



# 1 "../include/sys/types.h" 2
# 315 "../stdlib/stdlib.h" 2






extern long int random (void) __attribute__ ((__nothrow__ ));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ ));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ )) ;



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ )) ;







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ )) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ )) ;

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ )) ;

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ )) ;






extern int rand (void) __attribute__ ((__nothrow__ ));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ ));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ ));







extern double drand48 (void) __attribute__ ((__nothrow__ ));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ )) ;


extern long int lrand48 (void) __attribute__ ((__nothrow__ ));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ )) ;


extern long int mrand48 (void) __attribute__ ((__nothrow__ ));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ )) ;


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ ));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ )) ;
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ )) ;





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ )) ;
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ )) ;


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) ;
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) ;


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) ;
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ )) ;

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ )) ;

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ )) ;









extern void *malloc (size_t __size) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__ ));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__ ));



# 1 "../include/alloca.h" 1


# 1 "../stdlib/alloca.h" 1
# 24 "../stdlib/alloca.h"
# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 25 "../stdlib/alloca.h" 2







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ ));






# 4 "../include/alloca.h" 2
# 1 "../include/stackinfo.h" 1
# 24 "../include/stackinfo.h"
# 1 "../sysdeps/asmjs/stackinfo.h" 1
# 25 "../include/stackinfo.h" 2
# 5 "../include/alloca.h" 2




extern void *__alloca (size_t __size);





extern int __libc_use_alloca (size_t size) __attribute__ ((const));
extern int __libc_alloca_cutoff (size_t size) __attribute__ ((const));




# 1 "../sysdeps/asmjs/allocalim.h" 1
extern inline int __libc_use_alloca (size_t size)
{
  return size <= 65536;
}
# 22 "../include/alloca.h" 2
# 493 "../stdlib/stdlib.h" 2





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ )) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;




extern void abort (void) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ )) ;







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ )) ;







extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ )) ;






extern void exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));







extern void _Exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));






extern char *getenv (const char *__name) __attribute__ ((__nothrow__ )) ;





extern char *secure_getenv (const char *__name)
     __attribute__ ((__nothrow__ )) ;






extern int putenv (char *__string) __attribute__ ((__nothrow__ )) ;





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ )) ;


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ )) ;






extern int clearenv (void) __attribute__ ((__nothrow__ ));
# 606 "../stdlib/stdlib.h"
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ )) ;
# 619 "../stdlib/stdlib.h"
extern int mkstemp (char *__template) ;
# 629 "../stdlib/stdlib.h"
extern int mkstemp64 (char *__template) ;
# 641 "../stdlib/stdlib.h"
extern int mkstemps (char *__template, int __suffixlen) ;
# 651 "../stdlib/stdlib.h"
extern int mkstemps64 (char *__template, int __suffixlen)
     ;
# 662 "../stdlib/stdlib.h"
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ )) ;
# 673 "../stdlib/stdlib.h"
extern int mkostemp (char *__template, int __flags) ;
# 683 "../stdlib/stdlib.h"
extern int mkostemp64 (char *__template, int __flags) ;
# 693 "../stdlib/stdlib.h"
extern int mkostemps (char *__template, int __suffixlen, int __flags)
     ;
# 705 "../stdlib/stdlib.h"
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     ;









extern int system (const char *__command) ;






extern char *canonicalize_file_name (const char *__name)
     __attribute__ ((__nothrow__ )) ;
# 733 "../stdlib/stdlib.h"
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ )) ;






typedef int (*__compar_fn_t) (const void *, const void *);


typedef __compar_fn_t comparison_fn_t;



typedef int (*__compar_d_fn_t) (const void *, const void *, void *);





extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     ;


# 1 "../bits/stdlib-bsearch.h" 1
# 19 "../bits/stdlib-bsearch.h"
extern __inline void *
bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size,
  __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;

  __l = 0;
  __u = __nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;
      __p = (void *) (((const char *) __base) + (__idx * __size));
      __comparison = (*__compar) (__key, __p);
      if (__comparison < 0)
 __u = __idx;
      else if (__comparison > 0)
 __l = __idx + 1;
      else
 return (void *) __p;
    }

  return 
# 42 "../bits/stdlib-bsearch.h" 3 4
        ((void *)0)
# 42 "../bits/stdlib-bsearch.h"
            ;
}
# 760 "../stdlib/stdlib.h" 2




extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) ;

extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  ;




extern int abs (int __x) __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;

# 811 "../stdlib/stdlib.h"
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ )) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ )) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ )) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ )) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ )) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ )) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ )) ;
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ )) ;

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) ;
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) ;






extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ ));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ ));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ ));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ ));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ ));








extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ )) ;
# 898 "../stdlib/stdlib.h"
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ )) ;





extern void setkey (const char *__key) __attribute__ ((__nothrow__ )) ;







extern int posix_openpt (int __oflag) ;







extern int grantpt (int __fd) __attribute__ ((__nothrow__ ));



extern int unlockpt (int __fd) __attribute__ ((__nothrow__ ));




extern char *ptsname (int __fd) __attribute__ ((__nothrow__ )) ;






extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ )) ;


extern int getpt (void);






extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ )) ;


# 1 "../include/bits/stdlib-float.h" 1





# 1 "../stdlib/bits/stdlib-float.h" 1
# 24 "../stdlib/bits/stdlib-float.h"

extern __inline double
__attribute__ ((__nothrow__ )) atof (const char *__nptr)
{
  return strtod (__nptr, (char **) 
# 28 "../stdlib/bits/stdlib-float.h" 3 4
                                  ((void *)0)
# 28 "../stdlib/bits/stdlib-float.h"
                                      );
}

# 7 "../include/bits/stdlib-float.h" 2
# 955 "../stdlib/stdlib.h" 2
# 967 "../stdlib/stdlib.h"

# 11 "../include/stdlib.h" 2



# 1 "../include/sys/stat.h" 1

# 1 "../io/sys/stat.h" 1
# 36 "../io/sys/stat.h"
# 1 "../include/time.h" 1


# 1 "../time/time.h" 1
# 4 "../include/time.h" 2
# 37 "../io/sys/stat.h" 2
# 102 "../io/sys/stat.h"


# 1 "../sysdeps/asmjs/bits/stat.h" 1
# 26 "../sysdeps/asmjs/bits/stat.h"
# 1 "../include/endian.h" 1
# 27 "../sysdeps/asmjs/bits/stat.h" 2
# 1 "../sysdeps/wordsize-32/bits/wordsize.h" 1
# 28 "../sysdeps/asmjs/bits/stat.h" 2
# 55 "../sysdeps/asmjs/bits/stat.h"
struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino __attribute__((__aligned__ (__alignof__ (__ino64_t)))); int __st_ino_pad;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    __dev_t __pad1;
    __off_t st_size __attribute__((__aligned__ (__alignof__ (__off64_t)))); int __st_size_pad;
    __blksize_t st_blksize;
    int __pad2;
    __blkcnt_t st_blocks __attribute__((__aligned__ (__alignof__ (__blkcnt64_t)))); int __st_blocks_pad;







    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 90 "../sysdeps/asmjs/bits/stat.h"
    int __glibc_reserved[2];
  };




struct stat64
  {
    __dev_t st_dev;
    __ino64_t st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    __dev_t __pad1;
    __off64_t st_size;
    __blksize_t st_blksize;
    int __pad2;
    __blkcnt64_t st_blocks;







    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 128 "../sysdeps/asmjs/bits/stat.h"
    int __glibc_reserved[2];
  };
# 105 "../io/sys/stat.h" 2
# 208 "../io/sys/stat.h"
extern int stat (const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__ )) ;



extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ )) ;
# 227 "../io/sys/stat.h"
extern int stat64 (const char *__restrict __file,
     struct stat64 *__restrict __buf) __attribute__ ((__nothrow__ )) ;
extern int fstat64 (int __fd, struct stat64 *__buf) __attribute__ ((__nothrow__ )) ;







extern int fstatat (int __fd, const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ )) ;
# 252 "../io/sys/stat.h"
extern int fstatat64 (int __fd, const char *__restrict __file,
        struct stat64 *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ )) ;







extern int lstat (const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__ )) ;
# 275 "../io/sys/stat.h"
extern int lstat64 (const char *__restrict __file,
      struct stat64 *__restrict __buf)
     __attribute__ ((__nothrow__ )) ;





extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ )) ;





extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ )) ;




extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ ));





extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ )) ;






extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ ));




extern __mode_t getumask (void) __attribute__ ((__nothrow__ ));



extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ )) ;





extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ )) ;






extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ )) ;





extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ )) ;





extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ )) ;





extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ )) ;





extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ )) ;




extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ ));
# 398 "../io/sys/stat.h"
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf)
     __attribute__ ((__nothrow__ )) ;
extern int __xstat (int __ver, const char *__filename,
      struct stat *__stat_buf) __attribute__ ((__nothrow__ )) ;
extern int __lxstat (int __ver, const char *__filename,
       struct stat *__stat_buf) __attribute__ ((__nothrow__ )) ;
extern int __fxstatat (int __ver, int __fildes, const char *__filename,
         struct stat *__stat_buf, int __flag)
     __attribute__ ((__nothrow__ )) ;
# 431 "../io/sys/stat.h"
extern int __fxstat64 (int __ver, int __fildes, struct stat64 *__stat_buf)
     __attribute__ ((__nothrow__ )) ;
extern int __xstat64 (int __ver, const char *__filename,
        struct stat64 *__stat_buf) __attribute__ ((__nothrow__ )) ;
extern int __lxstat64 (int __ver, const char *__filename,
         struct stat64 *__stat_buf) __attribute__ ((__nothrow__ )) ;
extern int __fxstatat64 (int __ver, int __fildes, const char *__filename,
    struct stat64 *__stat_buf, int __flag)
     __attribute__ ((__nothrow__ )) ;

extern int __xmknod (int __ver, const char *__path, __mode_t __mode,
       __dev_t *__dev) __attribute__ ((__nothrow__ )) ;

extern int __xmknodat (int __ver, int __fd, const char *__path,
         __mode_t __mode, __dev_t *__dev)
     __attribute__ ((__nothrow__ )) ;




extern __inline int
__attribute__ ((__nothrow__ )) stat (const char *__path, struct stat *__statbuf)
{
  return __xstat (0, __path, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__ )) lstat (const char *__path, struct stat *__statbuf)
{
  return __lxstat (0, __path, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__ )) fstat (int __fd, struct stat *__statbuf)
{
  return __fxstat (0, __fd, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__ )) fstatat (int __fd, const char *__filename, struct stat *__statbuf, int __flag)

{
  return __fxstatat (0, __fd, __filename, __statbuf, __flag);
}



extern __inline int
__attribute__ ((__nothrow__ )) mknod (const char *__path, __mode_t __mode, __dev_t __dev)
{
  return __xmknod (0, __path, __mode, &__dev);
}



extern __inline int
__attribute__ ((__nothrow__ )) mknodat (int __fd, const char *__path, __mode_t __mode, __dev_t __dev)

{
  return __xmknodat (0, __fd, __path, __mode, &__dev);
}





extern __inline int
__attribute__ ((__nothrow__ )) stat64 (const char *__path, struct stat64 *__statbuf)
{
  return __xstat64 (0, __path, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__ )) lstat64 (const char *__path, struct stat64 *__statbuf)
{
  return __lxstat64 (0, __path, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__ )) fstat64 (int __fd, struct stat64 *__statbuf)
{
  return __fxstat64 (0, __fd, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__ )) fstatat64 (int __fd, const char *__filename, struct stat64 *__statbuf, int __flag)

{
  return __fxstatat64 (0, __fd, __filename, __statbuf, __flag);
}







# 3 "../include/sys/stat.h" 2



extern int __stat (const char *__file, struct stat *__buf);
extern int __fstat (int __fd, struct stat *__buf);
extern int __lstat (const char *__file, struct stat *__buf);
extern int __chmod (const char *__file, __mode_t __mode);
extern int __fchmod (int __fd, __mode_t __mode);
extern __mode_t __umask (__mode_t __mask);
extern int __mkdir (const char *__path, __mode_t __mode);
extern int __mknod (const char *__path,
      __mode_t __mode, __dev_t __dev);








extern __inline__ int __stat (const char *__path, struct stat *__statbuf)
{
  return __xstat (0, __path, __statbuf);
}

extern __inline__ int __mknod (const char *__path, __mode_t __mode,
          __dev_t __dev)
{
  return __xmknod (0, __path, __mode, &__dev);
}




# 15 "../include/stdlib.h" 2



extern __typeof (strtol_l) __strtol_l;
extern __typeof (strtoul_l) __strtoul_l;
extern __typeof (strtoll_l) __strtoll_l;
extern __typeof (strtoull_l) __strtoull_l;
extern __typeof (strtod_l) __strtod_l;
extern __typeof (strtof_l) __strtof_l;
extern __typeof (strtold_l) __strtold_l;











extern __typeof (secure_getenv) __libc_secure_getenv;



extern __typeof (qsort_r) __qsort_r;




extern long int __random (void);
extern void __srandom (unsigned int __seed);
extern char *__initstate (unsigned int __seed, char *__statebuf,
     size_t __statelen);
extern char *__setstate (char *__statebuf);
extern int __random_r (struct random_data *__buf, int32_t *__result);
extern int __srandom_r (unsigned int __seed, struct random_data *__buf);
extern int __initstate_r (unsigned int __seed, char *__statebuf,
     size_t __statelen, struct random_data *__buf);
extern int __setstate_r (char *__statebuf, struct random_data *__buf);
extern int __rand_r (unsigned int *__seed);
extern int __erand48_r (unsigned short int __xsubi[3],
   struct drand48_data *__buffer, double *__result);
extern int __nrand48_r (unsigned short int __xsubi[3],
   struct drand48_data *__buffer,
   long int *__result);
extern int __jrand48_r (unsigned short int __xsubi[3],
   struct drand48_data *__buffer,
   long int *__result);
extern int __srand48_r (long int __seedval,
   struct drand48_data *__buffer);
extern int __seed48_r (unsigned short int __seed16v[3],
         struct drand48_data *__buffer);
extern int __lcong48_r (unsigned short int __param[7],
   struct drand48_data *__buffer);


extern int __drand48_iterate (unsigned short int __xsubi[3],
         struct drand48_data *__buffer);


extern struct drand48_data __libc_drand48_data ;

extern int __setenv (const char *__name, const char *__value, int __replace);
extern int __unsetenv (const char *__name);
extern int __clearenv (void);
extern char *__mktemp (char *__template) __attribute__ ((__nothrow__ )) ;
extern char *__canonicalize_file_name (const char *__name);
extern char *__realpath (const char *__name, char *__resolved);
extern int __ptsname_r (int __fd, char *__buf, size_t __buflen);

extern int __ptsname_internal (int fd, char *buf, size_t buflen,
          struct stat64 *stp);

extern int __getpt (void);
extern int __posix_openpt (int __oflag);

extern int __add_to_environ (const char *name, const char *value,
        const char *combines, int replace);

extern void _quicksort (void *const pbase, size_t total_elems,
   size_t size, __compar_d_fn_t cmp, void *arg);

extern int __on_exit (void (*__func) (int __status, void *__arg), void *__arg);

extern int __cxa_atexit (void (*func) (void *), void *arg, void *d);
;

extern int __cxa_thread_atexit_impl (void (*func) (void *), void *arg,
         void *d);
extern void __call_tls_dtors (void)

  __attribute__ ((weak))

  ;


extern void __cxa_finalize (void *d);

extern int __posix_memalign (void **memptr, size_t alignment, size_t size);

extern void *__libc_memalign (size_t alignment, size_t size)
     __attribute__ ((__malloc__));

extern int __libc_system (const char *line);


extern double __strtod_internal (const char *__restrict __nptr,
     char **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__ )) ;
extern float __strtof_internal (const char *__restrict __nptr,
    char **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__ )) ;
extern long double __strtold_internal (const char *__restrict __nptr,
           char **__restrict __endptr,
           int __group)
     __attribute__ ((__nothrow__ )) ;
extern long int __strtol_internal (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group)
     __attribute__ ((__nothrow__ )) ;
extern unsigned long int __strtoul_internal (const char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group)
     __attribute__ ((__nothrow__ )) ;
__extension__
extern long long int __strtoll_internal (const char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group)
     __attribute__ ((__nothrow__ )) ;
__extension__
extern unsigned long long int __strtoull_internal (const char *
         __restrict __nptr,
         char **__restrict __endptr,
         int __base, int __group)
     __attribute__ ((__nothrow__ )) ;








extern double ____strtod_l_internal (const char *__restrict __nptr,
         char **__restrict __endptr, int __group,
         __locale_t __loc);
extern float ____strtof_l_internal (const char *__restrict __nptr,
        char **__restrict __endptr, int __group,
        __locale_t __loc);
extern long double ____strtold_l_internal (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __group, __locale_t __loc);
extern long int ____strtol_l_internal (const char *__restrict __nptr,
           char **__restrict __endptr,
           int __base, int __group,
           __locale_t __loc);
extern unsigned long int ____strtoul_l_internal (const char *
       __restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group,
       __locale_t __loc);
__extension__
extern long long int ____strtoll_l_internal (const char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group,
          __locale_t __loc);
__extension__
extern unsigned long long int ____strtoull_l_internal (const char *
             __restrict __nptr,
             char **
             __restrict __endptr,
             int __base, int __group,
             __locale_t __loc);

















extern float __strtof_nan (const char *, char **, char) ;
extern double __strtod_nan (const char *, char **, char) ;
extern long double __strtold_nan (const char *, char **, char)
     ;
extern float __wcstof_nan (const wchar_t *, wchar_t **, wchar_t)
     ;
extern double __wcstod_nan (const wchar_t *, wchar_t **, wchar_t)
     ;
extern long double __wcstold_nan (const wchar_t *, wchar_t **, wchar_t)
     ;








extern char *__ecvt (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign);
extern char *__fcvt (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign);
extern char *__gcvt (double __value, int __ndigit, char *__buf);
extern int __ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign, char *__restrict __buf,
       size_t __len);
extern int __fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign, char *__restrict __buf,
       size_t __len);
extern char *__qecvt (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign);
extern char *__qfcvt (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign);
extern char *__qgcvt (long double __value, int __ndigit, char *__buf);
extern int __qecvt_r (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign,
        char *__restrict __buf, size_t __len);
extern int __qfcvt_r (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign,
        char *__restrict __buf, size_t __len);






extern void *__default_morecore (ptrdiff_t) __attribute__ ((__nothrow__ ));


struct abort_msg_s
{
  unsigned int size;
  char msg[0];
};
extern struct abort_msg_s *__abort_msg;








# 19 "../sysdeps/posix/readv.c" 2
# 1 "../include/unistd.h" 1

# 1 "../posix/unistd.h" 1
# 27 "../posix/unistd.h"

# 205 "../posix/unistd.h"
# 1 "../bits/posix_opt.h" 1
# 206 "../posix/unistd.h" 2



# 1 "../bits/environments.h" 1
# 22 "../bits/environments.h"
# 1 "../sysdeps/wordsize-32/bits/wordsize.h" 1
# 23 "../bits/environments.h" 2
# 210 "../posix/unistd.h" 2
# 229 "../posix/unistd.h"
# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 230 "../posix/unistd.h" 2
# 270 "../posix/unistd.h"
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 290 "../posix/unistd.h"
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ )) ;




extern int euidaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ )) ;


extern int eaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ )) ;






extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ )) ;
# 337 "../posix/unistd.h"
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ ));
# 348 "../posix/unistd.h"
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     __attribute__ ((__nothrow__ ));






extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;





extern ssize_t write (int __fd, const void *__buf, size_t __n) ;
# 379 "../posix/unistd.h"
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) ;






extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) ;
# 407 "../posix/unistd.h"
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
   __off64_t __offset) ;


extern ssize_t pwrite64 (int __fd, const void *__buf, size_t __n,
    __off64_t __offset) ;







extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ )) ;




extern int pipe2 (int __pipedes[2], int __flags) __attribute__ ((__nothrow__ )) ;
# 435 "../posix/unistd.h"
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ ));
# 447 "../posix/unistd.h"
extern unsigned int sleep (unsigned int __seconds);







extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ ));






extern int usleep (__useconds_t __useconds);
# 472 "../posix/unistd.h"
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ )) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ )) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ )) ;






extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ )) ;



extern int chdir (const char *__path) __attribute__ ((__nothrow__ )) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__ )) ;
# 514 "../posix/unistd.h"
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ )) ;





extern char *get_current_dir_name (void) __attribute__ ((__nothrow__ ));







extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__deprecated__)) ;




extern int dup (int __fd) __attribute__ ((__nothrow__ )) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ ));




extern int dup3 (int __fd, int __fd2, int __flags) __attribute__ ((__nothrow__ ));



extern char **__environ;

extern char **environ;





extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ )) ;




extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ )) ;




extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ )) ;



extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ )) ;



extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ )) ;



extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ )) ;




extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ )) ;




extern int execvpe (const char *__file, char *const __argv[],
      char *const __envp[])
     __attribute__ ((__nothrow__ )) ;





extern int nice (int __inc) __attribute__ ((__nothrow__ )) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "../bits/confname.h" 1
# 24 "../bits/confname.h"
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,


    _CS_V6_ENV,

    _CS_V7_ENV

  };
# 613 "../posix/unistd.h" 2


extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ )) ;


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ ));


extern long int sysconf (int __name) __attribute__ ((__nothrow__ ));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ ));




extern __pid_t getpid (void) __attribute__ ((__nothrow__ ));


extern __pid_t getppid (void) __attribute__ ((__nothrow__ ));


extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ ));


extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ ));

extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ ));






extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ ));
# 663 "../posix/unistd.h"
extern int setpgrp (void) __attribute__ ((__nothrow__ ));






extern __pid_t setsid (void) __attribute__ ((__nothrow__ ));



extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ ));



extern __uid_t getuid (void) __attribute__ ((__nothrow__ ));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__ ));


extern __gid_t getgid (void) __attribute__ ((__nothrow__ ));


extern __gid_t getegid (void) __attribute__ ((__nothrow__ ));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ )) ;



extern int group_member (__gid_t __gid) __attribute__ ((__nothrow__ ));






extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ )) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ )) ;




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ )) ;






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ )) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ )) ;




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ )) ;





extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     __attribute__ ((__nothrow__ ));



extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     __attribute__ ((__nothrow__ ));



extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     __attribute__ ((__nothrow__ )) ;



extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     __attribute__ ((__nothrow__ )) ;






extern __pid_t fork (void) __attribute__ ((__nothrow__));







extern __pid_t vfork (void) __attribute__ ((__nothrow__ ));





extern char *ttyname (int __fd) __attribute__ ((__nothrow__ ));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ )) ;



extern int isatty (int __fd) __attribute__ ((__nothrow__ ));





extern int ttyslot (void) __attribute__ ((__nothrow__ ));




extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ )) ;




extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ )) ;




extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ )) ;




extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) ;




extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ )) ;


extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) ;



extern int unlink (const char *__name) __attribute__ ((__nothrow__ )) ;



extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ )) ;



extern int rmdir (const char *__path) __attribute__ ((__nothrow__ )) ;



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ ));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ ));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) ;




extern int setlogin (const char *__name) __attribute__ ((__nothrow__ )) ;
# 874 "../posix/unistd.h"
# 1 "../include/getopt.h" 1



# 1 "../posix/getopt.h" 1
# 57 "../posix/getopt.h"
extern char *optarg;
# 71 "../posix/getopt.h"
extern int optind;




extern int opterr;



extern int optopt;
# 150 "../posix/getopt.h"
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ ));
# 5 "../include/getopt.h" 2
# 875 "../posix/unistd.h" 2







extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ )) ;






extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ )) ;



extern int sethostid (long int __id) __attribute__ ((__nothrow__ )) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ )) ;
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ )) ;





extern int vhangup (void) __attribute__ ((__nothrow__ ));


extern int revoke (const char *__file) __attribute__ ((__nothrow__ )) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ )) ;





extern int acct (const char *__name) __attribute__ ((__nothrow__ ));



extern char *getusershell (void) __attribute__ ((__nothrow__ ));
extern void endusershell (void) __attribute__ ((__nothrow__ ));
extern void setusershell (void) __attribute__ ((__nothrow__ ));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ )) ;






extern int chroot (const char *__path) __attribute__ ((__nothrow__ )) ;



extern char *getpass (const char *__prompt) ;







extern int fsync (int __fd);





extern int syncfs (int __fd) __attribute__ ((__nothrow__ ));






extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__ ));





extern int getpagesize (void) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__ ));
# 996 "../posix/unistd.h"
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ )) ;
# 1008 "../posix/unistd.h"
extern int truncate64 (const char *__file, __off64_t __length)
     __attribute__ ((__nothrow__ )) ;
# 1019 "../posix/unistd.h"
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ )) ;
# 1029 "../posix/unistd.h"
extern int ftruncate64 (int __fd, __off64_t __length) __attribute__ ((__nothrow__ )) ;
# 1040 "../posix/unistd.h"
extern int brk (void *__addr) __attribute__ ((__nothrow__ )) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ ));
# 1061 "../posix/unistd.h"
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ ));
# 1084 "../posix/unistd.h"
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1094 "../posix/unistd.h"
extern int lockf64 (int __fd, int __cmd, __off64_t __len) ;
# 1115 "../posix/unistd.h"
extern int fdatasync (int __fildes);







extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ )) ;



extern void encrypt (char *__glibc_block, int __edflag)
     __attribute__ ((__nothrow__ )) ;






extern void swab (const void *__restrict __from, void *__restrict __to,
    ssize_t __n) __attribute__ ((__nothrow__ )) ;
# 1154 "../posix/unistd.h"

# 3 "../include/unistd.h" 2















extern __typeof (getlogin_r) __getlogin_r ;








extern int __access (const char *__name, int __type);
extern int __euidaccess (const char *__name, int __type);
extern __off64_t __lseek64 (int __fd, __off64_t __offset, int __whence);
extern __off_t __lseek (int __fd, __off_t __offset, int __whence);

extern __off_t __libc_lseek (int __fd, __off_t __offset, int __whence);
extern __off64_t __libc_lseek64 (int __fd, __off64_t __offset, int __whence);
extern ssize_t __pread (int __fd, void *__buf, size_t __nbytes,
   __off_t __offset);
extern ssize_t __libc_pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset);
extern ssize_t __pread64 (int __fd, void *__buf, size_t __nbytes,
     __off64_t __offset);
extern ssize_t __libc_pread64 (int __fd, void *__buf, size_t __nbytes,
          __off64_t __offset);
extern ssize_t __pwrite (int __fd, const void *__buf, size_t __n,
    __off_t __offset);
extern ssize_t __libc_pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset);
extern ssize_t __pwrite64 (int __fd, const void *__buf, size_t __n,
      __off64_t __offset);

extern ssize_t __libc_pwrite64 (int __fd, const void *__buf, size_t __n,
    __off64_t __offset) ;
extern ssize_t __libc_read (int __fd, void *__buf, size_t __n);

extern ssize_t __libc_write (int __fd, const void *__buf, size_t __n);

extern int __pipe (int __pipedes[2]);

extern int __pipe2 (int __pipedes[2], int __flags);
extern unsigned int __sleep (unsigned int __seconds);
extern int __chown (const char *__file,
      __uid_t __owner, __gid_t __group);

extern int __fchown (int __fd,
       __uid_t __owner, __gid_t __group);
extern int __lchown (const char *__file, __uid_t __owner,
       __gid_t __group);
extern int __chdir (const char *__path);
extern int __fchdir (int __fd);
extern char *__getcwd (char *__buf, size_t __size);
extern int __rmdir (const char *__path);
extern int __execvpe (const char *file, char *const argv[],
        char *const envp[]);







char *__canonicalize_directory_name_internal (const char *__thisdir,
           char *__buf,
           size_t __size) ;

extern int __dup (int __fd);
extern int __dup2 (int __fd, int __fd2);

extern int __dup3 (int __fd, int __fd2, int flags);

extern int __execve (const char *__path, char *const __argv[],
       char *const __envp[]);
extern long int __pathconf (const char *__path, int __name);
extern long int __fpathconf (int __fd, int __name);
extern long int __sysconf (int __name);

extern __pid_t __getpid (void);

extern __pid_t __getppid (void);
extern __pid_t __setsid (void);
extern __uid_t __getuid (void);
extern __uid_t __geteuid (void);
extern __gid_t __getgid (void);
extern __gid_t __getegid (void);
extern int __getgroups (int __size, __gid_t __list[]);

extern int __group_member (__gid_t __gid);
extern int __setuid (__uid_t __uid);
extern int __setreuid (__uid_t __ruid, __uid_t __euid);
extern int __setgid (__gid_t __gid);
extern int __setpgid (__pid_t __pid, __pid_t __pgid);

extern int __setregid (__gid_t __rgid, __gid_t __egid);
extern int __getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid);
extern int __getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid);
extern int __setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid);
extern int __setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid);




extern __pid_t __vfork (void);

extern int __ttyname_r (int __fd, char *__buf, size_t __buflen);
extern int __isatty (int __fd);
extern int __link (const char *__from, const char *__to);
extern int __symlink (const char *__from, const char *__to);
extern ssize_t __readlink (const char *__path, char *__buf, size_t __len);
extern int __unlink (const char *__name);
extern int __gethostname (char *__name, size_t __len);
extern int __profil (unsigned short int *__sample_buffer, size_t __size,
       size_t __offset, unsigned int __scale);
extern int __getdtablesize (void);
extern int __brk (void *__addr);
extern int __close (int __fd);

extern int __libc_close (int __fd);
extern ssize_t __read (int __fd, void *__buf, size_t __nbytes);

extern ssize_t __write (int __fd, const void *__buf, size_t __n);

extern __pid_t __fork (void);

extern int __getpagesize (void) __attribute__ ((__const__));

extern int __ftruncate (int __fd, __off_t __length);
extern int __ftruncate64 (int __fd, __off64_t __length);
extern int __truncate (const char *path, __off_t __length);
extern void *__sbrk (intptr_t __delta);








extern int __libc_enable_secure __attribute__ ((section (".data.rel.ro")));
extern int __libc_enable_secure_decided;




extern void __libc_check_standard_fds (void) ;



extern __pid_t __libc_fork (void);



extern int __libc_pause (void);

extern int __pause_nocancel (void) ;

extern int __have_pipe2 ;
extern int __have_dup3 ;

extern int __getlogin_r_loginuid (char *name, size_t namesize)
     ;






# 20 "../sysdeps/posix/readv.c" 2
# 1 "../include/string.h" 1



# 1 "../include/sys/types.h" 1
# 5 "../include/string.h" 2

extern void *__memccpy (void *__dest, const void *__src,
   int __c, size_t __n);

extern size_t __strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__pure__));

extern char *__strsep (char **__stringp, const char *__delim);

extern int __strverscmp (const char *__s1, const char *__s2)
     __attribute__ ((__pure__));

extern int __strncasecmp (const char *__s1, const char *__s2,
     size_t __n)
     __attribute__ ((__pure__));

extern int __strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__pure__));

extern char *__strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__pure__));

extern char *__strdup (const char *__string)
     __attribute__ ((__malloc__));
extern char *__strndup (const char *__string, size_t __n)
     __attribute__ ((__malloc__));

extern void *__rawmemchr (const void *__s, int __c)
     __attribute__ ((__pure__));

extern char *__strchrnul (const char *__s, int __c)
     __attribute__ ((__pure__));

extern void *__memrchr (const void *__s, int __c, size_t __n)
     __attribute__ ((__pure__));

extern void *__memchr (const void *__s, int __c, size_t __n)
     __attribute__ ((__pure__));

extern int __ffs (int __i) __attribute__ ((const));

extern char *__strerror_r (int __errnum, char *__buf, size_t __buflen);




# 1 "../string/string.h" 1
# 27 "../string/string.h"





# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 33 "../string/string.h" 2









extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ )) ;


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ )) ;






extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ )) ;





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ )) ;


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 92 "../string/string.h"
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;


# 106 "../string/string.h"
extern void *rawmemchr (const void *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 117 "../string/string.h"
extern void *memrchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;






extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) ;

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) ;


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) ;

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ )) ;


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) ;






# 1 "../include/xlocale.h" 1
# 160 "../string/string.h" 2


extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;

extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ )) ;




extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;
# 206 "../string/string.h"

# 231 "../string/string.h"
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 258 "../string/string.h"
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;


# 272 "../string/string.h"
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;






extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 310 "../string/string.h"
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 337 "../string/string.h"
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) ;




extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) ;

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) ;
# 368 "../string/string.h"
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) ;
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) ;





extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;





extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;





extern char *strerror (int __errnum) __attribute__ ((__nothrow__ ));

# 433 "../string/string.h"
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ )) ;





extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ ));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) ;



extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ )) ;


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) ;


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 484 "../string/string.h"
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;
# 512 "../string/string.h"
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;




extern int ffs (int __i) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));




extern int ffsl (long int __l) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;





extern int strcasecmp_l (const char *__s1, const char *__s2,
    __locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;

extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, __locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;





extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) ;




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ ));


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) ;
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) ;



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) ;
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) ;




extern int strverscmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) ;


extern char *strfry (char *__string) __attribute__ ((__nothrow__ )) ;


extern void *memfrob (void *__s, size_t __n) __attribute__ ((__nothrow__ )) ;
# 599 "../string/string.h"
extern char *basename (const char *__filename) __attribute__ ((__nothrow__ )) ;
# 627 "../string/string.h"
# 1 "../bits/string.h" 1
# 628 "../string/string.h" 2


# 1 "../include/bits/string2.h" 1
# 1 "../string/bits/string2.h" 1
# 79 "../string/bits/string2.h"
typedef struct { unsigned char __arr[2]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR2;
typedef struct { unsigned char __arr[3]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR3;
typedef struct { unsigned char __arr[4]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR4;
typedef struct { unsigned char __arr[5]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR5;
typedef struct { unsigned char __arr[6]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR6;
typedef struct { unsigned char __arr[7]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR7;
typedef struct { unsigned char __arr[8]; } __attribute__ ((__packed__)) __STRING2_COPY_ARR8;
# 393 "../string/bits/string2.h"
extern void *__rawmemchr (const void *__s, int __c);
# 945 "../string/bits/string2.h"
extern __inline size_t __strcspn_c1 (const char *__s, int __reject);
extern __inline size_t
__strcspn_c1 (const char *__s, int __reject)
{
  size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject)
    ++__result;
  return __result;
}

extern __inline size_t __strcspn_c2 (const char *__s, int __reject1,
         int __reject2);
extern __inline size_t
__strcspn_c2 (const char *__s, int __reject1, int __reject2)
{
  size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
  && __s[__result] != __reject2)
    ++__result;
  return __result;
}

extern __inline size_t __strcspn_c3 (const char *__s, int __reject1,
         int __reject2, int __reject3);
extern __inline size_t
__strcspn_c3 (const char *__s, int __reject1, int __reject2,
       int __reject3)
{
  size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
  && __s[__result] != __reject2 && __s[__result] != __reject3)
    ++__result;
  return __result;
}
# 1021 "../string/bits/string2.h"
extern __inline size_t __strspn_c1 (const char *__s, int __accept);
extern __inline size_t
__strspn_c1 (const char *__s, int __accept)
{
  size_t __result = 0;

  while (__s[__result] == __accept)
    ++__result;
  return __result;
}

extern __inline size_t __strspn_c2 (const char *__s, int __accept1,
        int __accept2);
extern __inline size_t
__strspn_c2 (const char *__s, int __accept1, int __accept2)
{
  size_t __result = 0;

  while (__s[__result] == __accept1 || __s[__result] == __accept2)
    ++__result;
  return __result;
}

extern __inline size_t __strspn_c3 (const char *__s, int __accept1,
        int __accept2, int __accept3);
extern __inline size_t
__strspn_c3 (const char *__s, int __accept1, int __accept2, int __accept3)
{
  size_t __result = 0;

  while (__s[__result] == __accept1 || __s[__result] == __accept2
  || __s[__result] == __accept3)
    ++__result;
  return __result;
}
# 1097 "../string/bits/string2.h"
extern __inline char *__strpbrk_c2 (const char *__s, int __accept1,
        int __accept2);
extern __inline char *
__strpbrk_c2 (const char *__s, int __accept1, int __accept2)
{

  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2)
    ++__s;
  return *__s == '\0' ? 
# 1105 "../string/bits/string2.h" 3 4
                       ((void *)0) 
# 1105 "../string/bits/string2.h"
                            : (char *) (size_t) __s;
}

extern __inline char *__strpbrk_c3 (const char *__s, int __accept1,
        int __accept2, int __accept3);
extern __inline char *
__strpbrk_c3 (const char *__s, int __accept1, int __accept2, int __accept3)
{

  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2
  && *__s != __accept3)
    ++__s;
  return *__s == '\0' ? 
# 1117 "../string/bits/string2.h" 3 4
                       ((void *)0) 
# 1117 "../string/bits/string2.h"
                            : (char *) (size_t) __s;
}
# 1147 "../string/bits/string2.h"
extern __inline char *__strtok_r_1c (char *__s, char __sep, char **__nextp);
extern __inline char *
__strtok_r_1c (char *__s, char __sep, char **__nextp)
{
  char *__result;
  if (__s == 
# 1152 "../string/bits/string2.h" 3 4
            ((void *)0)
# 1152 "../string/bits/string2.h"
                )
    __s = *__nextp;
  while (*__s == __sep)
    ++__s;
  __result = 
# 1156 "../string/bits/string2.h" 3 4
            ((void *)0)
# 1156 "../string/bits/string2.h"
                ;
  if (*__s != '\0')
    {
      __result = __s++;
      while (*__s != '\0')
 if (*__s++ == __sep)
   {
     __s[-1] = '\0';
     break;
   }
    }
  *__nextp = __s;
  return __result;
}
# 1179 "../string/bits/string2.h"
extern char *__strsep_g (char **__stringp, const char *__delim);
# 1197 "../string/bits/string2.h"
extern __inline char *__strsep_1c (char **__s, char __reject);
extern __inline char *
__strsep_1c (char **__s, char __reject)
{
  char *__retval = *__s;
  if (__retval != 
# 1202 "../string/bits/string2.h" 3 4
                 ((void *)0) 
# 1202 "../string/bits/string2.h"
                      && (*__s = (__extension__ (__builtin_constant_p (__reject) && !__builtin_constant_p (__retval) && (__reject) == '\0' ? (char *) __rawmemchr (__retval, __reject) : __builtin_strchr (__retval, __reject)))) != 
# 1202 "../string/bits/string2.h" 3 4
                                                                 ((void *)0)
# 1202 "../string/bits/string2.h"
                                                                     )
    *(*__s)++ = '\0';
  return __retval;
}

extern __inline char *__strsep_2c (char **__s, char __reject1, char __reject2);
extern __inline char *
__strsep_2c (char **__s, char __reject1, char __reject2)
{
  char *__retval = *__s;
  if (__retval != 
# 1212 "../string/bits/string2.h" 3 4
                 ((void *)0)
# 1212 "../string/bits/string2.h"
                     )
    {
      char *__cp = __retval;
      while (1)
 {
   if (*__cp == '\0')
     {
       __cp = 
# 1219 "../string/bits/string2.h" 3 4
             ((void *)0)
# 1219 "../string/bits/string2.h"
                 ;
   break;
     }
   if (*__cp == __reject1 || *__cp == __reject2)
     {
       *__cp++ = '\0';
       break;
     }
   ++__cp;
 }
      *__s = __cp;
    }
  return __retval;
}

extern __inline char *__strsep_3c (char **__s, char __reject1, char __reject2,
       char __reject3);
extern __inline char *
__strsep_3c (char **__s, char __reject1, char __reject2, char __reject3)
{
  char *__retval = *__s;
  if (__retval != 
# 1240 "../string/bits/string2.h" 3 4
                 ((void *)0)
# 1240 "../string/bits/string2.h"
                     )
    {
      char *__cp = __retval;
      while (1)
 {
   if (*__cp == '\0')
     {
       __cp = 
# 1247 "../string/bits/string2.h" 3 4
             ((void *)0)
# 1247 "../string/bits/string2.h"
                 ;
   break;
     }
   if (*__cp == __reject1 || *__cp == __reject2 || *__cp == __reject3)
     {
       *__cp++ = '\0';
       break;
     }
   ++__cp;
 }
      *__s = __cp;
    }
  return __retval;
}
# 1278 "../string/bits/string2.h"
extern char *__strdup (const char *__string) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__));
# 1297 "../string/bits/string2.h"
extern char *__strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__));
# 1 "../include/bits/string2.h" 2
# 631 "../string/string.h" 2
# 648 "../string/string.h"
extern __inline __attribute__ ((__always_inline__)) void *
__mempcpy_inline (void *__restrict __dest,
    const void *__restrict __src, size_t __n)
{
  return (char *) memcpy (__dest, __src, __n) + __n;
}





# 52 "../include/string.h" 2


extern __typeof (strcoll_l) __strcoll_l;
extern __typeof (strxfrm_l) __strxfrm_l;
extern __typeof (strcasecmp_l) __strcasecmp_l;
extern __typeof (strncasecmp_l) __strncasecmp_l;
# 73 "../include/string.h"












extern char *__basename (const char *__filename) __attribute__ ((__nothrow__ )) ;





extern char *__strsep_g (char **__stringp, const char *__delim);




extern __typeof (memmem) __memmem;























# 145 "../include/string.h"
extern __typeof (mempcpy) mempcpy __asm__ ("__mempcpy");
extern __typeof (stpcpy) stpcpy __asm__ ("__stpcpy");
# 158 "../include/string.h"
extern void *__memcpy_chk (void *__restrict __dest,
      const void *__restrict __src, size_t __len,
      size_t __destlen) __attribute__ ((__nothrow__ ));
extern void *__memmove_chk (void *__dest, const void *__src, size_t __len,
       size_t __destlen) __attribute__ ((__nothrow__ ));
extern void *__mempcpy_chk (void *__restrict __dest,
       const void *__restrict __src, size_t __len,
       size_t __destlen) __attribute__ ((__nothrow__ ));
extern void *__memset_chk (void *__dest, int __ch, size_t __len,
      size_t __destlen) __attribute__ ((__nothrow__ ));
extern char *__strcpy_chk (char *__restrict __dest,
      const char *__restrict __src,
      size_t __destlen) __attribute__ ((__nothrow__ ));
extern char *__stpcpy_chk (char *__restrict __dest,
      const char *__restrict __src,
      size_t __destlen) __attribute__ ((__nothrow__ ));
extern char *__strncpy_chk (char *__restrict __dest,
       const char *__restrict __src,
       size_t __len, size_t __destlen) __attribute__ ((__nothrow__ ));
extern char *__strcat_chk (char *__restrict __dest,
      const char *__restrict __src,
      size_t __destlen) __attribute__ ((__nothrow__ ));
extern char *__strncat_chk (char *__restrict __dest,
       const char *__restrict __src,
       size_t __len, size_t __destlen) __attribute__ ((__nothrow__ ));
# 21 "../sysdeps/posix/readv.c" 2
# 1 "../include/limits.h" 1
# 123 "../include/limits.h"
# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include-fixed/limits.h" 1 3 4
# 124 "../include/limits.h" 2
# 143 "../include/limits.h"
# 1 "../include/bits/posix1_lim.h" 1
# 1 "../posix/bits/posix1_lim.h" 1
# 160 "../posix/bits/posix1_lim.h"
# 1 "../sysdeps/asmjs/bits/local_lim.h" 1
# 161 "../posix/bits/posix1_lim.h" 2
# 1 "../include/bits/posix1_lim.h" 2
# 144 "../include/limits.h" 2



# 1 "../include/bits/posix2_lim.h" 1
# 1 "../posix/bits/posix2_lim.h" 1
# 1 "../include/bits/posix2_lim.h" 2
# 148 "../include/limits.h" 2



# 1 "../include/bits/xopen_lim.h" 1
# 33 "../include/bits/xopen_lim.h"
# 1 "/home/pip/build/glibc/asmjs-20160214/bits/stdio_lim.h" 1
# 34 "../include/bits/xopen_lim.h" 2
# 152 "../include/limits.h" 2
# 22 "../sysdeps/posix/readv.c" 2
# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stdbool.h" 1 3 4
# 23 "../sysdeps/posix/readv.c" 2
# 1 "../include/sys/param.h" 1
# 1 "../misc/sys/param.h" 1
# 23 "../misc/sys/param.h"
# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 24 "../misc/sys/param.h" 2

# 1 "../include/sys/types.h" 1
# 26 "../misc/sys/param.h" 2
# 1 "../include/limits.h" 1
# 143 "../include/limits.h"
# 1 "../include/bits/posix1_lim.h" 1
# 144 "../include/limits.h" 2



# 1 "../include/bits/posix2_lim.h" 1
# 148 "../include/limits.h" 2
# 27 "../misc/sys/param.h" 2
# 1 "../include/endian.h" 1
# 28 "../misc/sys/param.h" 2
# 1 "../include/signal.h" 1




# 1 "../signal/signal.h" 1
# 30 "../signal/signal.h"


# 1 "../bits/sigset.h" 1
# 63 "../bits/sigset.h"
extern int __sigismember (const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 76 "../bits/sigset.h"
extern __inline int __sigismember (const __sigset_t *__set, int __sig) { __sigset_t __mask = (((__sigset_t) 1) << ((__sig) - 1)); return (*__set & __mask) ? 1 : 0; }
extern __inline int __sigaddset ( __sigset_t *__set, int __sig) { __sigset_t __mask = (((__sigset_t) 1) << ((__sig) - 1)); return ((*__set |= __mask), 0); }
extern __inline int __sigdelset ( __sigset_t *__set, int __sig) { __sigset_t __mask = (((__sigset_t) 1) << ((__sig) - 1)); return ((*__set &= ~__mask), 0); }
# 33 "../signal/signal.h" 2







typedef __sig_atomic_t sig_atomic_t;

# 57 "../signal/signal.h"
# 1 "../bits/signum.h" 1
# 58 "../signal/signal.h" 2
# 75 "../signal/signal.h"
# 1 "../include/time.h" 1


# 1 "../time/time.h" 1
# 4 "../include/time.h" 2
# 76 "../signal/signal.h" 2




# 1 "../bits/siginfo.h" 1
# 30 "../bits/siginfo.h"
typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;






typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;
    __pid_t si_pid;
    __uid_t si_uid;
    void *si_addr;
    int si_status;
    long int si_band;
    union sigval si_value;
  } siginfo_t;




enum
{
  SI_ASYNCIO = -4,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER

};




enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};




enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};




enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 196 "../bits/siginfo.h"
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    void (*sigev_notify_function) (sigval_t);
    void *sigev_notify_attributes;
  } sigevent_t;


enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD

};
# 81 "../signal/signal.h" 2




typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ ));

extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ ));







extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ ));
# 114 "../signal/signal.h"





extern __sighandler_t bsd_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ ));






extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ ));






extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ ));




extern int raise (int __sig) __attribute__ ((__nothrow__ ));




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ ));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ ));




extern void psignal (int __sig, const char *__s);


extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
# 168 "../signal/signal.h"
extern int sigpause (int __sig) __asm__ ("__xpg_sigpause");
# 187 "../signal/signal.h"
extern int sigblock (int __mask) __attribute__ ((__nothrow__ )) __attribute__ ((__deprecated__));


extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ )) __attribute__ ((__deprecated__));


extern int siggetmask (void) __attribute__ ((__nothrow__ )) __attribute__ ((__deprecated__));
# 202 "../signal/signal.h"
typedef __sighandler_t sighandler_t;




typedef __sighandler_t sig_t;





extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ )) ;


extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ )) ;


extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ )) ;


extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ )) ;


extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ )) ;



extern int sigisemptyset (const sigset_t *__set) __attribute__ ((__nothrow__ )) ;


extern int sigandset (sigset_t *__set, const sigset_t *__left,
        const sigset_t *__right) __attribute__ ((__nothrow__ )) ;


extern int sigorset (sigset_t *__set, const sigset_t *__left,
       const sigset_t *__right) __attribute__ ((__nothrow__ )) ;




# 1 "../bits/sigaction.h" 1
# 29 "../bits/sigaction.h"
struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;
  };
# 244 "../signal/signal.h" 2


extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ ));






extern int sigsuspend (const sigset_t *__set) ;


extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ ));


extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ )) ;






extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     ;






extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) ;






extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     ;



extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ ));
# 301 "../signal/signal.h"
extern const char *const _sys_siglist[32];
extern const char *const sys_siglist[32];



# 1 "../bits/sigcontext.h" 1
# 24 "../bits/sigcontext.h"
struct sigcontext
  {
    int sc_onstack;
    __sigset_t sc_mask;


  };
# 307 "../signal/signal.h" 2


extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ ));






# 1 "/usr/local/lib/gcc/asmjs-virtual-gnu/6.0.0/include/stddef.h" 1 3 4
# 317 "../signal/signal.h" 2




extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ ));

# 1 "../bits/sigstack.h" 1
# 25 "../bits/sigstack.h"
struct sigstack
  {
    void * ss_sp;
    int ss_onstack;
  };



typedef struct sigaltstack
  {
    void * ss_sp;
    size_t ss_size;
    int ss_flags;
  } stack_t;



enum
{
  SS_ONSTACK = 0x0001,

  SS_DISABLE = 0x0004

};
# 324 "../signal/signal.h" 2


# 1 "../sysdeps/asmjs/sys/ucontext.h" 1
# 26 "../sysdeps/asmjs/sys/ucontext.h"
# 1 "../include/signal.h" 1
# 27 "../sysdeps/asmjs/sys/ucontext.h" 2

typedef struct sigcontext mcontext_t;


typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
  } ucontext_t;
# 327 "../signal/signal.h" 2





extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ )) __attribute__ ((__deprecated__));



extern int sigaltstack (const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) __attribute__ ((__nothrow__ ));







extern int sighold (int __sig) __attribute__ ((__nothrow__ ));


extern int sigrelse (int __sig) __attribute__ ((__nothrow__ ));


extern int sigignore (int __sig) __attribute__ ((__nothrow__ ));


extern __sighandler_t sigset (int __sig, __sighandler_t __disp) __attribute__ ((__nothrow__ ));





# 1 "../bits/pthreadtypes.h" 1
# 362 "../signal/signal.h" 2
# 1 "../bits/sigthread.h" 1
# 30 "../bits/sigthread.h"
extern int pthread_sigmask (int __how, const __sigset_t *__newmask,
       __sigset_t *__oldmask) __attribute__ ((__nothrow__ ));
# 363 "../signal/signal.h" 2






extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ ));

extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ ));




# 6 "../include/signal.h" 2







extern int __sigpause (int sig_or_mask, int is_sig);







extern __sighandler_t __bsd_signal (int __sig, __sighandler_t __handler);
extern int __kill (__pid_t __pid, int __sig);
extern int __sigaction (int __sig, const struct sigaction *__restrict __act,
   struct sigaction *__restrict __oact);

extern int __sigblock (int __mask);
extern int __sigsetmask (int __mask);
extern int __sigprocmask (int __how,
     const sigset_t *__set, sigset_t *__oset);
extern int __sigsuspend (const sigset_t *__set);


extern int __sigsuspend_nocancel (const sigset_t *__set) ;

extern int __sigwait (const sigset_t *__set, int *__sig);

extern int __sigwaitinfo (const sigset_t *__set, siginfo_t *__info);

extern int __sigtimedwait (const sigset_t *__set, siginfo_t *__info,
      const struct timespec *__timeout);

extern int __sigqueue (__pid_t __pid, int __sig,
         const union sigval __val);

extern int __sigreturn (struct sigcontext *__scp);

extern int __sigaltstack (const struct sigaltstack *__ss,
     struct sigaltstack *__oss);
extern int __libc_sigaction (int sig, const struct sigaction *act,
        struct sigaction *oact);


extern int __default_sigpause (int mask);
extern int __xpg_sigpause (int sig);
# 63 "../include/signal.h"
extern int __libc_allocate_rtsig (int __high);
# 29 "../misc/sys/param.h" 2


# 1 "../bits/param.h" 1
# 32 "../misc/sys/param.h" 2
# 1 "../include/sys/param.h" 2
# 24 "../sysdeps/posix/readv.c" 2
# 1 "../include/sys/uio.h" 1

# 1 "../misc/sys/uio.h" 1
# 23 "../misc/sys/uio.h"
# 1 "../include/sys/types.h" 1
# 24 "../misc/sys/uio.h" 2




# 1 "../bits/uio.h" 1
# 25 "../bits/uio.h"
struct iovec
{

  void * iov_base;

  size_t iov_len;
};
# 29 "../misc/sys/uio.h" 2
# 39 "../misc/sys/uio.h"
extern ssize_t readv (int __fd, const struct iovec *__iovec, int __count)
  ;
# 50 "../misc/sys/uio.h"
extern ssize_t writev (int __fd, const struct iovec *__iovec, int __count)
  ;
# 65 "../misc/sys/uio.h"
extern ssize_t preadv (int __fd, const struct iovec *__iovec, int __count,
         __off_t __offset) ;
# 77 "../misc/sys/uio.h"
extern ssize_t pwritev (int __fd, const struct iovec *__iovec, int __count,
   __off_t __offset) ;
# 103 "../misc/sys/uio.h"
extern ssize_t preadv64 (int __fd, const struct iovec *__iovec, int __count,
    __off64_t __offset) ;
# 115 "../misc/sys/uio.h"
extern ssize_t pwritev64 (int __fd, const struct iovec *__iovec, int __count,
     __off64_t __offset) ;




# 3 "../include/sys/uio.h" 2



extern ssize_t __readv (int __fd, const struct iovec *__iovec,
   int __count);
extern ssize_t __writev (int __fd, const struct iovec *__iovec,
    int __count);
# 25 "../sysdeps/posix/readv.c" 2
# 1 "../include/errno.h" 1


# 1 "../stdlib/errno.h" 1
# 31 "../stdlib/errno.h"




# 1 "../sysdeps/asmjs/bits/errno.h" 1
# 209 "../sysdeps/asmjs/bits/errno.h"
extern int *__errno_location (void) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));
# 36 "../stdlib/errno.h" 2
# 54 "../stdlib/errno.h"
extern char *program_invocation_name, *program_invocation_short_name;




# 68 "../stdlib/errno.h"
typedef int error_t;
# 4 "../include/errno.h" 2
# 42 "../include/errno.h"
extern int *__errno_location (void) __attribute__ ((__nothrow__ )) __attribute__ ((__const__))



;

# 26 "../sysdeps/posix/readv.c" 2


static void
ifree (char **ptrp)
{
  free (*ptrp);
}






ssize_t
__readv (int fd, const struct iovec *vector, int count)
{

  size_t bytes = 0;
  for (int i = 0; i < count; ++i)
    {

      if (0x7fffffffL - bytes < vector[i].iov_len)
 {
   ((*__errno_location ()) = (22));
   return -1;
 }
      bytes += vector[i].iov_len;
    }





  char *buffer;
  char *malloced_buffer __attribute__ ((__cleanup__ (ifree))) = 
# 60 "../sysdeps/posix/readv.c" 3 4
                                                               ((void *)0)
# 60 "../sysdeps/posix/readv.c"
                                                                   ;
  if (__libc_use_alloca (bytes))
    buffer = (char *) __builtin_alloca (bytes);
  else
    {
      malloced_buffer = buffer = (char *) malloc (bytes);
      if (buffer == 
# 66 "../sysdeps/posix/readv.c" 3 4
                   ((void *)0)
# 66 "../sysdeps/posix/readv.c"
                       )
 return -1;
    }


  ssize_t bytes_read = __read (fd, buffer, bytes);
  if (bytes_read < 0)
    return -1;


  bytes = bytes_read;
  for (int i = 0; i < count; ++i)
    {
      size_t copy = (((vector[i].iov_len)<(bytes))?(vector[i].iov_len):(bytes));

      (void) memcpy ((void *) vector[i].iov_base, (void *) buffer, copy);

      buffer += copy;
      bytes -= copy;
      if (bytes == 0)
 break;
    }

  return bytes_read;
}
