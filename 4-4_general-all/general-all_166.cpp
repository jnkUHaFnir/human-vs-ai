#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    int n;

    std::cout << "How many elements would you like to sort?" << std::endl;
    std::cin >> n;

    std::cout << "Enter " << n << " numbers separated by commas to be sorted" << std::endl;

    std::string input;
    std::cin.ignore(); // Ignore the newline character left in the stream

    std::getline(std::cin, input);

    std::stringstream ss(input);
    int* unsortedNumbers = new int[n]; // Dynamic allocation for the array

    for (int i = 0; i < n; i++) {
        std::string temp;
        std::getline(ss, temp, ',');
        unsortedNumbers[i] = std::stoi(temp);
    }

    // Sorting the array
    std::sort(unsortedNumbers, unsortedNumbers + n);

    std::cout << "Sorted numbers: ";
    for (int i = 0; i < n; i++) {
        std::cout << unsortedNumbers[i];
        if (i != n - 1) {
            std::cout << ", ";
        }
    }

    delete[] unsortedNumbers; // Free the dynamically allocated array

    return 0;
}
