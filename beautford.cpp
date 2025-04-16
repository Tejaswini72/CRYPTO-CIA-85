#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Beaufort cipher encryption/decryption function
void applyBeaufortCipher(string &text, const string &keyInput) {
    string key = keyInput;
    int keyIndex = 0;
    int keyLen = key.length();

    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int charIndex = toupper(text[i]) - 'A';
            int keyChar = toupper(key[keyIndex % keyLen]) - 'A';
            int cipherVal = (keyChar - charIndex + 26) % 26;
            text[i] = base + cipherVal;
            keyIndex++;
        }
    }
}

int main() {
    string message, keyword;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the keyword (letters only): ";
    getline(cin, keyword);

    string encrypted = message;
    applyBeaufortCipher(encrypted, keyword);
    cout << "Encrypted message: " << encrypted << endl;

    string decrypted = encrypted;
    applyBeaufortCipher(decrypted, keyword);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
