#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>

std::string exec_command(const char* cmd) {
    std::array<char, 128> buffer; // Buffer size for reading output

    // Open a pipe to the command
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

int main() {
    try {
        std::string result = exec_command("./some_command");
        std::cout << "Command output:\n" << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
