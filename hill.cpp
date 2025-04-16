#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mod(int val) {
    return (val % 26 + 26) % 26;
}

int computeDeterminant(int m[2][2]) {
    return mod(m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

int modularInverse(int num) {
    for (int i = 0; i < 26; ++i) {
        if ((num * i) % 26 == 1)
            return i;
    }
    return -1;
}

void hillEncrypt(char *input, int matrix[2][2]) {
    int n = strlen(input);
    if (n % 2 != 0)
        strcat(input, "X");  // padding if odd

    printf("Encrypted message: ");
    for (int i = 0; i < n; i += 2) {
        int a = toupper(input[i]) - 'A';
        int b = toupper(input[i+1]) - 'A';
        int c1 = mod(matrix[0][0] * a + matrix[0][1] * b);
        int c2 = mod(matrix[1][0] * a + matrix[1][1] * b);
        printf("%c%c", c1 + 'A', c2 + 'A');
    }
    printf("\n");
}

void hillDecrypt(char *encText, int matrix[2][2]) {
    int det = computeDeterminant(matrix);
    int inv = modularInverse(det);
    if (inv == -1) {
        printf("Key matrix not invertible modulo 26.\n");
        return;
    }

    int inverseMatrix[2][2];
    inverseMatrix[0][0] = mod( matrix[1][1] * inv);
    inverseMatrix[0][1] = mod(-matrix[0][1] * inv);
    inverseMatrix[1][0] = mod(-matrix[1][0] * inv);
    inverseMatrix[1][1] = mod( matrix[0][0] * inv);

    printf("Decrypted message: ");
    for (int i = 0; i < strlen(encText); i += 2) {
        int p = toupper(encText[i]) - 'A';
        int q = toupper(encText[i+1]) - 'A';
        int d1 = mod(inverseMatrix[0][0] * p + inverseMatrix[0][1] * q);
        int d2 = mod(inverseMatrix[1][0] * p + inverseMatrix[1][1] * q);
        printf("%c%c", d1 + 'A', d2 + 'A');
    }
    printf("\n");
}

int main() {
    char plainText[100], encryptedText[100];
    int keyMatrix[2][2];

    printf("Enter 2x2 matrix key (4 integers): ");
    scanf("%d %d %d %d", &keyMatrix[0][0], &keyMatrix[0][1], &keyMatrix[1][0], &keyMatrix[1][1]);
    getchar(); // clear buffer

    printf("Enter message (alphabet only): ");
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = 0;

    // Validate input
    for (int i = 0; plainText[i]; i++) {
        if (!isalpha(plainText[i])) {
            printf("Message must contain only alphabetic characters.\n");
            return 1;
        }
    }

    hillEncrypt(plainText, keyMatrix);

    printf("Enter ciphertext to decrypt: ");
    fgets(encryptedText, sizeof(encryptedText), stdin);
    encryptedText[strcspn(encryptedText, "\n")] = 0;

    hillDecrypt(encryptedText, keyMatrix);

    return 0;
}
