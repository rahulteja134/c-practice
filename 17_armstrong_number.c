#include <stdio.h>
#include <math.h>
int main() {
    int n, orig, sum = 0, digits = 0, rem;
    printf("Enter number: ");
    scanf("%d", &n);
    orig = n;
    int temp = n;
    while(temp){digits++; temp/=10;}
    temp = n;
    while(temp){
        rem = temp%10;
        sum += pow(rem,digits);
        temp/=10;
    }
    if(sum==orig) printf("Armstrong"); else printf("Not Armstrong");
    return 0;
}