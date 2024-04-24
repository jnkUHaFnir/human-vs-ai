#include <iostream>
#include <string>
using namespace std;

string capitalizeFirstLetter(const string& text);

int main() {
    string sentence;
    
    for (;;) {
        getline(cin, sentence);
        if (sentence != "0") {
            capitalizeFirstLetter(sentence);
        }
    }

    return 0;
}

string capitalizeFirstLetter(const string& text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (i == 0) {
            text[i] = toupper(text[i]);
        }
        if (text[i] == ' ' && i + 1 < text.length()) {
            text[i + 1] = toupper(text[i + 1]);
        }
    }

    cout << text << endl;

    return text;
}
