#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void applyCipher(string &text, const vector<int> &key, bool encrypt = true) {
    int keyLen = key.size();

    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = encrypt ? key[i % keyLen] : -key[i % keyLen];
            text[i] = base + (text[i] - base + shift + 26) % 26;
        }
    }
}

vector<int> convertKeyString(const string &keyStr) {
    vector<int> keyVec;
    for (char ch : keyStr) {
        if (isdigit(ch)) {
            keyVec.push_back(ch - '0');
        }
    }
    return keyVec;
}

int main() {
    string message, keyInput;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter numeric key (digits only): ";
    getline(cin, keyInput);

    vector<int> numericKey = convertKeyString(keyInput);

    string encrypted = message;
    applyCipher(encrypted, numericKey, true);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = encrypted;
    applyCipher(decrypted, numericKey, false);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
