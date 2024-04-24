#include <windows.h>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    std::string softphonePath = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe";
    std::string phoneNumber = "";

    if (argc == 2) {
        std::string arg = argv[1]; // Get the argument passed
        if (arg.substr(0, 4) == "sip:") {
            phoneNumber = arg.substr(4); // Extract phone number from "sip:" prefix
        }
    }
    
    if (phoneNumber.empty()) {
        std::cout << "Invalid phone number. Proper usage: dial.exe sip:<phone_number>" << std::endl;
        return 1;
    }

    std::string command = "start \"" + softphonePath + "\" -dial " + phoneNumber;
    system(command.c_str());

    return 0;
}
