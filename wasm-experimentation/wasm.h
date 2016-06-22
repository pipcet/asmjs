typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;

void *mem;

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

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

i32 f32_eq(f32 a, f32 b) { return a == b; }
i32 f32_ne(f32 a, f32 b) { return a != b; }
i32 f32_lt(f32 a, f32 b) { return a <  b; }
i32 f32_gt(f32 a, f32 b) { return a >  b; }
i32 f32_le(f32 a, f32 b) { return a <= b; }
i32 f32_ge(f32 a, f32 b) { return a >= b; }

i32 i64_lt_u(i64 a, i64 b) { return (unsigned long)a <  (unsigned long)b; }
i32 i64_gt_u(i64 a, i64 b) { return (unsigned long)a >  (unsigned long)b; }
i32 i64_le_u(i64 a, i64 b) { return (unsigned long)a <= (unsigned long)b; }
i32 i64_ge_u(i64 a, i64 b) { return (unsigned long)a >= (unsigned long)b; }

i32 i64_lt_s(i64 a, i64 b) { return a <  b; }
i32 i64_gt_s(i64 a, i64 b) { return a >  b; }
i32 i64_le_s(i64 a, i64 b) { return a <= b; }
i32 i64_ge_s(i64 a, i64 b) { return a >= b; }

i32 i32_eq(i32 a, i32 b) { return a == b; }
i32 i32_ne(i32 a, i32 b) { return a != b; }

i32 i32_lt_u(i32 a, i32 b) { return (unsigned)a <  (unsigned)b; }
i32 i32_gt_u(i32 a, i32 b) { return (unsigned)a >  (unsigned)b; }
i32 i32_le_u(i32 a, i32 b) { return (unsigned)a <= (unsigned)b; }
i32 i32_ge_u(i32 a, i32 b) { return (unsigned)a >= (unsigned)b; }

i32 i32_lt_s(i32 a, i32 b) { return a <  b; }
i32 i32_gt_s(i32 a, i32 b) { return a >  b; }
i32 i32_le_s(i32 a, i32 b) { return a <= b; }
i32 i32_ge_s(i32 a, i32 b) { return a >= b; }

i64 i64_shl(i64 a, i64 b) { return a << (b&63); }
i64 i64_shr_s(i64 a, i64 b) { return a >> (b&63); }
i64 i64_shr_u(i64 a, i64 b) { return (unsigned long)a >> (b&63); }
i64 i64_rotr(i64 a, i64 b) { return a>>(b&63) | a<<(32-(b&63)); }
i64 i64_rotl(i64 a, i64 b) { return a<<(b&63) | a>>(32-(b&63)); }

i32 i32_shl(i32 a, i32 b) { return a << (b&31); }
i32 i32_shr_s(i32 a, i32 b) { return a >> (b&31); }
i32 i32_shr_u(i32 a, i32 b) { return (unsigned long)a >> (b&31); }
i32 i32_rotr(i32 a, i32 b) { return a>>(b&31) | a<<(32-(b&31)); }
i32 i32_rotl(i32 a, i32 b) { return a<<(b&31) | a>>(32-(b&31)); }

i64 i64_reinterpret_f64(f64 x)
{
  return *(i64 *)(&x);
}

f64 f64_reinterpret_i64(i64 x)
{
  return *(f64 *)(&x);
}

i32 i32_reinterpret_f32(f32 x)
{
  return *(i32 *)(&x);
}

f32 f32_reinterpret_i32(i32 x)
{
  return *(f32 *)(&x);
}

i32 fix_ptr(i32 ptr)
{
  return ptr & 0xffffffff;
}

i32 load_i32_i8_u(i32 ptr)
{
  return *(unsigned char *)(mem + fix_ptr(ptr));
}

i32 load_i32_i8_s(i32 ptr)
{
  return *(signed char *)(mem + fix_ptr(ptr));
}

i32 load_i32_i16_u(i32 ptr)
{
  return *(unsigned short *)(mem + fix_ptr(ptr));
}

i32 load_i32_i16_s(i32 ptr)
{
  return *(short *)(mem + fix_ptr(ptr));
}

i32 load_i32_i32_u(i32 ptr)
{
  return *(i32 *)(mem + fix_ptr(ptr));
}

i32 load_i32_i32_s(i32 ptr)
{
  return *(i32 *)(mem + fix_ptr(ptr));
}

i64 load_i64_i64_u(i32 ptr)
{
  return *(i64 *)(mem + fix_ptr(ptr));
}

i64 load_i64_i64_s(i32 ptr)
{
  return *(i64 *)(mem + fix_ptr(ptr));
}

f32 load_f32_f32(i32 ptr)
{
  return *(f32 *)(mem + fix_ptr(ptr));
}

f64 load_f64_f64(i32 ptr)
{
  return *(f64 *)(mem + fix_ptr(ptr));
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
  return *(char *)(mem + fix_ptr(ptr)) = value;
}

i32 store_i32_i16(i32 ptr, i32 value)
{
  return *(short *)(mem + fix_ptr(ptr)) = value;
}

i32 store_i32_i32(i32 ptr, i32 value)
{
  return *(i32 *)(mem + fix_ptr(ptr)) = value;
}

i64 store_i64_i64(i32 ptr, i64 value)
{
  return *(i64 *)(mem + fix_ptr(ptr)) = value;
}

f64 store_f64_f64(i32 ptr, f64 value)
{
  return *(f64 *)(mem + fix_ptr(ptr)) = value;
}

f32 store_f32_f32(i32 ptr, f32 value)
{
  return *(f32 *)(mem + fix_ptr(ptr)) = value;
}

