#include <stdio.h>
/* Swap two integers without a temp variable using XOR.
   Note: safe when a and b are distinct memory locations. */
int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    printf("After swap: a=%d b=%d\n", a, b);
    return 0;
}
