# in glibc/sysdeps/wasm32
find -type f | while read; do diff -uN "../generic/$REPLY" "$REPLY" && echo "YYY $REPLY"; done
