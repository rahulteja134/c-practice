#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%u", &n) != 1) return 1;
    if (n == 0) { printf("0\n"); return 0; }
    char buf[64]; int idx = 0;
    while (n > 0) {
        buf[idx++] = '0' + (n & 1);
        n >>= 1;
    }
    while (--idx >= 0) putchar(buf[idx]);
    putchar('\n');
    return 0;
}
