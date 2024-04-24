#include <iostream>
#include <cstring> // for strlen
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for (;;)
    {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") == 0) // Compare using strcmp for cstrings
            break;
        capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(string text) {
    string textStr(text); // Convert cstring to std::string

    for (int i = 0; i < textStr.length(); i++)
    {
        if (i == 0)
        {
            textStr[i] = toupper(textStr[i]);
        }
        if (textStr[i] == ' ')
        {
            ++i;
            textStr[i] = toupper(textStr[i]);
        }
    }
    cout << textStr;

    return textStr;
}
