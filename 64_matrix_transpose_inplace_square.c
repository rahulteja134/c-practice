#include <stdio.h>

int main(void){
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int a[n][n];
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++){
        int t = a[i][j]; a[i][j]=a[j][i]; a[j][i]=t;
    }
    for (int i=0;i<n;i++){ for (int j=0;j<n;j++) printf("%d ", a[i][j]); printf("\n"); }
    return 0;
}
