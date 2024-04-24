    #include <iostream>
    #include <iterator>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    using namespace std;
    void countWord(const string& word, int &countNumbers, int &countWords);
    int main(int argc, char* argv[]) {
        int countWords = 0, countNumbers = 0;
        ifstream file;
        file.open ("input1.txt");
        string word;
        while (file >> word) {
            // iterate over each "word"
            countWord(word, countNumbers, countWords);
            cout << word << " ";
        }
        cout << endl;
        cout << "Words = " << countWords << "      Numbers = " << countNumbers << endl;
        system("pause");
        return 0;
    }
    void countWord(const string &word, int &countNumbers, int &countWords) {
        bool word_start = true;
        for (int i=0; i < word.length(); i++) {
            if (word_start == true) {
                if (word.at(i) == '.' || word.at(i) == ',') {
                    continue;
                }
                else if (isdigit(word.at(i)) {
                    countNumbers++;
                }
                else {
                    countWords++;
                }
                word_start = false;
            }
            if (word.at(i) == '.' || word.at(i) == ',') {
                word_start = true;
            }
        }
        return;
    }