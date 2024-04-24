#include <iostream>

int main() {
    int* pSomeObject = new int(5);

    // No need to check for NULL before deleting
    delete pSomeObject;
    pSomeObject = NULL; // Good practice to set to NULL after deleting

    // Check if pointer is NULL before accessing
    if (pSomeObject == NULL) {
        std::cout << "Pointer has been deleted." << std::endl;
    } else {
        std::cout << "Pointer still points to memory." << std::endl;
    }

    return 0;
}
``` 

This code snippet demonstrates deleting a pointer without checking for NULL and setting it to NULL after deletion to promote safer programming practices.
