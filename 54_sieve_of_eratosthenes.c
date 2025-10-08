#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int n;
    printf("Enter n (>=2): ");
    if (scanf("%d", &n) != 1 || n < 2) return 1;
    bool *is_prime = calloc(n+1, sizeof(bool));
    for (int i = 2; i <= n; ++i) is_prime[i] = true;
    for (int p = 2; p*p <= n; ++p) {
        if (is_prime[p]) {
            for (int k = p*p; k <= n; k += p) is_prime[k] = false;
        }
    }
    printf("Primes <= %d:\n", n);
    for (int i = 2; i <= n; ++i) if (is_prime[i]) printf("%d ", i);
    printf("\n");
    free(is_prime);
    return 0;
}
