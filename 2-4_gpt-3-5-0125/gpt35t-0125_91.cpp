#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <string>

int main(int argc, char *argv[]) // added arguments to main
{
    // Check if there are command line arguments
    if (argc > 1 && _strnicmp(argv[1], "sip:", 4) == 0)
    { 
        // Change current working directory to where talk.exe is located
        _chdir("C:\\Program Files\\NCHSoftware\\Talk\\");

        // Extract the phone number from the SIP link
        std::string cmd = "start talk.exe -dial " + std::string(argv[1] + 4);

        // Execute the command to dial the number
        system(cmd.c_str());
    }
    return 0;
}
