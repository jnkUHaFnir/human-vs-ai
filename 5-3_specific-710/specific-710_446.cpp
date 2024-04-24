#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

string capitalizeFirstLetter(const char* text);

int main() {
    char sentence[100];
    for (;;) {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") != 0) {
            capitalizeFirstLetter(sentence);
        } else {
            break;
        }
    }

    return 0;
}

string capitalizeFirstLetter(const char* text) {
    string result = ""; // Initialize an empty string to store the capitalized result
    bool capitalizeNext = true;

    for (size_t i = 0; i < strlen(text); i++) {
        if (capitalizeNext && isalpha(text[i])) {
            result += toupper(text[i]);
            capitalizeNext = false;
        } else {
            result += text[i];
            if (text[i] == ' ') {
                capitalizeNext = true;
            }
        }
    }
    
    cout << result << endl;

    return result;
}
