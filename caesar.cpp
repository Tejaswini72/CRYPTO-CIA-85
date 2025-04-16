#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to shift characters forward or backward based on mode
void shiftText(string &message, int shift, bool encryptMode) {
    if (!encryptMode) {
        shift = -shift;
    }
    shift = (shift % 26 + 26) % 26;

    for (char &ch : message) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = base + (ch - base + shift) % 26;
        }
    }
}

int main() {
    string input;
    int shift;

    cout << "Enter a message: ";
    getline(cin, input);

    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = input;
    shiftText(encrypted, shift, true);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = encrypted;
    shiftText(decrypted, shift, false);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
