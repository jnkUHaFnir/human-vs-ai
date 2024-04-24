#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

int main() {
    int n;

    std::cout << "How many elements would you like to sort?" << std::endl;
    std::cin >> n;

    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter " << n << " numbers separated by commas to be sorted" << std::endl;

    std::vector<int> unsortedNumbers;

    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ',')) {
        unsortedNumbers.push_back(std::stoi(token));
    }

    std::sort(unsortedNumbers.begin(), unsortedNumbers.end());

    std::cout << "Sorted numbers:" << std::endl;
    for (int num : unsortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
