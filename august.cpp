#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void augustCipher(string &text, int key) {
    key %= 26; 
    if (key < 0) key += 26;

    for (char &ch : text) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + key) % 26 + base;
        }
    }
}

int main() {
    string message;
    int key;

    cout << "Enter the text to be ciphered/deciphered: ";
    getline(cin, message);

    cout << "Enter the key (integer): ";
    cin >> key;

    cout << "Original message: " << message << endl;

    augustCipher(message, key);
    cout << "August ciphered message: " << message << endl;

    augustCipher(message, -key);
    cout << "Decrypted message: " << message << endl;

    return 0;
}
