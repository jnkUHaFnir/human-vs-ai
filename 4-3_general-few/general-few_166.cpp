#include <iostream>
#include <algorithm>
#include <sstream>  // For stringstream
#include <vector>   // For vector
#include <string>

using namespace std;

int main() {
    int n;

    cout << "How many elements would you like to sort?" << endl;
    cin >> n;

    cout << "Enter " << n << " numbers separated by commas to be sorted" << endl;
    cin.ignore(); // Ignore the newline character

    string input;
    getline(cin, input);

    // Use a stringstream to parse the input string
    stringstream ss(input);
    vector<int> unsortedNumbers;

    int temp;
    char comma; // To store the comma character
    while(ss >> temp) {
        unsortedNumbers.push_back(temp);
        ss >> comma; // Read the comma
    }

    cout << "Input numbers: ";
    for(int num : unsortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the vector of numbers
    sort(unsortedNumbers.begin(), unsortedNumbers.end());

    cout << "Sorted numbers: ";
    for(int num : unsortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
