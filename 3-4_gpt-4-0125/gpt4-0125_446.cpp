#include <iostream>
#include <string>
#include <cstring> // For strcmp

using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for ( ; ; )
    {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") != 0) { // Proper comparison for C strings
            string capitalized = capitalizeFirstLetter(string(sentence));
            cout << capitalized << endl; // Printing the result
        } else {
            break; // Exit if sentence is "0"
        }
    }

    return 0;
}

string capitalizeFirstLetter(string text) {

    bool capitalizeNext = true; // Instead of directly modifying 'i', use a flag

    for (size_t i = 0; i < text.length(); i++)
    {
        if (capitalizeNext && text[i] != ' ') {
            text[i] = toupper(text[i]);
            capitalizeNext = false; // Reset the flag after capitalization
        }
        if (text[i] == ' ') {
            capitalizeNext = true; // Set flag to capitalize next non-space character
        }
    }

    return text; // The console output happens in main now
}
