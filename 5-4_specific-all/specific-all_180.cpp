#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <string>

// Written to implement click-to-dial functionality for soft phones (assuming softphones allow arguments to be passed to dial the phone.)
int main(int argc, char* argv[])
{
    _chdir("C:\\Program Files\\NCHSoftware\\Talk\\");

    if (argc > 1 && _strnicmp(argv[1], "sip:", 4) == 0)
    { 
        // match "sip:" prefix, case insensitive
        std::string cmd = "start talk.exe -dial " + std::string(argv[1] + 4);
        system(cmd.c_str());
    }

    return 0;
}
