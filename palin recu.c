#include<stdio.h>
#include<string.h>

void pali(char[], char[], int, int);

int main() {
    char a[50] = "hello", b[50] = "";
    pali(a, b, strlen(a) - 1, 0);
    return 0;
}

void pali(char a[], char b[], int c, int i) {
    if (c >= 0 && a[c] != '\0') {
        b[i] = a[c];
        c--;
        pali(a, b, c, i + 1);
    } else {
        b[i] = '\0'; // Add null terminator to make b a valid string
        if (strcmp(a, b) == 0) {
            printf("Palindrome\n");
        } else {
            printf("Not a Palindrome\n");
        }
    }
}
