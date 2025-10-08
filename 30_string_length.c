#include <stdio.h>
int main() {
    char str[100];
    int len=0;
    printf("Enter string: ");
    gets(str);
    for(int i=0;str[i]!='\0';i++) len++;
    printf("Length = %d", len);
    return 0;
}