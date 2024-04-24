#include <iostream>
#include <cstdio>
#include <memory>

// RAII File Handle class
class FileHandle {
public:
    FileHandle(const char* filename, const char* mode) : fileHandle(fopen(filename, mode)) {
        if (!fileHandle) {
            std::perror("Error opening file");
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandle() {
        if (fileHandle) {
            fclose(fileHandle);
        }
    }

    FILE* get() const {
        return fileHandle;
    }

private:
    FILE* fileHandle;
};

int main() {
    try {
        FileHandle file("test.txt", "r");

        // Check for other conditions
        if (other_condition) {
            throw std::runtime_error("Other error occurred!");
        }

        // Use the file handle safely
        // Example: read data from the file
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
