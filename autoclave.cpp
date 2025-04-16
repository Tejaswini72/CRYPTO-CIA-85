#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void encryptAutokey(const string &plaintext, const string &keyword, string &ciphertext) {
    string fullKey = keyword + plaintext.substr(0, plaintext.size() - keyword.size());
    ciphertext = "";

    for (size_t i = 0; i < plaintext.size(); ++i) {
        if (isalpha(plaintext[i])) {
            int p = toupper(plaintext[i]) - 'A';
            int k = toupper(fullKey[i]) - 'A';
            ciphertext += (p + k) % 26 + 'A';
        } else {
            ciphertext += plaintext[i];
        }
    }
}

void decryptAutokey(const string &ciphertext, const string &keyword, string &plaintext) {
    string currentKey = keyword;
    plaintext = "";

    for (size_t i = 0; i < ciphertext.size(); ++i) {
        int k = toupper(currentKey[i]) - 'A';
        int c = toupper(ciphertext[i]) - 'A';
        int p = (c - k + 26) % 26;
        char plainChar = p + 'A';
        plaintext += plainChar;
        currentKey += plainChar;  // Extend key with decrypted character
    }
}

int main() {
    string plaintext, keyword, ciphertext, decrypted;

    cout << "Enter plaintext (letters only): ";
    getline(cin, plaintext);

    cout << "Enter keyword (letters only): ";
    getline(cin, keyword);

    encryptAutokey(plaintext, keyword, ciphertext);
    cout << "Encrypted: " << ciphertext << endl;

    decryptAutokey(ciphertext, keyword, decrypted);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
