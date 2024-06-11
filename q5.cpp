#include <stdio.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void affineCaesarCipher(char* plaintext, int a, int b) {
    int i;
    char ch;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];
        
        if (ch >= 'a' && ch <= 'z') {
            ch = ((a * (ch - 'a') + b) % 26) + 'a';
            plaintext[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((a * (ch - 'A') + b) % 26) + 'A';
            plaintext[i] = ch;
        }
    }
}
int main() {
    char plaintext[100];
    int a, b;
    printf("Enter a string: ");
    gets(plaintext);
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1) {
        printf("Invalid values for a and b.\n");
    } else {
        affineCaesarCipher(plaintext, a, b);
        printf("Encrypted text: %s\n", plaintext);
    }  
    return 0;
}
