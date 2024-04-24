#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <string>

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        std::string cmd = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe -dial " + std::string(argv[1] + 4);
        if (system(cmd.c_str()) == -1)
        {
            // Handle error when the system call fails
            perror("Error executing command");
            return 1;
        }
    }
    
    return 0;
}
