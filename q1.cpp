#include <stdio.h>
#include <string.h>

void caesarCipher(char* plaintext, int k) {
    int i;
    char ch;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];
        
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + k;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            plaintext[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + k;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            plaintext[i] = ch;
        }
    }
}

int main() {
    char plaintext[100];
    int k;

    printf("Enter a string: ");
    gets(plaintext);
    printf("Enter shift value: ");
    scanf("%d", &k);

    caesarCipher(plaintext, k);

    printf("Encrypted text: %s\n", plaintext);
    return 0;
}
