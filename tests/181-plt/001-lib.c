asm(".text\n\t"
    "createsig FiiiiiiiE\n\t"
    ".globl plus\n\t"
    "defun plus FdddE\n"
    "__wasm_body_blocks_plus:\n\t"
    "local.get 0\n\t"
    "local.get 1\n\t"
    "f64.add\n\t"
    "return\n\t"
    "end\n\t"
    "endefun plus");
