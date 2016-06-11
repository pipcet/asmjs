#!/bin/bash
TMP1=$(mktemp);
TMP2=$(mktemp);
TMP3=$(mktemp);
TMP4=$(mktemp);
TMP5=$(mktemp);
TMP6=$(mktemp);
TMP7=$(mktemp);
asmjs-virtual-asmjs-objcopy $2 $TMP1 -N __header_start --add-symbol __header_start=.next_header:0
asmjs-virtual-asmjs-ld -T linked-list.lds $1 $TMP1 -o $TMP2
asmjs-virtual-asmjs-ld -T linked-list-1.lds $TMP2 -o $TMP3
cp $TMP3 $1
