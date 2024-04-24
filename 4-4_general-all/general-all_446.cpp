#include <iostream>
#include <cstring> // for strlen
using namespace std;

void capitalizeFirstLetter(const char* text);

int main() {
    char sentence[100];
    while (true)
    {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") == 0)
            break;
        capitalizeFirstLetter(sentence);
    }

    return 0;
}

void capitalizeFirstLetter(const char* text) {
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (i == 0 || text[i - 1] == ' ')
        {
            text[i] = toupper(text[i]);
        }
    }
    cout << text << endl;
}
