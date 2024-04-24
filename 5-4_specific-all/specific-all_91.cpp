#include <stdlib.h>
#include <windows.h>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    const std::string talkPath = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe";

    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        std::string phoneNumber = std::string(argv[1] + 4);

        // Clear any potential directory changes made by _chdir
        _chdir("C:\\");

        std::string cmd = "start \"" + talkPath + "\" -dial " + phoneNumber;
        
        system(cmd.c_str());
    }
    else
    {
        std::cout << "Usage: dial.exe sip:phonenumber" << std::endl;
    }

    return 0;
}
