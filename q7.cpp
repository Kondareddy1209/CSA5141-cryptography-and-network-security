#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
void countFreq(char *str, int freq[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }
}
void printFreq(int freq[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] != 0) {
            printf("'%c': %d\n", i, freq[i]);
        }
    }
}
int main() {
    char ciphertext[1000]; 
    int freq[MAX_CHAR] = {0};
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    countFreq(ciphertext, freq);
    printFreq(freq);
    return 0;
}
