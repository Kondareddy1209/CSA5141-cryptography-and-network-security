#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void generate_cipher_alphabet(const char *keyword, char *cipher_alphabet) {
    int used[ALPHABET_SIZE] = {0};
    int i, j = 0;
    for (i = 0; keyword[i]; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher_alphabet[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipher_alphabet[j++] = 'A' + i;
        }
    }
    cipher_alphabet[j] = '\0';
}
void encrypt_message(const char *message, const char *cipher_alphabet, char *encrypted) {
    int i;
    for (i = 0; message[i]; i++) {
        char ch = toupper(message[i]);
        if (isalpha(ch)) {
            encrypted[i] = cipher_alphabet[ch - 'A'];
        } else {
            encrypted[i] = ch;
        }
    }
    encrypted[i] = '\0';
}
int main() {
    char keyword[256];
    char message[256];
    char cipher_alphabet[ALPHABET_SIZE + 1];
    char encrypted[256];
    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    size_t len = strlen(keyword);
    if (len > 0 && keyword[len - 1] == '\n') {
        keyword[len - 1] = '\0';
}
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }
    generate_cipher_alphabet(keyword, cipher_alphabet);
    encrypt_message(message, cipher_alphabet, encrypted);

    printf("Cipher Alphabet: %s\n", cipher_alphabet);
    printf("Encrypted Message: %s\n", encrypted);
    return 0;
}
