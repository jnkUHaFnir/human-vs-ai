#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    int countWords = 0, countNumbers = 0;

    ifstream file;
    file.open("input1.txt");

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        // Replace commas and periods with spaces
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',' || line[i] == '.') {
                line.replace(i, 1, " ");
            }
        }

        // Read the updated line word-by-word
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (isdigit(word.at(0))) {
                countNumbers++;
            }
            else {
                countWords++;
            }
        }
    }

    cout << "Words = " << countWords << "      Numbers = " << countNumbers << endl;

    system("pause");
    return 0;
}
