#include <iostream>
#include <vector>

// Combine consecutive pairs of integers in the vector and return the result.
std::vector<int> combine(const std::vector<int> &numbers) {
    std::vector<int> result;
    for (size_t i = 0; i < numbers.size(); i += 2) {
        int combined = numbers[i] + (i + 1 < numbers.size() ? numbers[i + 1] : 0);
        result.push_back(combined);
    }
    return result;
}

int main() {
    // Initial vector of sorted integers.
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    // Store the intermediate results
    std::vector<std::vector<int>> intermediateResults;

    // Loop until we have only one number left.
    while (numbers.size() > 1) {
        numbers = combine(numbers);
        intermediateResults.push_back(numbers); // Store the intermediate result for later use.
    }

    // Print the final number.
    if (!numbers.empty()) {
        std::cout << "The final number is: " << numbers[0] << std::endl;
    }

    // Print all intermediate results (optional).
    std::cout << "Intermediate results:" << std::endl;
    for (auto &result : intermediateResults) {
        for (auto num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
