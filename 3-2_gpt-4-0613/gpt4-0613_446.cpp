#include <cctype>
#include <iostream>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    string sentence;  // Using std::string is easier and safer
    while (true)
    {
        getline(cin, sentence);  // std::getline for std::string
        if (sentence != "0")
            sentence = capitalizeFirstLetter(sentence);
    }

    return 0;
}

string capitalizeFirstLetter(string text) {
    for (std::size_t i = 0; i < text.length(); i++)
    {
        if (i == 0)
        {
            text[i] = toupper(text[i]);
        }
        else if (text[i] == ' ')
        {
            text[i+1] = toupper(text[i+1]);
        }
    }
    cout << text << "\n";

    return text;
}
