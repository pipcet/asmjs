#if 0
struct __attribute__((jsexport)) {
  int x;
  int y;
  int z;
};

struct __attribute__((jsexport)) s {
  int x;
  int y;
  int z;
};

typedef struct __attribute__((jsexport)) s2 {
  int x;
  int y;
  int z;
} s2;
#endif

__attribute__((jsexport)) int i;
__attribute__((jsexport)) long long ll;
#if 0
__attribute__((jsexport)) struct s s3;
__attribute__((jsexport)) struct s2 s4;
__attribute__((jsexport)) s2 s5;
#endif

int main(void)
{
  return 0;
}
