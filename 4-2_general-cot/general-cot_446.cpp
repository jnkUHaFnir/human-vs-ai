#include <iostream>
#include <string>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    string sentence;
    while (true) {
        cout << "Enter a sentence (type '0' to quit): ";
        getline(cin, sentence);

        if (sentence == "0") {
            break;
        }

        cout << capitalizeFirstLetter(sentence) << endl;
    }

    return 0;
}

string capitalizeFirstLetter(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }

    return text;
}
