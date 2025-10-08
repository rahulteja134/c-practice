#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    const char *in = "input.txt", *out = "output.txt";
    FILE *f = fopen(in, "r");
    if (!f){ perror("fopen"); return 1; }
    FILE *g = fopen(out, "w");
    if (!g){ perror("fopen"); fclose(f); return 1; }
    char buf[512];
    while (fgets(buf, sizeof buf, f)){
        char *p = buf;
        while ((p = strstr(p, "foo"))){ fwrite(buf, 1, p - buf, g); fprintf(g, "bar"); p += 3; memmove(buf, p, strlen(p)+1); p = buf; }
        fputs(buf, g);
    }
    fclose(f); fclose(g);
    printf("Replaced 'foo' with 'bar' (simple algorithm).\n");
    return 0;
}
