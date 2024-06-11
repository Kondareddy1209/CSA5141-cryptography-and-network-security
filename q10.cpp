#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
char matrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};
void preprocess_message(char *message, char *processed) {
    int i, j = 0;
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            processed[j++] = toupper(message[i]);
        }
    }
    processed[j] = '\0';
}
void find_position(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J') ch = 'I';
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encrypt_pair(char a, char b, char *result) {
    int row1, col1, row2, col2;
    find_position(a, &row1, &col1);
    find_position(b, &row2, &col2);
    if (row1 == row2) {
        result[0] = matrix[row1][(col1 + 1) % SIZE];
        result[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + 1) % SIZE][col1];
        result[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}
void playfair_encrypt(char *message, char *encrypted) {
    char processed[256];
    preprocess_message(message, processed);
    int len = strlen(processed);
    int i, j = 0;
    for (i = 0; i < len; i += 2) {
        if (i + 1 == len || processed[i] == processed[i + 1]) {
            encrypted[j++] = processed[i];
            encrypted[j++] = 'X';
        } else {
            encrypted[j++] = processed[i];
            encrypted[j++] = processed[i + 1];
            i++;
        }
    }
    encrypted[j] = '\0';
    for (i = 0; i < j; i += 2) {
        char result[2];
        encrypt_pair(encrypted[i], encrypted[i + 1], result);
        encrypted[i] = result[0];
        encrypted[i + 1] = result[1];
    }
}
int main() {
    char message[256];
    char encrypted[256];
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
}
    playfair_encrypt(message, encrypted);
    printf("Encrypted Message: %s\n", encrypted);
    return 0;
}
