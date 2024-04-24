#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    cout << "How many elements would you like to sort?" << endl;
    cin >> n; // Number of elements to sort
    
    cout << "Enter " << n << " numbers separated by spaces to be sorted" << endl;
    
    // Read the input line
    string input;
    cin.ignore(); // Clear the input buffer
    getline(cin, input);
    
    istringstream iss(input);
    vector<int> numbers;
    int num;
    
    // Parse the input line and store numbers in a vector
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    // Sort the vector of numbers
    sort(numbers.begin(), numbers.end());
    
    // Output the sorted numbers
    cout << "Sorted numbers: ";
    for (const int& number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
