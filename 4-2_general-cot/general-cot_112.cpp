#include <cstdio>
#include <memory>

class FileRAII {
public:
    FileRAII(const char* filename, const char* mode) : fileHandle(fopen(filename, mode)) {
        if (!fileHandle) {
            perror("Error opening file");
            // You can throw an exception here if you prefer exception handling
        }
    }

    ~FileRAII() {
        if (fileHandle) {
            fclose(fileHandle);
        }
    }

    FILE* getFile() const {
        return fileHandle;
    }

private:
    FILE* fileHandle;
};

// Example usage
void readFile(const char* filename) {
    FileRAII file(filename, "r");
    
    if (someCondition) {
        perror("Other error occurred!");
        return;
    }

    // File operations using file.getFile()
}
