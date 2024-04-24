#include <iostream>
#include <string>
using namespace std;

string capitalizeFirstLetter(const string& text);

int main() {
    char sentence[100];
    for (;;) {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") != 0)
            capitalizeFirstLetter(sentence);
    }
    return 0;
}

string capitalizeFirstLetter(const string& text) {
    string capitalizedText = text;

    for (size_t i = 0; i < text.length(); i++) {
        if (i == 0) {
            capitalizedText[i] = toupper(text[i]);
        }
        if (text[i] == ' ') {
            ++i;
            capitalizedText[i] = toupper(text[i]);
        }
    }
    cout << capitalizedText << endl;

    return capitalizedText;
}
