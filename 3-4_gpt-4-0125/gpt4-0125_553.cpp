#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int countWords = 0, countNumbers = 0;

    ifstream file("input1.txt"); // Open the input file.
    if (!file){
        cout << "Error opening file!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf(); // Read the entire file content into a string stream.
    file.close(); // Close the file as its content is now in the buffer.

    string content = buffer.str(); // Convert the string stream into a string.

    // Replace commas and periods in the string with spaces.
    for(char& ch : content) {
        if(ch == ',' || ch == '.') {
            ch = ' ';
        }
    }

    // Convert the modified string back into a stream for easy word by word parsing.
    stringstream modifiedStream(content);
    string word;

    // Parse the modified content word-by-word.
    while (modifiedStream >> word) { // Read word by word.
        if (isdigit(word.at(0))) {   // If the first character is a digit, count as a number.
            countNumbers++;
        } else {
            countWords++;
        }
    }

    // Output the word and number counts.
    cout << "Words = " << countWords << "      Numbers = " << countNumbers << endl;

    return 0;
}
