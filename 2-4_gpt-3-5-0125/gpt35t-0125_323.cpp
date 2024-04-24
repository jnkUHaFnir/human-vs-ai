#include <iostream>
#include <cstdio>

int main() {
    std::FILE *file = std::fopen("output.txt", "w");
    if (file == nullptr) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    char buffer[100];
    int value = 42;
    
    std::sprintf(buffer, "The value is: %d", value);
    
    std::fprintf(file, "%s\n", buffer);
    
    std::fclose(file);
    
    return 0;
}
