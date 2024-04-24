#include <stdio.h>
#include <iostream>

int main() {
    FILE* pipe = popen("ls", "r");
    if (!pipe) {
        std::cerr << "Error: failed to open pipe\n";
        return 1;
    }
    char buffer[128];
    std::string result = "";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    std::cout << result;
    return 0;
}