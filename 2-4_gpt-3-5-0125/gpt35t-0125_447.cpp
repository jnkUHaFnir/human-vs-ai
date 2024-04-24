#include <iostream>
#include <cstring>
using namespace std;

string capitalizeFirstLetter(const char* text);

int main() {
    char sentence[100];
    for (;;)
    {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") != 0)
            capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(const char* text) {
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            text[i] = toupper(text[i]);
        }
        if (text[i] == ' ')
        {
            ++i;
            text[i] = toupper(text[i]);
        }
    }
    cout << text << endl;

    return text;
}
