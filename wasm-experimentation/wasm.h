typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;

void *mem;

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

i64 import$0(i64 x)
{
  fprintf(stderr, "debug: %lx\n", x);
}

i64 import$2(i64 dpc, i64 sp, i64 r0, i64 r1, i64 rpc, i64 pc0);

i64 import$1(i64 a0, i64 a1, i64 a2, i64 a3)
{
  fprintf(stderr, "import call: %s/%s\n", (const char *)mem+a0, (const char *)mem+a1);

  if (strcmp ((const char *)mem+a1, "write") == 0) {
    fprintf(stderr, "write: (%lx) %s\n",*(i64 *)((((mem + a3))+0x30)),
            mem + *(i64 *)(mem+a3+0x28));
    *(i64 *)(mem + 4096) = *(i64 *)((((mem + a3))+0x30));
  } else if (strcmp((const char *)mem+a1, "exit") == 0) {
    exit(0);
  } else {
    *(i64 *)(mem + 4096) = -1LL;
  }
}
i64 import$3(i64 x, i64 y, i64 z)
{
  fprintf(stderr, "mystery call: %lx\n", x);
}

extern i64 f_0x4000000000025000(i64, i64, i64, i64, i64, i64);

int main(void)
{
  mem = malloc(64 * 1024 * 1024);

  FILE *f;
  f = fopen("wasm.data", "r");
  
  if (!f)
    return 1;

  void *p = mem + 0x4040;
  size_t res;
  while (res = fread(p, 1, 4096, f))
    p += res;

  fclose(f);

  f_0x4000000000025000(0, 2 * 1024 * 1024, 0, 0, 0, 0x400000000002500UL);

  return 0;
}

i32 i64_eq(i64 a, i64 b) { return a == b; }
i32 i64_ne(i64 a, i64 b) { return a != b; }

i32 f64_eq(f64 a, f64 b) { return a == b; }
i32 f64_ne(f64 a, f64 b) { return a != b; }
i32 f64_lt(f64 a, f64 b) { return a <  b; }
i32 f64_gt(f64 a, f64 b) { return a >  b; }
i32 f64_le(f64 a, f64 b) { return a <= b; }
i32 f64_ge(f64 a, f64 b) { return a >= b; }

i32 i64_lt_u(i64 a, i64 b) { return (unsigned long)a <  (unsigned long)b; }
i32 i64_gt_u(i64 a, i64 b) { return (unsigned long)a >  (unsigned long)b; }
i32 i64_le_u(i64 a, i64 b) { return (unsigned long)a <= (unsigned long)b; }
i32 i64_ge_u(i64 a, i64 b) { return (unsigned long)a >= (unsigned long)b; }

i32 i64_lt_s(i64 a, i64 b) { return a <  b; }
i32 i64_gt_s(i64 a, i64 b) { return a >  b; }
i32 i64_le_s(i64 a, i64 b) { return a <= b; }
i32 i64_ge_s(i64 a, i64 b) { return a >= b; }

i64 i64_shl(i64 a, i64 b)
{
  return a << (b&63);
}

i64 i64_shr_s(i64 a, i64 b)
{
  return a >> (b&63);
}

i64 i64_shr_u(i64 a, i64 b)
{
  return (unsigned long)a >> (b&63);
}

i64 i64_reinterpret_f64(f64 x)
{
  return *(i64 *)(&x);
}

f64 f64_reinterpret_i64(i64 x)
{
  return *(f64 *)(&x);
}

i32 load_i32_i8_u(i32 ptr)
{
  return *(unsigned char *)(mem + ptr);
}

i32 load_i32_i8_s(i32 ptr)
{
  return *(signed char *)(mem + ptr);
}

i32 load_i32_i16_u(i32 ptr)
{
  return *(unsigned short *)(mem + ptr);
}

i32 load_i32_i16_s(i32 ptr)
{
  return *(short *)(mem + ptr);
}

i32 load_i32_i32_u(i32 ptr)
{
  return *(i32 *)(mem + ptr);
}

i32 load_i32_i32_s(i32 ptr)
{
  return *(i32 *)(mem + ptr);
}

i64 load_i64_i64(i32 ptr)
{
  return *(i64 *)(mem + ptr);
}

f32 load_f32_f32(i32 ptr)
{
  return *(f32 *)(mem + ptr);
}

f64 load_f64_f64(i32 ptr)
{
  return *(f64 *)(mem + ptr);
}

i32 i32_wrap_i64(i64 x)
{
  return (i32)x;
}

i64 i64_extend_s_i32(i32 x)
{
  return (i64)x;
}

i64 i64_extend_u_i32(i32 x)
{
  return (i64)(unsigned int)x;
}

i32 store_i32_i8(i32 ptr, i32 value)
{
  return *(char *)(mem + ptr) = value;
}

i32 store_i32_i16(i32 ptr, i32 value)
{
  return *(short *)(mem + ptr) = value;
}

i32 store_i32_i32(i32 ptr, i32 value)
{
  return *(i32 *)(mem + ptr) = value;
}

i64 store_i64_i64(i32 ptr, i64 value)
{
  return *(i64 *)(mem + ptr) = value;
}

f64 store_f64_f64(i32 ptr, f64 value)
{
  return *(f64 *)(mem + ptr) = value;
}

f32 store_f32_f32(i32 ptr, f32 value)
{
  return *(f32 *)(mem + ptr) = value;
}

i64 i64_add(i64 a, i64 b) { return a + b; }
i64 i64_sub(i64 a, i64 b) { return a - b; }
i64 i64_and(i64 a, i64 b) { return a & b; }
i64 i64_xor(i64 a, i64 b) { return a ^ b; }
i64 i64_or (i64 a, i64 b) { return a | b; }
i64 i64_mul(i64 a, i64 b) { return a * b; }
i64 i64_div_s(i64 a, i64 b) { return a / b; }
i64 i64_div_u(i64 a, i64 b) { return (unsigned long)a/(unsigned long)b; }
i64 i64_rem_s(i64 a, i64 b) { return a % b; }
i64 i64_rem_u(i64 a, i64 b) { return (unsigned long)a%(unsigned long)b; }

f64 f64_add(f64 a, f64 b) { return a + b; }
f64 f64_sub(f64 a, f64 b) { return a - b; }
f64 f64_mul(f64 a, f64 b) { return a * b; }
f64 f64_div(f64 a, f64 b) { return a / b; }

f32 f32_div(f32 a, f32 b) { return a / b; }

i32 i32_and(i32 a, i32 b) { return a & b; }
