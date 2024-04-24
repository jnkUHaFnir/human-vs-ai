#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;

    std::cout << "How many elements would you like to sort?" << std::endl;
    std::cin >> n;

    std::vector<int> unsortedNumbers;

    std::cout << "Enter " << n << " numbers separated by spaces to be sorted" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        unsortedNumbers.push_back(num); // Store the input numbers in the vector
    }

    std::sort(unsortedNumbers.begin(), unsortedNumbers.end());

    std::cout << "Sorted numbers: ";
    for (int num : unsortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
