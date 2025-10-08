#include <stdio.h>
#include <string.h>

int main(void) {
    char s[256];
    printf("Enter a string: ");
    if (!fgets(s, sizeof(s), stdin)) return 1;
    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[--n] = '\0';

    int i = 0, j = (int)n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            printf("Not a palindrome\n");
            return 0;
        }
        i++; j--;
    }
    printf("Palindrome\n");
    return 0;
}
