extern int sprintf (char *__s, ...) __attribute__ ((__nothrow__));
extern __typeof (sprintf) sprintf __attribute__ ((visibility ("hidden")));

int __sprintf(char *s, ...)
{
  return 0;
}

extern __typeof (__sprintf) sprintf __attribute__ ((alias ("__sprintf"))) __attribute__((visibility("default")));
