#include <iostream>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for (;;) {
        cin.getline(sentence, 100);
        if (sentence[0] != '0') // compare the first character in the array
            capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (i == 0) {
            text[i] = toupper(text[i]);
        }
        if (text[i] == ' ') {
            ++i;
            text[i] = toupper(text[i]);
        }
    }
    cout << text;

    return text;
}
