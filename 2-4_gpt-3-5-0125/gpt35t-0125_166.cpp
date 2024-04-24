#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int n;
    cout << "How many elements would you like to sort?" << endl;
    cin >> n;  //index for the array

    cout << "Enter " << n << " numbers separated by a comma to be sorted" << endl;
    cin.ignore(); // Ignores the newline character in input buffer

    string input;
    getline(cin, input);

    vector<int> unsortedNumbers;

    istringstream iss(input);
    string token;
    while(getline(iss, token, ',')){
        unsortedNumbers.push_back(stoi(token));
    }

    sort(unsortedNumbers.begin(), unsortedNumbers.end());

    cout << "Sorted numbers: ";
    for(int i=0; i<unsortedNumbers.size(); i++){
        cout << unsortedNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}
