#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char* argv[])
{
    if (argc > 1 && strnicmp(argv[1], "sip:", 4) == 0)
    {
        std::string command = "start \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial ";
        command += std::string(argv[1] + 4); // Extract the phone number from the SIP link
        
        system(command.c_str());
    }
    else
    {
        std::cout << "Usage: dial.exe sip:<phonenumber>" << std::endl;
    }

    return 0;
}
