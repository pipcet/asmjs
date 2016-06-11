TMP1=$(mktemp)
asmjs-virtual-asmjs-objcopy --prefix-sections .prev -N __data_start -N __data_end -N __init_array_start -N __init_array_end -N __terminator $1 $TMP1 && mv $TMP1 $1
