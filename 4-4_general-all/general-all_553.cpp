#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

bool isLetterOrDigit(char c) {
    return isalnum(c) || c == ',' || c == '.';
}

int main() {
    int countWords = 0, countNumbers = 0;
    ifstream file("input1.txt");

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    char c;
    bool inWord = false;

    while (file.get(c)) {
        if (isLetterOrDigit(c)) {
            if (!inWord) {
                inWord = true;
                if (isdigit(c)) {
                    countNumbers++;
                } else {
                    countWords++;
                }
            }
        } else {
            if (inWord) {
                inWord = false;
            }
        }
    }

    // If the last character is a letter or digit, increment word count
    if (inWord) {
        countWords++;
    }

    cout << "Words = " << countWords << "      Numbers = " << countNumbers << endl;

    return 0;
}
