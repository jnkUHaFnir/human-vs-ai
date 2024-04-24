#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cout << "How many elements would you like to sort?" << endl;
    cin >> n;  //index for the vector

    vector<int> numbers;
    int input;

    cout << "Enter " << n << " numbers to be sorted" <<   endl;

    for (int i=0; i<n; i++){
        cin >> input;
        numbers.push_back(input);  // values inputed stored as vector elements
    }

    // Printing unsorted numbers
    cout << "Unsorted numbers are: ";
    for(int i=0; i<n; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Sorting the vector
    sort(numbers.begin(), numbers.end());

    // Printing sorted numbers
    cout << "Sorted numbers are: ";
    for(int i=0; i<n; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
}
