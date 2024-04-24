#include <iostream>
#include <vector>

std::pair<int*, size_t> getArrayFromVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Allocate a dynamic array and copy the data from vector
    int* arr = new int[vec.size()];
    std::copy(vec.begin(), vec.end(), arr);

    // Return a pair containing a pointer to the array and its size
    return std::make_pair(arr, vec.size());
}

int main() {
    std::pair<int*, size_t> result = getArrayFromVector();
    int* arr = result.first;
    size_t arrSize = result.second;

    // Access the array data
    for (size_t i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }

    // Don't forget to delete the memory when you're done
    delete[] arr;

    return 0;
}
std::pair<int*, size_t>* getArrayFromVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Allocate a dynamic array and copy the data from vector
    int* arr = new int[vec.size()];
    std::copy(vec.begin(), vec.end(), arr);

    // Create a pair containing a pointer to the array and its size
    std::pair<int*, size_t>* result = new std::pair<int*, size_t>(arr, vec.size());
    return result;
}

int main() {
    std::pair<int*, size_t>* result = getArrayFromVector();

    // Access the data
    int* arr = result->first;
    size_t arrSize = result->second;

    // Print the array data
    for (size_t i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }

    // Don't forget to delete the memory when you're done
    delete[] arr;
    delete result;

    return 0;
}
