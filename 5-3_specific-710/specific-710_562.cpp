#include <iostream>
#include <memory>
#include <cstdio>
#include <string>

std::string execute_command(const char* command) {
    char buffer[128];
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen(command, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != nullptr) {
            result += buffer;
        }
    }
    return result;
}

int main() {
    std::string command_output = execute_command("./some_command");
    std::cout << "Command output: " << command_output << std::endl;
    return 0;
}
