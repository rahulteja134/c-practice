#include <stdio.h>
#include <time.h>

int main(void){
    time_t t = time(NULL);
    if (t == (time_t)-1) { perror("time"); return 1; }
    printf("Unix timestamp: %lld\n", (long long)t);
    struct tm *tm = localtime(&t);
    char buf[128];
    strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S %z", tm);
    printf("Local time: %s\n", buf);
    return 0;
}
