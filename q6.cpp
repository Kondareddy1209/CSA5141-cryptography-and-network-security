#include <stdio.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}
void decryptAffine(char ciphertext[], int a, int b) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("No modular inverse found for a = %d and m = 26\n", a);
        return;
    }
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int x = (a_inv * ((ciphertext[i] - 'A' - b + 26) % 26)) % 26;
            printf("%c", x + 'A');
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[100]; 
    int a, b;
    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);
    printf("Enter a & b: ");
    scanf("%d %d", &a, &b);  
    decryptAffine(ciphertext, a, b);
    return 0;
}
