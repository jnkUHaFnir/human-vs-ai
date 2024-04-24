#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0) {
        std::string cmd = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe -dial ";
        cmd += std::string(argv[1] + 4); // Extract the phone number from the SIP link
        system(cmd.c_str());
    } else {
        std::cout << "Invalid SIP link format. Example format: sip:5555555555" << std::endl;
    }

    return 0;
}
