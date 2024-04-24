#include <iostream>
#include <cstdio>

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");

    try {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }

    pclose(pipe);
    return result;
}

int main() {
    std::string result = exec("./some_command");
    std::cout << "Output: " << result;
    return 0;
}
