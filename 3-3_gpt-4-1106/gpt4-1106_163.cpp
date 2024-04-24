#include <vector>

// SomeObject represents whatever type you are storing in your vector
typedef int SomeObject;

// Return a pair of pointer to data and its size
std::pair<SomeObject*, size_t> createAndReturnVectorData() {
    // allocate vector on the heap
    auto vectorPtr = new std::vector<SomeObject>();

    // ... fill your vector with data ...

    // Return a pointer to the data and the size of the vector
    return std::make_pair(vectorPtr->data(), vectorPtr->size());
}

// Function to be later used to delete the vector
void deleteVector(std::vector<SomeObject>* vectorPtr) {
    delete vectorPtr;
}

