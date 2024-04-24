#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "How many elements would you like to sort?" << endl;
    cin >> n;  // Index for the array
    
    cout << "Enter " << n << " numbers separated by commas to be sorted" << endl;
    cin.ignore();  // Ignore the newline character after reading n
    string input;
    getline(cin, input);  // Read the line of comma-separated numbers
    
    vector<int> unsortedNumbers;
    stringstream ss(input);
    string token;
    
    while (getline(ss, token, ',')) {  // Parse the comma-separated numbers
        unsortedNumbers.push_back(stoi(token));
    }
    
    sort(unsortedNumbers.begin(), unsortedNumbers.end());  // Sorting the numbers
    
    cout << "Sorted numbers: ";
    
    for (int i = 0; i < unsortedNumbers.size(); i++) {
        cout << unsortedNumbers[i];
        if (i != unsortedNumbers.size() - 1) {
            cout << ",";
        }
    }
    
    cout << endl;

    return 0;
}
