#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalizeFirstLetter(char* text);

int main() {
    char sentence[100];
    for (;;)
    {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") != 0)
            capitalizeFirstLetter(sentence);
        else
            break;
    }

    return 0;
}

void capitalizeFirstLetter(char* text) {
    bool capitalizeNext = true;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (capitalizeNext && islower(text[i]))
        {
            text[i] = toupper(text[i]);
            capitalizeNext = false;
        }
        else if (text[i] == ' ')
        {
            capitalizeNext = true;
        }
    }

    cout << text << endl;
}
