#include <iostream>
#include <string>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for (;;) {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") == 0)
            break;
        
        capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }
    cout << text << endl;

    return text;
}
