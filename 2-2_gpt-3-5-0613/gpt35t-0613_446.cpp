#include <iostream>
#include <cstring>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for ( ; ; )
    {
        cin.getline(sentence, 100);
        if (strcmp(sentence, "0") == 0)
            break;
        capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(string text) {

    for (int i = 0; i < strlen(text.c_str()); i++)
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
    cout << text;

    return text;
}
