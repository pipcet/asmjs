TMP1=$(mktemp)
asmjs-virtual-asmjs-ld -T multifile.lds $1 $2 -o $TMP1
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end -N __init_array_start -N __init_array_end -N __terminator $TMP1 $1
