#include <iostream>
#include <vector>

// Function to create a vector, fill it, and return a pointer to its data
const int* processData()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Output the count of elements in the vector
    std::cout << "Count of elements in vector: " << vec.size() << std::endl;

    // Return a pointer to the data in the vector
    return vec.data();
}

int main()
{
    const int* dataPtr = processData();

    // Access and print the data using the pointer
    std::cout << "Data: ";
    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << dataPtr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
