#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;

    cout << "How many elements would you like to sort?" << endl;
    cin >> n;  // size of the array

    cout << "Enter " << n << " numbers separated by spaces to be sorted" << endl;

    // vector to store numbers
    vector<int> unsortedNumbers(n);

    // input numbers into the vector
    for (int i = 0; i < n; i++) {
        cin >> unsortedNumbers[i];
    }

    // sort the vector
    std::sort(unsortedNumbers.begin(), unsortedNumbers.end());

    // print the sorted numbers
    for (int i = 0; i < n; i++) {
        cout << unsortedNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}
