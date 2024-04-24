#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::string input;
    int n;

    std::cout << "How many elements would you like to sort?" << std::endl;
    std::cin >> n;

    std::cin.ignore();  // to clear the newline character left in the stream

    std::cout << "Enter " << n << " numbers separated by commas to be sorted:" << std::endl;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::vector<int> numbers;
    int number;

    while (ss >> number) {
        numbers.push_back(number);

        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
