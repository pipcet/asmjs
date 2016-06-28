int main(void)
{
  asm volatile("get_local $fp\n\t"
               "i64.const 1\n\t"
               "i64.or\n\t"
               "set_local $rp\n\t"
               "br __wasm_depth - __wasm_blocks");

  return 0;
}
