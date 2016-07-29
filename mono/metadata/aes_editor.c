#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CBC 1
#define ECB 1

void encrypt_dll_by_aes(char const* source, char const* dest) {
    FILE *inf = fopen(source, "rb");
    FILE *ouf = fopen(dest, "wb");
    size_t bytes_read, bytes_written;
    unsigned char indata[16];
    unsigned char outdata[16];
    uint8_t key[] = { 0xf3, 0xbc, 0x64, 0x7d, 0x12, 0x05, 0xbf, 0x1a, 0x00, 0x6e, 0x28, 0xfd, 0x08, 0x1f, 0xfa, 0xbb };
    uint8_t iv[]  = { 0xf4, 0xc2, 0x04, 0x87, 0xe0, 0xd2, 0x18, 0x8b, 0xfa, 0x1d, 0x7d, 0x82, 0x4d, 0xa5, 0x70, 0x95 };
    while (1)
    {
        bytes_read = fread(indata, 1, 16, inf);
        if (bytes_read < 16)
        {
            bytes_written = fwrite(indata, 1, bytes_read, ouf);
            break;
        }
        else
        {
            func_fe2bd83b3(outdata, indata, 16, key, iv);
            bytes_written = fwrite(outdata, 1, bytes_read, ouf);
        }
    }
    fclose(inf);
    fclose(ouf);
}

int main(int argc, char *argv[]) {
    if (argc < 3)
        return -1;
    encrypt_dll_by_aes(argv[1], argv[2]);
}