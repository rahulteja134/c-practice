#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof *L);
    int *R = malloc(n2 * sizeof *R);
    for (int i=0;i<n1;i++) L[i]=a[l+i];
    for (int j=0;j<n2;j++) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while (i<n1 && j<n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i<n1) a[k++] = L[i++];
    while (j<n2) a[k++] = R[j++];
    free(L); free(R);
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int *a = malloc(n * sizeof *a);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    merge_sort(a,0,n-1);
    for (int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
