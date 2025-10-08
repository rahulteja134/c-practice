#include <stdio.h>

int bsearch_rec(const int a[], int lo, int hi, int key){
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) return bsearch_rec(a, mid+1, hi, key);
    return bsearch_rec(a, lo, mid-1, key);
}

int main(void){
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int a[n];
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int key; scanf("%d", &key);
    int idx = bsearch_rec(a, 0, n-1, key);
    if (idx >= 0) printf("Found at index %d\n", idx); else printf("Not found\n");
    return 0;
}
