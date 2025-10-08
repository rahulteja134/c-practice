#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b){ int t=*a; *a=*b; *b=t; }

int partition(int arr[], int lo, int hi) {
    int pivot = arr[hi], i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if (arr[j] <= pivot) swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i+1], &arr[hi]);
    return i+1;
}

void quicksort(int arr[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(arr, lo, hi);
        quicksort(arr, lo, p-1);
        quicksort(arr, p+1, hi);
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int *a = malloc(n * sizeof *a);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
