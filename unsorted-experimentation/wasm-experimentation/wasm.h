typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;

void *mem;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ai extern inline __attribute__((always_inline))

static i64 _1562(i64, i64, i64, i64, i64, i64);

ai i32 i64_eq(i64 a, i64 b) { return a == b; }
ai i32 i64_ne(i64 a, i64 b) { return a != b; }

ai i32 f64_eq(f64 a, f64 b) { return a == b; }
ai i32 f64_ne(f64 a, f64 b) { return a != b; }
ai i32 f64_lt(f64 a, f64 b) { return a <  b; }
ai i32 f64_gt(f64 a, f64 b) { return a >  b; }
ai i32 f64_le(f64 a, f64 b) { return a <= b; }
ai i32 f64_ge(f64 a, f64 b) { return a >= b; }

ai i32 f32_eq(f32 a, f32 b) { return a == b; }
ai i32 f32_ne(f32 a, f32 b) { return a != b; }
ai i32 f32_lt(f32 a, f32 b) { return a <  b; }
ai i32 f32_gt(f32 a, f32 b) { return a >  b; }
ai i32 f32_le(f32 a, f32 b) { return a <= b; }
ai i32 f32_ge(f32 a, f32 b) { return a >= b; }

ai i32 i64_lt_u(i64 a, i64 b) { return (unsigned long)a <  (unsigned long)b; }
ai i32 i64_gt_u(i64 a, i64 b) { return (unsigned long)a >  (unsigned long)b; }
ai i32 i64_le_u(i64 a, i64 b) { return (unsigned long)a <= (unsigned long)b; }
ai i32 i64_ge_u(i64 a, i64 b) { return (unsigned long)a >= (unsigned long)b; }

ai i32 i64_lt_s(i64 a, i64 b) { return a <  b; }
ai i32 i64_gt_s(i64 a, i64 b) { return a >  b; }
ai i32 i64_le_s(i64 a, i64 b) { return a <= b; }
ai i32 i64_ge_s(i64 a, i64 b) { return a >= b; }

ai i32 i32_eq(i32 a, i32 b) { return a == b; }
ai i32 i32_ne(i32 a, i32 b) { return a != b; }

ai i32 i32_lt_u(i32 a, i32 b) { return (unsigned)a <  (unsigned)b; }
ai i32 i32_gt_u(i32 a, i32 b) { return (unsigned)a >  (unsigned)b; }
ai i32 i32_le_u(i32 a, i32 b) { return (unsigned)a <= (unsigned)b; }
ai i32 i32_ge_u(i32 a, i32 b) { return (unsigned)a >= (unsigned)b; }

ai i32 i32_lt_s(i32 a, i32 b) { return a <  b; }
ai i32 i32_gt_s(i32 a, i32 b) { return a >  b; }
ai i32 i32_le_s(i32 a, i32 b) { return a <= b; }
ai i32 i32_ge_s(i32 a, i32 b) { return a >= b; }

ai i64 i64_shl(i64 a, i64 b) { return a << (b&63); }
ai i64 i64_shr_s(i64 a, i64 b) { return a >> (b&63); }
ai i64 i64_shr_u(i64 a, i64 b) { return (unsigned long)a >> (b&63); }
ai i64 i64_rotr(i64 a, i64 b) { return a>>(b&63) | a<<(32-(b&63)); }
ai i64 i64_rotl(i64 a, i64 b) { return a<<(b&63) | a>>(32-(b&63)); }

ai i32 i32_shl(i32 a, i32 b) { return a << (b&31); }
ai i32 i32_shr_s(i32 a, i32 b) { return a >> (b&31); }
ai i32 i32_shr_u(i32 a, i32 b) { return (unsigned long)a >> (b&31); }
ai i32 i32_rotr(i32 a, i32 b) { return a>>(b&31) | a<<(32-(b&31)); }
ai i32 i32_rotl(i32 a, i32 b) { return a<<(b&31) | a>>(32-(b&31)); }

ai i64 i64_reinterpret_f64(f64 x)
{
  return *(i64 *)(&x);
}

ai f64 f64_reinterpret_i64(i64 x)
{
  return *(f64 *)(&x);
}

ai i32 i32_reinterpret_f32(f32 x)
{
  return *(i32 *)(&x);
}

