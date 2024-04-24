#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

int main(int argc, char *argv[])
{
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        std::string cmd = "start \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial ";
        cmd += std::string(argv[1] + 4); // Skip the "sip:" prefix
        std::cout << "Executing command: " << cmd << std::endl;
        system(cmd.c_str());
    }

    return 0;
}
