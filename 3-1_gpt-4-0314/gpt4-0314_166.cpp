#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;

    cout << "How many elements would you like to sort?" << endl;

    cin >> n;

    cout << "Enter " << n << " numbers separated by spaces to be sorted" <<   endl;

    vector<int> unsortedNumbers(n);

    for(int i = 0; i < n; i++) {
        cin >> unsortedNumbers[i];
    }

    for(auto num : unsortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    std::sort(unsortedNumbers.begin() , unsortedNumbers.end());
    
    for(auto num : unsortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

}
