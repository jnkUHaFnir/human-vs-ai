#include <iostream>
using namespace std;

string capitalizeFirstLetter(const string& text); // Pass by const reference

int main() {
    char sentence[100];
    while (true)
    {
        cin.getline(sentence, 100);
        if (sentence[0] == '0' && sentence[1] == '\0') // Check if the first character is '0' and the next is the null terminator
            break;
        string capitalized = capitalizeFirstLetter(sentence); // This will convert to std::string
        cout << capitalized << endl; // Output the capitalized string
    }

    return 0;
}

string capitalizeFirstLetter(const string& text) { // Pass by const reference to avoid unnecessary copies

    string result = text; // Work on a copy of text so we don't modify the original reference
    if (result.length() > 0)
    {
        result[0] = toupper(result[0]);
    }
    
    for (size_t i = 1; i < result.length(); i++) // Use size_t for matching the type returned by length()
    {
        if (result[i-1] == ' ') // Look for a space in the previous character
        {
            result[i] = toupper(result[i]);
        }
    }
    
    return result; // Caller has to print this if needed
}
