#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

int main() {
    int n;
    std::string input;

    std::cout << "How many elements would you like to sort?" << std::endl;
    std::cin >> n;

    std::cout << "Enter " << n << " numbers separated by commas to be sorted:" << std::endl;
    std::cin.ignore(); // Ignore the newline character left in the input stream

    std::getline(std::cin, input);

    std::vector<int> unsortedNumbers;
    std::stringstream ss(input);
    std::string token;

    while(std::getline(ss, token, ',')) {
        unsortedNumbers.push_back(std::stoi(token));
    }

    std::sort(unsortedNumbers.begin(), unsortedNumbers.end());

    std::cout << "Sorted numbers: ";
    for (int num : unsortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
