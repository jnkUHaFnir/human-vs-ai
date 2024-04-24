#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;

    cout << "How many elements would you like to sort?" << endl;
    cin >> n;  //index for the array

    cout << "Enter " << n << " numbers separated by a comma to be sorted" <<   endl;

    string input;
    cin.ignore(); // Ignore the newline character left in the input buffer

    getline(cin, input); // Read the entire line of input

    vector<int> unsortedNumbers;

    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        int num = stoi(token);
        unsortedNumbers.push_back(num);  // Add each number to the vector
    }

    // Sort the vector of numbers
    sort(unsortedNumbers.begin(), unsortedNumbers.end());

    // Print the sorted numbers
    cout << "Sorted numbers: ";
    for (int num : unsortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
