#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char* plaintext, const char* key) {
    int i;
    char ch;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];
        
        if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = key[ch - 'a'] + 32;
        } else if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = key[ch - 'A'];
        }
    }
}

int main() {
    char plaintext[100];
    const char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Enter a string: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    monoalphabeticCipher(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);
    return 0;
}
