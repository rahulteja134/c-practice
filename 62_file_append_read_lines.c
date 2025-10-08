#include <stdio.h>
#include <stdlib.h>

int main(void){
    const char *fname = "lines.txt";
    FILE *f = fopen(fname, "a");
    if (!f) { perror("fopen"); return 1; }
    fprintf(f, "New line appended.\n");
    fclose(f);

    f = fopen(fname, "r");
    if (!f) { perror("fopen"); return 1; }
    char buf[256];
    while (fgets(buf, sizeof(buf), f)) fputs(buf, stdout);
    fclose(f);
    return 0;
}
