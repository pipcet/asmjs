typedef unsigned char u8;

struct wasm_fragment {
  size_t insize;
  size_t outsize;
  u8 *in;
  u8 *out;
};

void mputchar(int c)
{
  
}

unsigned long read_uleb128(void)
{
  int c = getchar();
  long value = 0;
  long shift = 0;
  if (c == EOF)
    exit(1);

  value += (c & 0x7f) << shift;
  shift += 7;

  if (!(c & 0x80))
    return value;
}

void write_uleb128(unsigned long value)
{
  do {
    u8 c = value & 0x7f;
    value >>= 7;
    putchar(c | (value?0x80:0));
  } while(value);
}

char *read_string(void)
{
  unsigned long len = read_uleb128();
  char *ret = xmalloc(len+1);

  fread(ret, 1, len, stdin);

  ret[len] = 0;

  return ret;
}

void write_string(char *string)
{
  write_uleb128(strlen(string));
  fwrite(string, 1, strlen(string), stdout);
}

char *read_bytes(unsigned long len)
{
  char *ret = xmalloc(len);

  fread(ret, 1, len, stdin);

  return ret;
}

void write_bytes(char *bytes, unsigned long len)
{
  fwrite(bytes, 1, len, stdout);

  free(bytes);
}

void section_simple(char *name)
{
  unsigned long len = read_uleb128();

  if (len) {
    write_string(name);
    write_bytes(read_bytes(len), len);
  }
}

void ast(void)
{
}

void function_body(void)
{
  unsigned long len = read_uleb128();

  if (len) {
    write_uleb128_delta(len);
    write_bytes(read_bytes(len), len);
    pop_delta(len);
  }
}

void section_code(char *name)
{
  unsigned long count = read_uleb128();
  if (count) {
    write_string(name);
    write_uleb128(count);
    while (count--)
      function_body();
  }
}

void section(void)
{
  char *name = read_string();

  if (strcmp(name, "type") == 0) {
    section_simple(name);
  } else if (strcmp(name, "import") == 0) {
    section_simple(name);
  } else if (strcmp(name, "function") == 0) {
    section_simple(name);
  } else if (strcmp(name, "memory") == 0) {
    section_simple("memory");
  } else if (strcmp(name, "export") == 0) {
    section_simple("export");
  } else if (strcmp(name, "code") == 0) {
    section_simple("code");
  } else if (strcmp(name, "start") == 0) {
    section_simple("start");
  } else if (strcmp(name, "data") == 0) {
    section_simple("data");
  }
}

int main(void)
{

}