i32 i32_add(i32 a, i32 b) { return a + b; }
i32 i32_sub(i32 a, i32 b) { return a - b; }
i32 i32_and(i32 a, i32 b) { return a & b; }
i32 i32_xor(i32 a, i32 b) { return a ^ b; }
i32 i32_or (i32 a, i32 b) { return a | b; }
i32 i32_mul(i32 a, i32 b) { return a * b; }

i64 i64_add(i64 a, i64 b) { return a + b; }
i64 i64_sub(i64 a, i64 b) { return a - b; }
i64 i64_and(i64 a, i64 b) { return a & b; }
i64 i64_xor(i64 a, i64 b) { return a ^ b; }
i64 i64_or (i64 a, i64 b) { return a | b; }
i64 i64_mul(i64 a, i64 b) { return a * b; }

/* XXX negative */
i64 i64_div_s(i64 a, i64 b) { return a / b; }
i64 i64_div_u(i64 a, i64 b) { return (unsigned long)a/(unsigned long)b; }
i64 i64_rem_s(i64 a, i64 b) { return a % b; }
i64 i64_rem_u(i64 a, i64 b) { return (unsigned long)a%(unsigned long)b; }

/* XXX negative */
i32 i32_div_s(i32 a, i32 b) { return a / b; }
i32 i32_div_u(i32 a, i32 b) { return (unsigned)a/(unsigned)b; }
i32 i32_rem_s(i32 a, i32 b) { return a % b; }
i32 i32_rem_u(i32 a, i32 b) { return (unsigned)a%(unsigned)b; }

f64 f64_add(f64 a, f64 b) { return a + b; }
f64 f64_sub(f64 a, f64 b) { return a - b; }
f64 f64_mul(f64 a, f64 b) { return a * b; }
f64 f64_div(f64 a, f64 b) { return a / b; }

/* XXX NaN */
f64 f64_min(f64 a, f64 b) { return a < b ? a : b; }
f64 f64_max(f64 a, f64 b) { return a > b ? a : b; }
f64 f64_abs(f64 a) { return f64_max(a, -a); }
f64 f64_neg(f64 a) { return -a; }

f64 f64_sqrt(f64 a) { return sqrt(a); }

f32 f32_add(f32 a, f32 b) { return a + b; }
f32 f32_sub(f32 a, f32 b) { return a - b; }
f32 f32_mul(f32 a, f32 b) { return a * b; }
f32 f32_div(f32 a, f32 b) { return a / b; }

/* XXX NaN */
f32 f32_min(f32 a, f32 b) { return a < b ? a : b; }
f32 f32_max(f32 a, f32 b) { return a > b ? a : b; }
f32 f32_abs(f32 a) { return f32_max(a, -a); }
f32 f32_neg(f32 a) { return -a; }

f32 f32_sqrt(f32 a) { return sqrt(a); }

f64 f64_promote_f32(f32 a) { return a; }
f32 f32_demote_f64(f64 a) { return a; }

i32 i32_trunc_s_f32(f32 a) { return a; }
i32 i32_trunc_s_f64(f64 a) { return a; }
i32 i32_trunc_u_f32(f32 a) { return (unsigned)a; }
i32 i32_trunc_u_f64(f64 a) { return (unsigned)a; }
i64 i64_trunc_s_f32(f32 a) { return a; }
i64 i64_trunc_s_f64(f64 a) { return a; }
i64 i64_trunc_u_f32(f32 a) { return (unsigned long)a; }
i64 i64_trunc_u_f64(f64 a) { return (unsigned long)a; }

i64 i64_extend_s(i32 a) { return a; }
i64 i64_extend_u(i32 a) { return (unsigned)a; }

f32 f32_convert_s_i32(i32 a) { return a; }
f32 f32_convert_u_i32(i32 a) { return (unsigned)a; }
f32 f32_convert_s_i64(i64 a) { return a; }
f32 f32_convert_u_i64(i64 a) { return (unsigned long)a; }
f64 f64_convert_s_i32(i32 a) { return a; }
f64 f64_convert_u_i32(i32 a) { return (unsigned)a; }
f64 f64_convert_s_i64(i64 a) { return a; }
f64 f64_convert_u_i64(i64 a) { return (unsigned long)a; }

i32 i32_popcnt(i32 a) { return __builtin_popcount(a); }
i64 i64_popcnt(i64 a) { return __builtin_popcountl(a); }
/* XXX 0 */
i32 i32_clz(i32 a) { return __builtin_clz(a); }
i64 i64_clz(i64 a) { return __builtin_clzl(a); }
i32 i32_ctz(i32 a) { return __builtin_ctz(a); }
i64 i64_ctz(i64 a) { return __builtin_ctzl(a); }

i32 i32_eqz(i32 a) { return !a; }
i32 i64_eqz(i64 a) { return !a; }

f32 f32_trunc(f32 a) { return truncf(a); }
f64 f64_trunc(f64 a) { return trunc(a); }

f32 f32_ceil(f32 a) { return ceilf(a); }
f64 f64_ceil(f64 a) { return ceil(a); }

f32 f32_floor(f32 a) { return floorf(a); }
f64 f64_floor(f64 a) { return floor(a); }

f32 f32_nearest(f32 a) { return nearbyintf(a); }
f64 f64_nearest(f64 a) { return nearbyint(a); }

f32 f32_copysign(f32 a, f32 b) { return copysignf(a, b); }
f64 f64_copysign(f64 a, f64 b) { return copysign(a, b); }
