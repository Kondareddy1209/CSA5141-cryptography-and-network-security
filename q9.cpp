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
void decrypt_pair(char a, char b, char *result) {
    int row1, col1, row2, col2;
    find_position(a, &row1, &col1);
    find_position(b, &row2, &col2);
    if (row1 == row2) {
        result[0] = matrix[row1][(col1 + SIZE - 1) % SIZE];
        result[1] = matrix[row2][(col2 + SIZE - 1) % SIZE];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + SIZE - 1) % SIZE][col1];
        result[1] = matrix[(row2 + SIZE - 1) % SIZE][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}
void playfair_decrypt(char *message, char *decrypted) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i += 2) {
        char result[2];
        decrypt_pair(message[i], message[i + 1], result);
        decrypted[i] = result[0];
        decrypted[i + 1] = result[1];
    }
    decrypted[len] = '\0';
}
int main() {
    char message[256];
    char decrypted[256];
    printf("Enter the encrypted message: ");
    fgets(message, sizeof(message), stdin);
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }
    playfair_decrypt(message, decrypted);
    printf("Decrypted Message: %s\n", decrypted);
    return 0;
}
