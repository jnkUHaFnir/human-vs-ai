#include <iostream>
#include <string>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    string sentence;
    for ( ; ; )
    {
        getline(cin, sentence);
        if (sentence != "0") {
            capitalizeFirstLetter(sentence);
        } else {
            break; // exit the loop when the input is "0"
        }
    }

    return 0;
}

string capitalizeFirstLetter(string text) {

    for (size_t i = 0; i < text.length(); i++)
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
