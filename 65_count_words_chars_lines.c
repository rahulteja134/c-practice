#include <stdio.h>
#include <ctype.h>

int main(void){
    int c;
    size_t words=0, lines=0, chars=0;
    int in_word = 0;
    while ((c = getchar()) != EOF){
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) in_word = 0;
        else if (!in_word){ in_word=1; words++; }
    }
    printf("Words: %zu Lines: %zu Chars: %zu\n", words, lines, chars);
    return 0;
}
