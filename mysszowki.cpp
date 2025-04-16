#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Comparator for sorting characters
int charCompare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

// Compute order of columns based on key
void computeColumnRanks(const char *keyword, int *order) {
    int n = strlen(keyword);
    char *sorted = (char *)malloc((n + 1) * sizeof(char));
    strcpy(sorted, keyword);

    for (int i = 0; i < n; ++i)
        sorted[i] = tolower(sorted[i]);

    qsort(sorted, n, sizeof(char), charCompare);

    int rank = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tolower(keyword[j]) == sorted[i] && order[j] == 0) {
                order[j] = rank;
                break;
            }
        }
        if (i + 1 < n && sorted[i] != sorted[i + 1])
            rank++;
    }

    free(sorted);
}

// Perform Myszkowski encryption
void performEncryption(const char *input, const char *keyword, char *output) {
    int inputLen = strlen(input);
    int keyLen = strlen(keyword);
    int totalRows = (inputLen + keyLen - 1) / keyLen;

    char **grid = (char **)malloc(totalRows * sizeof(char *));
    for (int i = 0; i < totalRows; ++i)
        grid[i] = (char *)malloc(keyLen * sizeof(char));

    // Fill grid row-wise
    for (int i = 0; i < totalRows * keyLen; ++i)
        grid[i / keyLen][i % keyLen] = (i < inputLen) ? input[i] : 'X';

    int *columnRanks = (int *)calloc(keyLen, sizeof(int));
    computeColumnRanks(keyword, columnRanks);

    // Find the maximum rank
    int highestRank = 0;
    for (int i = 0; i < keyLen; ++i)
        if (columnRanks[i] > highestRank)
            highestRank = columnRanks[i];

    int pos = 0;
    for (int r = 1; r <= highestRank; ++r) {
        for (int c = 0; c < keyLen; ++c) {
            if (columnRanks[c] == r) {
                for (int row = 0; row < totalRows; ++row) {
                    output[pos++] = grid[row][c];
                }
            }
        }
    }

    output[pos] = '\0';

    for (int i = 0; i < totalRows; ++i)
        free(grid[i]);
    free(grid);
    free(columnRanks);
}

int main() {
    char message[200], cipher[300], keyword[50];

    printf("Enter plain text: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter keyword: ");
    scanf("%s", keyword);

    performEncryption(message, keyword, cipher);

    printf("Encrypted Output: %s\n", cipher);

    return 0;
}
