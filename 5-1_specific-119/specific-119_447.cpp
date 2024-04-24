#include <iostream>
#include <string>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for (;;) {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") != 0) {
            capitalizeFirstLetter(sentence);
        } else {
            break; // Exit the infinite loop if "0" is entered
        }
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
            if (i < text.length()) { // Check if index is within bounds
                text[i] = toupper(text[i]);
            }
        }
    }
    cout << text << endl;

    return text;
}