ai f32 f32_reinterpret_i32(i32 x)
{
  return *(f32 *)(&x);
}

ai i32 fix_ptr(i32 ptr)
{
  return ptr & 0xffffffff;
}

ai i32 load_i32_i8_u(i32 ptr)
{
  return *(unsigned char *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i8_s(i32 ptr)
{
  return *(signed char *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i16_u(i32 ptr)
{
  return *(unsigned short *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i16_s(i32 ptr)
{
  return *(short *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i32_u(i32 ptr)
{
  return *(i32 *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i32_s(i32 ptr)
{
  return *(i32 *)(mem + fix_ptr(ptr));
}

ai i64 load_i64_i64_u(i32 ptr)
{
  return *(i64 *)(mem + fix_ptr(ptr));
}

ai i64 load_i64_i64_s(i32 ptr)
{
  return *(i64 *)(mem + fix_ptr(ptr));
}

ai f32 load_f32_f32(i32 ptr)
{
  return *(f32 *)(mem + fix_ptr(ptr));
}

ai f64 load_f64_f64(i32 ptr)
{
  return *(f64 *)(mem + fix_ptr(ptr));
}

ai i32 i32_wrap_i64(i64 x)
{
  return (i32)x;
}

ai i64 i64_extend_s_i32(i32 x)
{
  return (i64)x;
}

ai i64 i64_extend_u_i32(i32 x)
{
  return (i64)(unsigned int)x;
}

ai i32 store_i32_i8(i32 ptr, i32 value)
{
  return *(char *)(mem + fix_ptr(ptr)) = value;
}

ai i32 store_i32_i16(i32 ptr, i32 value)
{
  return *(short *)(mem + fix_ptr(ptr)) = value;
}

ai i32 store_i32_i32(i32 ptr, i32 value)
{
  return *(i32 *)(mem + fix_ptr(ptr)) = value;
}

ai i64 store_i64_i64(i32 ptr, i64 value)
{
  return *(i64 *)(mem + fix_ptr(ptr)) = value;
}

ai f64 store_f64_f64(i32 ptr, f64 value)
{
  return *(f64 *)(mem + fix_ptr(ptr)) = value;
}

ai f32 store_f32_f32(i32 ptr, f32 value)
{
  return *(f32 *)(mem + fix_ptr(ptr)) = value;
}

ai i32 i32_add(i32 a, i32 b) { return a + b; }
ai i32 i32_sub(i32 a, i32 b) { return a - b; }
ai i32 i32_and(i32 a, i32 b) { return a & b; }
ai i32 i32_xor(i32 a, i32 b) { return a ^ b; }
ai i32 i32_or (i32 a, i32 b) { return a | b; }
ai i32 i32_mul(i32 a, i32 b) { return a * b; }

ai i64 i64_add(i64 a, i64 b) { return a + b; }
ai i64 i64_sub(i64 a, i64 b) { return a - b; }
ai i64 i64_and(i64 a, i64 b) { return a & b; }
ai i64 i64_xor(i64 a, i64 b) { return a ^ b; }
ai i64 i64_or (i64 a, i64 b) { return a | b; }
ai i64 i64_mul(i64 a, i64 b) { return a * b; }

/* XXX negative */
ai i64 i64_div_s(i64 a, i64 b) { return a / b; }
ai i64 i64_div_u(i64 a, i64 b) { return (unsigned long)a/(unsigned long)b; }
ai i64 i64_rem_s(i64 a, i64 b) { return a % b; }
ai i64 i64_rem_u(i64 a, i64 b) { return (unsigned long)a%(unsigned long)b; }

/* XXX negative */
ai i32 i32_div_s(i32 a, i32 b) { return a / b; }
ai i32 i32_div_u(i32 a, i32 b) { return (unsigned)a/(unsigned)b; }
ai i32 i32_rem_s(i32 a, i32 b) { return a % b; }
ai i32 i32_rem_u(i32 a, i32 b) { return (unsigned)a%(unsigned)b; }

ai f64 f64_add(f64 a, f64 b) { return a + b; }
ai f64 f64_sub(f64 a, f64 b) { return a - b; }
ai f64 f64_mul(f64 a, f64 b) { return a * b; }
ai f64 f64_div(f64 a, f64 b) { return a / b; }

/* XXX NaN */
ai f64 f64_min(f64 a, f64 b) { return a < b ? a : b; }
ai f64 f64_max(f64 a, f64 b) { return a > b ? a : b; }
ai f64 f64_abs(f64 a) { return f64_max(a, -a); }
ai f64 f64_neg(f64 a) { return -a; }

ai f64 f64_sqrt(f64 a) { return sqrt(a); }

ai f32 f32_add(f32 a, f32 b) { return a + b; }
ai f32 f32_sub(f32 a, f32 b) { return a - b; }
ai f32 f32_mul(f32 a, f32 b) { return a * b; }
ai f32 f32_div(f32 a, f32 b) { return a / b; }

/* XXX NaN */
ai f32 f32_min(f32 a, f32 b) { return a < b ? a : b; }
ai f32 f32_max(f32 a, f32 b) { return a > b ? a : b; }
ai f32 f32_abs(f32 a) { return f32_max(a, -a); }
ai f32 f32_neg(f32 a) { return -a; }

ai f32 f32_sqrt(f32 a) { return sqrt(a); }

ai f64 f64_promote_f32(f32 a) { return a; }
ai f32 f32_demote_f64(f64 a) { return a; }

ai i32 i32_trunc_s_f32(f32 a) { return a; }
ai i32 i32_trunc_s_f64(f64 a) { return a; }
ai i32 i32_trunc_u_f32(f32 a) { return (unsigned)a; }
ai i32 i32_trunc_u_f64(f64 a) { return (unsigned)a; }
ai i64 i64_trunc_s_f32(f32 a) { return a; }
ai i64 i64_trunc_s_f64(f64 a) { return a; }
ai i64 i64_trunc_u_f32(f32 a) { return (unsigned long)a; }
ai i64 i64_trunc_u_f64(f64 a) { return (unsigned long)a; }

ai i64 i64_extend_s(i32 a) { return a; }
ai i64 i64_extend_u(i32 a) { return (unsigned)a; }

ai f32 f32_convert_s_i32(i32 a) { return a; }
ai f32 f32_convert_u_i32(i32 a) { return (unsigned)a; }
ai f32 f32_convert_s_i64(i64 a) { return a; }
ai f32 f32_convert_u_i64(i64 a) { return (unsigned long)a; }
ai f64 f64_convert_s_i32(i32 a) { return a; }
ai f64 f64_convert_u_i32(i32 a) { return (unsigned)a; }
ai f64 f64_convert_s_i64(i64 a) { return a; }
ai f64 f64_convert_u_i64(i64 a) { return (unsigned long)a; }

ai i32 i32_popcnt(i32 a) { return __builtin_popcount(a); }
ai i64 i64_popcnt(i64 a) { return __builtin_popcountl(a); }
/* XXX 0 */
ai i32 i32_clz(i32 a) { return __builtin_clz(a); }
ai i64 i64_clz(i64 a) { return __builtin_clzl(a); }
ai i32 i32_ctz(i32 a) { return __builtin_ctz(a); }
ai i64 i64_ctz(i64 a) { return __builtin_ctzl(a); }

ai i32 i32_eqz(i32 a) { return !a; }
ai i32 i64_eqz(i64 a) { return !a; }

ai f32 f32_trunc(f32 a) { return truncf(a); }
ai f64 f64_trunc(f64 a) { return trunc(a); }

ai f32 f32_ceil(f32 a) { return ceilf(a); }
ai f64 f64_ceil(f64 a) { return ceil(a); }

ai f32 f32_floor(f32 a) { return floorf(a); }
ai f64 f64_floor(f64 a) { return floor(a); }

ai f32 f32_nearest(f32 a) { return nearbyintf(a); }
ai f64 f64_nearest(f64 a) { return nearbyint(a); }

ai f32 f32_copysign(f32 a, f32 b) { return copysignf(a, b); }
ai f64 f64_copysign(f64 a, f64 b) { return copysign(a, b); }

long wasm_start[32] = {
     0, 0,
     1, 0,
     2, 0,
     3, 0,
     -1, 0,
     -1, 0,
     -1, 0,
     -1, 0
};

void* instance;
void* exports;
void* heap;
void* jscontext;

extern void start(void);
int main(void)
{
  /* instance = (void*)wasm_start[11]; */
  /* exports = (void*)wasm_start[9]; */
  /* heap = (void*)wasm_start[13]; */
  /* jscontext = (void*)wasm_start[15]; */

  mem = malloc(128 * 1024 * 1024);

  FILE *f;
  f = fopen("wasm.data", "r");

  if (!f)
    return 1;

  void *p = mem + 0x4040;
  size_t res;
  while (res = fread(p, 1, 4096, f))
    p += res;

  fclose(f);

  long pc = 0x661LL<<32LL;
  long sp = 2 * 1024 * 1024;
  long rpc = 0;
  long rp;

  while (pc != 0xffffffffL) {
    rp = _1562(pc, sp, 0, 0, rpc, pc & 0xffffffff00000000UL);
    sp = rp;

    if (sp & 3) {
      sp &= -4L;
      pc = *(long *)(mem + sp + 16);
      pc |= 0xffffffffUL;
      sp += 16;
    } else {
      sp = *(long *)(mem + rp);
      pc = *(long *)(mem + sp + 16);
      pc |= 0xffffffffUL;
      sp += 16;
    }
  }

  return 0;
}

void extcall(void)
{
  long (*cbtn)(void *, void *, unsigned long, long, long, long, long);
  cbtn = exports;

  cbtn(jscontext, instance, 0, 0, 0, 0, 0);
}

i64 import_0(i64 x, i64 y, i64 z, i64 a)
{
  fprintf (stderr, "import_0\n");
  return 0;
}
i64 import_1(i64 x, i64 y, i64 z)
{
  fprintf (stderr, "import_1\n");
  return 0;
}
i64 import_3(i64 x)
{
  fprintf (stderr, "import_3\n");
  return 0;
}
i64 import$0(i64 x, i64 y, i64 z, i64 a)
{
  char *name = mem + y;
  fprintf (stderr, "import$0 %s\n", name);
  *(long *)(mem + 4096) = -1;

  if (strcmp(name, "write") == 0) {
    long count = *(long *)(mem + a + 0x20);
    long pointer = *(long *)(mem + a + 0x18);
    fwrite (mem + pointer, 1, count, stderr);
    *(long *)(mem + 4096) = count;
  } else if (strcmp(name, "exit") == 0) {
    long code = *(long *)(mem + a + 0x10);
    exit(code);
  }
  return 0;
}
i64 import$1(i64 fp, i64 sp, i64 handler)
{
  fprintf (stderr, "import$1 %lx %lx %lx\n", fp, sp, handler);
  *(long *)(mem + 4104) = *(long *)(mem + fp + 48);
  *(long *)(mem + 4112) = *(long *)(mem + fp + 56);
  *(long *)(mem + 4120) = *(long *)(mem + fp + 64);
  *(long *)(mem + 4128) = *(long *)(mem + fp + 72);

  fp = *(long *)(mem + fp);
  fp = *(long *)(mem + fp);

  *(long *)(mem + fp + 8) = handler & 0xffffffff00000000UL;
  *(long *)(mem + fp + 16) = handler;

  return fp|3;
}
i64 import$3(i64 x)
{
  //fprintf (stderr, "import$3 %lx\n", x);
  return 0;
}
#if 0
/* i64 import_0(i64 x) */
/* { */
/*   sprintf((char *)mem + 12288 + 2048, "log"); */
/*   store_i64_i64(12288, 2); */
/*   store_i64_i64(12296, (int64_t)12288 + 2048); */
/*   store_i64_i64(12304, x); */
/*   extcall(); */
/*   return load_i64_i64_u(12288); */
/* } */

i64 import_2(i64 dpc, i64 sp, i64 r0, i64 r1, i64 rpc, i64 pc0);

i64 import_0(i64 a0, i64 a1, i64 a2, i64 a3)
{
  sprintf((char *)mem + 12288 + 2048, "extcall");
  store_i64_i64(12288, 5);
  store_i64_i64(12296, (int64_t)12288 + 2048);
  store_i64_i64(12304, a0);
  store_i64_i64(12312, a1);
  store_i64_i64(12320, a2);
  store_i64_i64(12328, a3);
  extcall();
  return load_i64_i64_u(12288);
}

i64 import_1(i64 x, i64 y, i64 z)
{
  fprintf(stderr, "mystery call: %lx\n", x);
}
#endif

i64 (*table[])(i64, i64, i64, i64, i64, i64);
