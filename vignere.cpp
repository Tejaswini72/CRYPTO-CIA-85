#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void encryptMessage(string &message, const string &key) {
    size_t messageLength = message.length();
    size_t keyLength = key.length();
    size_t j = 0;

    for (size_t i = 0; i < messageLength; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLength]) - 'A';
            message[i] = (message[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

void decryptMessage(string &message, const string &key) {
    size_t messageLength = message.length();
    size_t keyLength = key.length();
    size_t j = 0;

    for (size_t i = 0; i < messageLength; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLength]) - 'A';
            message[i] = (message[i] - base - shift + 26) % 26 + base;
            j++;
        }
    }
}

int main() {
    string message;
    string key;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter key (letters only): ";
    getline(cin, key);

    encryptMessage(message, key);
    cout << "Encrypted: " << message << endl;

    decryptMessage(message, key);
    cout << "Decrypted: " << message << endl;

    return 0;
}
