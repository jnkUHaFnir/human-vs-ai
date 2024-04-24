#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "How many elements would you like to sort?" << endl;
    cin >> n;  //index for the array
    int* unsortedNumbers = new int[n]; // dynamically allocate integer array of size n
    cout << "Enter " << n << " numbers to be sorted" << endl;

    // input array values
    for(int i=0; i<n; i++){
        cin >> unsortedNumbers[i];
    }

    // sort array
    sort(unsortedNumbers, unsortedNumbers+n);

    // print sorted array
    cout << "Sorted array: " << endl;
    for(int i=0; i<n; i++){
        cout << unsortedNumbers[i] << " ";
    }
    cout << endl;

    // free dynamically allocated memory
    delete[] unsortedNumbers;
    return 0;
}
