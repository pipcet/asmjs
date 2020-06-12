int main(void)
{
  asm volatile("local.get $fp\n\t"
               "i64.const 1\n\t"
               "i64.or\n\t"
               "local.set $rp\n\t"
               "br __wasm_depth - __wasm_blocks");

  return 0;
}
