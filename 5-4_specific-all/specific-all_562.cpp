#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>

std::string exec_cmd(const char* cmd) {
    char buffer[128];
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
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
    std::string result = exec_cmd("ls -l");
    std::cout << "Command output:\n" << result << std::endl;
    return 0;
}
