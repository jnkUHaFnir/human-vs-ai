#include <iostream>
#include <cstdlib>

char* readUnlimitedInput() {
    char* buffer = nullptr;
    char* tmp = nullptr;
    char c;
    size_t size = 0;
    size_t len = 0;

    do {
        c = std::cin.get();

        if (c == '\n') {
            c = '\0'; // Replace newline with null terminator
        }

        // Reallocate buffer if needed
        if (len + 1 >= size) {
            size = size == 0 ? 1 : size * 2;
            tmp = (char*)realloc(buffer, size * sizeof(char));
            if (tmp == nullptr) {
                free(buffer);
                return nullptr;
            }
            buffer = tmp;
        }

        buffer[len++] = c;
    } while (c != '\0');

    return buffer;
}

int main() {
    std::cout << "Enter the address of the employee (press Enter twice to finish):" << std::endl;

    char* address = readUnlimitedInput();

    std::cout << "Address: " << address << std::endl;

    free(address);

    return 0;
}
