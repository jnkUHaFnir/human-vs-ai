#include <iostream>

int main() {
    int* ptr = new int(5);  // Allocate memory for an integer
    delete ptr;             // This is safe even if ptr is NULL

    ptr = NULL; // Null out the pointer to avoid accidental misuse

    // Attempting to dereference ptr here would cause a segmentation fault
    return 0;
}
