#include <stdlib.h>
#include <windows.h>

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    { 
        std::string cmd = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe -dial " + std::string(argv[1] + 4);
        system(cmd.c_str());
    }

    return 0;
}
