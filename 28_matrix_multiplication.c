#include <stdio.h>
int main() {
    int r1,c1,r2,c2;
    printf("Enter rows and cols of 1st matrix: "); scanf("%d %d",&r1,&c1);
    printf("Enter rows and cols of 2nd matrix: "); scanf("%d %d",&r2,&c2);
    if(c1!=r2){printf("Cannot multiply"); return 0;}
    int a[r1][c1], b[r2][c2], c[r1][c2];
    printf("Enter 1st matrix: "); for(int i=0;i<r1;i++) for(int j=0;j<c1;j++) scanf("%d",&a[i][j]);
    printf("Enter 2nd matrix: "); for(int i=0;i<r2;i++) for(int j=0;j<c2;j++) scanf("%d",&b[i][j]);
    for(int i=0;i<r1;i++) for(int j=0;j<c2;j++){c[i][j]=0; for(int k=0;k<c1;k++) c[i][j]+=a[i][k]*b[k][j];}
    printf("Result Matrix:\n"); for(int i=0;i<r1;i++){for(int j=0;j<c2;j++) printf("%d ",c[i][j]); printf("\n");}
    return 0;
}