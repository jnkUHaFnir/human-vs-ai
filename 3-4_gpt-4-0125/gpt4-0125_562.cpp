#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    // Create a pipe and execute command
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    // Read the output a chunk at a time and append to our result string
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main() {
    try {
        std::string cmdOutput = exec("./some_command");
        std::cout << "The command output was:\n" << cmdOutput << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error executing command: " << e.what() << std::endl;
    }

    return 0;
}
