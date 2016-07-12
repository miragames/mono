#! /bin/sh

gcc -c -fPIC -o mono/metadata/aes.o mono/metadata/aes.c
gcc -o AesEditor -fPIC mono/metadata/aes.o mono/metadata/aes_editor.c