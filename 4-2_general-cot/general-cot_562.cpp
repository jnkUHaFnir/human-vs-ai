#include <iostream>
#include <cstdio>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        return "popen failed!";
    }
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

int main() {
    std::string result = exec("ls -l");
    std::cout << "Command output:\n" << result << std::endl;
    return 0;
}
