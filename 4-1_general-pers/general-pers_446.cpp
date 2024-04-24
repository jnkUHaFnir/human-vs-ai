#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string capitalizeFirstLetter(const string &text);

int main() {
    string sentence;
    while (true) {
        getline(cin, sentence);
        if (sentence == "0")
            break;
        
        capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(const string &text) {
    string capitalizedText = text;

    for (size_t i = 0; i < text.length(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            capitalizedText[i] = toupper(text[i]);
        }
    }

    cout << capitalizedText << endl;

    return capitalizedText;
}
