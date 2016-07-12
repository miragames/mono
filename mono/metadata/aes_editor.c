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
    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    while (1)
    {
        bytes_read = fread(indata, 1, 16, inf);
        AES128_CBC_encrypt_buffer(outdata, indata, 16, key, iv);
        bytes_written = fwrite(outdata, 1, bytes_read, ouf);
        if (bytes_read < 16)
            break;
    }
    fclose(inf);
    fclose(ouf);
}

int main(int argc, char *argv[]) {
    if (argc < 3)
        return -1;
    encrypt_dll_by_aes(argv[1], argv[2]);
}