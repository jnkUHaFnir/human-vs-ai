#include <iostream>
using namespace std;

string capitalizeFirstLetter(string text);

int main() {
    char sentence[100];
    for ( ; ; )
    {
        cin.getline(sentence, 100);
        if (sentence[0] != '0') // Compare the first character of sentence array to '0'
            capitalizeFirstLetter(string(sentence)); // Convert sentence to std::string explicitly
        else
            break; // Exit the infinite loop if the first character is '0'
    }

    return 0;
}

string capitalizeFirstLetter(string text) {
    for (string::size_type i = 0; i < text.length(); i++) // Use string::size_type for i
    {
        if (i == 0 || text[i-1] == ' ') // Simplified approach to capitalize the first letter of each word
        {
            text[i] = toupper(text[i]);
        }
    }
    cout << text << endl; // Add endl to nicely separate outputs for each line

    return text;
}
