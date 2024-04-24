#include <iostream>
#include <vector>
#include <sstream>  // For istringstream
#include <algorithm>  // For sort
using namespace std;

int main() {
    int n;
    cout << "How many elements would you like to sort?" << endl;
    cin >> n;
    cin.ignore();  // Important: Clears the input buffer

    string input;
    cout << "Enter " << n << " numbers separated by spaces to be sorted: " << endl;
    getline(cin, input);  // Using getline to read the whole line of numbers
    
    // Using stringstream to separate numbers based on spaces
    istringstream iss(input);
    vector<int> numbers;
    int temp;
    while (iss >> temp) {
        numbers.push_back(temp);
    }
    
    // If the user entered less/more numbers than they indicated, handle it
    if (numbers.size() != n) {
        cerr << "Error: The number of inputs doesn't match what was specified." << endl;
        return 1;  // Exit the program with status code 1 indicating an error
    }

    cout << "Before sorting: ";
    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    sort(numbers.begin(), numbers.end());  // Sorting the vector of integers
    
    cout << "After sorting: ";
    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
