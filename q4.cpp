#include <stdio.h>
#include <string.h>
void vigenereCipher(char* plaintext, char* key) {
    int i, j;
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    char newKey[textLen], encryptedText[textLen];
    for(i = 0, j = 0; i < textLen; ++i, ++j) {
        if(j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    for(i = 0; i < textLen; ++i) {
        encryptedText[i] = ((plaintext[i] + newKey[i]) % 26) + 'A';
    }
    encryptedText[i] = '\0';

    printf("Encrypted Text: %s\n", encryptedText);
}
int main() {
    char plaintext[100], key[100];

    printf("Enter plaintext: ");
    gets(plaintext);
    printf("Enter key: ");
    gets(key);
    vigenereCipher(plaintext, key);
    return 0;
}
