#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char* argv[])
{
    if (argc > 1 && _strnicmp(argv[1], "sip:", 4) == 0)
    { 
        std::string exePath = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe";
        std::string phoneNumber = std::string(argv[1] + 4);  // Extract the phone number from the SIP link
        
        // Quote the paths to account for spaces in the directory name
        std::string command = "start \"" + exePath + "\" -dial " + phoneNumber;
        system(command.c_str());
    }
    else
    {
        std::cout << "Invalid command. Usage: dial.exe sip:<phone_number>\n";
    }

    return 0;
}
