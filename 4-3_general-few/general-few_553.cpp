#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    int countWords = 0, countNumbers = 0;

    ifstream file("input1.txt");
    string word;
    
    // If the file is open
    if (file.is_open()) {
        // Read the entire file to a string
        stringstream buffer;
        buffer << file.rdbuf();
        string fileContents = buffer.str();
        
        // Replace commas and periods with spaces
        for (char& c : fileContents) {
            if (c == ',' || c == '.') {
                c = ' ';
            }
        }
        
        // Use string stream to read words from the modified file contents
        istringstream iss(fileContents);
        
        while (iss >> word) {            
            if (isdigit(word.at(0))) {
                countNumbers++;
            } else {
                countWords++;
            }
            cout << word << " ";
        }
        
        cout << endl;
        cout << "Words = " << countWords << "      Numbers = " << countNumbers << endl;        
    } else {
        cout << "Error opening the file!" << endl;
    }

    system("pause");
    return 0;
}
