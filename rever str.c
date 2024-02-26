#include<stdio.h>
#include<string.h>

void cpy(char[], char[], int, int);

int main() {
    char a[50], b[50] = "";
    printf("enter");
    scanf("%s",&a);
    cpy(a, b, strlen(a)-1, 0);
    return 0;
}

void cpy(char a[], char b[], int c, int i) {
    if (c>=0 && a[c] != '\0') {
        b[i] = a[c];
        c--;
        cpy(a, b, c, i + 1);
    } else {
        b[i] = '\0';
        printf("%s",b);


    }
}
