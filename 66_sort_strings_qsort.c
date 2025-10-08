#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){ return strcmp(*(const char * const*)a, *(const char * const*)b); }

int main(void){
    int n; if (scanf("%d", &n) != 1) return 1;
    char **arr = malloc(n * sizeof *arr);
    for (int i=0;i<n;i++){
        arr[i] = malloc(256);
        scanf("%255s", arr[i]);
    }
    qsort(arr, n, sizeof *arr, cmp);
    for (int i=0;i<n;i++) puts(arr[i]);
    for (int i=0;i<n;i++) free(arr[i]);
    free(arr);
    return 0;
}
