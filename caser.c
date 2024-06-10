#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char* plaintext, char* key) {
    int i;
    char ch;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];
        
        if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = key[ch - 'a'];
        } else if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = key[ch - 'A'];
        }
    }
}

int main() {
    char plaintext[100];
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Enter a string: ");
    gets(plaintext);

    monoalphabeticCipher(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);
    return 0;
}