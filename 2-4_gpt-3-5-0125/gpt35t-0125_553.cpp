#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

string removePunctuation(string word) {
    word.erase(remove(word.begin(), word.end(), '.'), word.end());
    word.erase(remove(word.begin(), word.end(), ','), word.end());
    return word;
}

int main(int argc, char* argv[]) {
    int countWords = 0, countNumbers = 0;

    ifstream file;
    file.open ("input1.txt");
    string word;

    while (file >> word)            // read the text file word-by-word
    {
        word = removePunctuation(word); // remove commas and periods
        if (isdigit(word.at(0)))    // if the first letter a digit it counts as number
        {
            countNumbers++;
        }
        else
        {
            countWords++;
        }
        cout << word << " ";
    }

    cout << endl;
    cout << "Words = " << countWords << "      Numbers = " << countNumbers << endl;

    system("pause");
    return 0;
}
