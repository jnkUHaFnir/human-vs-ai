#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <string>

int main(int argc, char* argv[])
{
    if (argc > 1 && _strnicmp(argv[1], "sip:", 4) == 0)
    { 
        std::string cmd = "start \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial " + std::string(argv[1]+4);
        system(cmd.c_str());
    }
    else
    {
        printf("No valid SIP number provided.\n");
    }

    return 0;
}
