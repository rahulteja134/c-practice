#include <stdio.h>
#include <stdlib.h>

int main(void){
    const char *src = "image.bin", *dst = "image_copy.bin";
    FILE *fs = fopen(src, "rb");
    if (!fs){ perror("fopen src"); return 1; }
    FILE *fd = fopen(dst, "wb");
    if (!fd){ perror("fopen dst"); fclose(fs); return 1; }
    unsigned char buf[4096]; size_t n;
    while ((n = fread(buf, 1, sizeof buf, fs)) > 0) fwrite(buf, 1, n, fd);
    fclose(fs); fclose(fd);
    printf("Binary file copied (if %s existed).\n", src);
    return 0;
}
