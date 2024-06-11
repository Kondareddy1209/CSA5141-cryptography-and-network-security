#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void toUpperCase(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = toupper(s[i]);
    }
}

void removeSpaces(char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ')
            s[count++] = s[i];
    }
    s[count] = '\0';
}

void generateKeyTable(char key[], char keyT[SIZE][SIZE]) {
    int dict[26] = {0};
    int i, j, k, flag = 0;
    int x = 0, y = 0;

    for (i = 0; key[i]; i++) {
        if (key[i] != 'J') {
            key[i] = (key[i] == 'I') ? 'J' : key[i];
            if (dict[key[i] - 'A'] == 0) {
                dict[key[i] - 'A'] = 1;
                keyT[x][y++] = key[i];
                if (y == SIZE) {
                    y = 0;
                    x++;
                }
            }
        }
    }

    for (i = 0; i < 26; i++) {
        if (i != 9 && dict[i] == 0) {
            keyT[x][y++] = (char)(i + 65);
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }
}

void search(char keyT[SIZE][SIZE], char a, char b, int arr[]) {
    int i, j;

    if (a == 'J')
        a = 'I';
    else if (b == 'J')
        b = 'I';

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            } else if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a) {
    return (a % 5);
}

int prepare(char str[], int ptrs) {
    if (str[ptrs] == '\0')
        return 0;
    else if (str[ptrs] == str[ptrs + 1]) {
        for (int i = strlen(str) + 1; i > ptrs + 1; i--)
            str[i] = str[i - 1];
        str[ptrs + 1] = 'X';
    }
    return 1;
}

void encrypt(char str[], char keyT[SIZE][SIZE], int ps) {
    int i, a[4];

    for (i = 0; i < ps; i += 2) {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        } else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        } else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void playfairCipher(char str[], char key[]) {
    char keyT[SIZE][SIZE];

    toUpperCase(str);
    toUpperCase(key);
    removeSpaces(str);
    removeSpaces(key);

    generateKeyTable(key, keyT);

    int ps = strlen(str);
    for (int i = 0; i < ps; i += 2) {
        if (str[i + 1] == '\0')
            str[i + 1] = 'X';
        else if (str[i] == str[i + 1])
            str[i + 1] = 'X';
    }

    if (ps % 2 != 0) {
        str[ps] = 'X';
        str[ps + 1] = '\0';
    }

    encrypt(str, keyT, strlen(str));
}

int main() {
    char str[100], key[100];

    printf("Enter plaintext: ");
    gets(str);
    printf("Enter key: ");
    gets(key);

    playfairCipher(str, key);

    printf("Encrypted text: %s\n", str);
    return 0;
}

