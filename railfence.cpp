#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptRailFenceCipher(char *input, int numRails, char *output) {
    int length = strlen(input);

    char **matrix = malloc(numRails * sizeof(char *));
    for (int i = 0; i < numRails; i++)
        matrix[i] = malloc(length * sizeof(char));

    for (int i = 0; i < numRails; i++)
        for (int j = 0; j < length; j++)
            matrix[i][j] = '\n';

    int row = 0, goingDown = 0;

    for (int i = 0; i < length; i++) {
        matrix[row][i] = input[i];
        if (row == 0 || row == numRails - 1)
            goingDown = !goingDown;
        row += goingDown ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < numRails; i++)
        for (int j = 0; j < length; j++)
            if (matrix[i][j] != '\n')
                output[index++] = matrix[i][j];
    output[index] = '\0';

    for (int i = 0; i < numRails; i++)
        free(matrix[i]);
    free(matrix);
}

void decryptRailFenceCipher(char *cipherText, int numRails, char *output) {
    int length = strlen(cipherText);

    char **matrix = malloc(numRails * sizeof(char *));
    for (int i = 0; i < numRails; i++)
        matrix[i] = malloc(length * sizeof(char));

    for (int i = 0; i < numRails; i++)
        for (int j = 0; j < length; j++)
            matrix[i][j] = '\n';

    int row = 0, goingDown = 0;

    for (int i = 0; i < length; i++) {
        matrix[row][i] = '*';
        if (row == 0 || row == numRails - 1)
            goingDown = !goingDown;
        row += goingDown ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < numRails; i++)
        for (int j = 0; j < length; j++)
            if (matrix[i][j] == '*')
                matrix[i][j] = cipherText[index++];

    row = 0;
    goingDown = 0;
    for (int i = 0; i < length; i++) {
        output[i] = matrix[row][i];
        if (row == 0 || row == numRails - 1)
            goingDown = !goingDown;
        row += goingDown ? 1 : -1;
    }
    output[length] = '\0';

    for (int i = 0; i < numRails; i++)
        free(matrix[i]);
    free(matrix);
}

int main() {
    char message[100], cipherText[100], decryptedText[100];
    int numRails;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter number of rails (key): ");
    scanf("%d", &numRails);

    encryptRailFenceCipher(message, numRails, cipherText);
    printf("Encrypted: %s\n", cipherText);

    decryptRailFenceCipher(cipherText, numRails, decryptedText);
    printf("Decrypted: %s\n", decryptedText);

    return 0;
}
