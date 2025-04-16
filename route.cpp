#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void encryptColumnarTransposition(string input, int numCols, string &cipherText) {
    int length = input.length();
    int numRows = static_cast<int>(ceil(static_cast<double>(length) / numCols));

    vector<vector<char>> grid(numRows, vector<char>(numCols, ' '));

    int index = 0;
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCols; j++)
            grid[i][j] = (index < length) ? input[index++] : 'X';

    index = 0;
    cipherText.clear();
    for (int j = 0; j < numCols; j++)
        for (int i = 0; i < numRows; i++)
            cipherText += grid[i][j];
}

void decryptColumnarTransposition(string cipherText, int numCols, string &decryptedText) {
    int length = cipherText.length();
    int numRows = static_cast<int>(ceil(static_cast<double>(length) / numCols));

    vector<vector<char>> grid(numRows, vector<char>(numCols));

    int index = 0;
    for (int j = 0; j < numCols; j++)
        for (int i = 0; i < numRows; i++)
            grid[i][j] = cipherText[index++];

    index = 0;
    decryptedText.clear();
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCols; j++)
            decryptedText += grid[i][j];
}

int main() {
    string message, cipherText, decryptedText;
    int numCols;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter number of columns: ";
    cin >> numCols;

    encryptColumnarTransposition(message, numCols, cipherText);
    cout << "Encrypted: " << cipherText << endl;

    decryptColumnarTransposition(cipherText, numCols, decryptedText);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
