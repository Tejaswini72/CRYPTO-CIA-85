#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputText;
    int nGramSize, textLength;

    // Get input text from user
    cout << "Enter the text: ";
    getline(cin, inputText);

    // Get N-gram size
    cout << "Enter the value of N: ";
    cin >> nGramSize;

    textLength = inputText.length();

    // Check for valid N-gram size
    if (nGramSize <= 0 || nGramSize > textLength) {
        cout << "Invalid N-gram size.\n";
        return 1;
    }

    // Display the N-grams
    cout << "\nGenerated " << nGramSize << "-grams:\n";
    for (int i = 0; i <= textLength - nGramSize; ++i) {
        cout << "-> " << inputText.substr(i, nGramSize) << "\n";
    }

    return 0;
}
