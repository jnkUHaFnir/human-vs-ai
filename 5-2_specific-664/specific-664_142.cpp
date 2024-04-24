#include <iostream>
#include <vector>

// Function to combine consecutive elements in the array
std::vector<int> combineElements(std::vector<int>& arr) {
    std::vector<int> result;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size()) {
            result.push_back(arr[i] + arr[i + 1]);
        } else {
            result.push_back(arr[i]); // If there is one element left, copy it as it is
        }
    }
    return result;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::vector<int>> evaluatedData;

    // Perform the operation until there is only one element left
    while (data.size() > 1) {
        evaluatedData.push_back(data);
        data = combineElements(data);
    }

    // Output the final result
    std::cout << "Final result: " << data[0] << std::endl;

    // Free the memory for the evaluated data
    for (const auto& arr : evaluatedData) {
        // Free memory for each evaluated array
        arr.clear();
    }

    return 0;
}
