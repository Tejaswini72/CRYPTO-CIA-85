#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void atbashCipher(string &text) {
    for (char &ch : text) {
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = 'z' - (ch - 'a');
            } else {
                ch = 'Z' - (ch - 'A');
            }
        }
    }
}

int main() {
    string message;

    cout << "Enter the text to be ciphered/deciphered: ";
    getline(cin, message);

    cout << "Original message: " << message << endl;

    atbashCipher(message);
    cout << "Atbash ciphered message: " << message << endl;

    atbashCipher(message);
    cout << "Decrypted message: " << message << endl;

    return 0;
}
