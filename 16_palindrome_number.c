#include <stdio.h>
int main() {
    int n, orig, rev = 0, rem;
    printf("Enter number: ");
    scanf("%d", &n);
    orig = n;
    while(n!=0){
        rem = n%10;
        rev = rev*10 + rem;
        n/=10;
    }
    if(orig==rev) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}