#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int n;
    string line;

    cout << "How many elements would you like to sort?" << endl;
    cin >> n;
    cin.ignore();  // Ignore the newline character from the stream after reading n

    vector<int> numbers(n); // Vector to store the numbers

    cout << "Enter " << n << " numbers separated by spaces to be sorted" << endl;

    // Loop to read n numbers
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Sorting the vector of numbers
    sort(numbers.begin(), numbers.end());

    // Output the sorted numbers
    cout << "Sorted numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}
