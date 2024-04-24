#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <string>

int main(int argc, char* argv[])
{
    // Change directory to where the program is located
    SetCurrentDirectory("C:\\Program Files\\NCHSoftware\\Talk\\");

    // Check if an argument was passed and if it starts with "sip:"
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        // Construct the command to dial the number
        std::string cmd = "start talk.exe -dial " + std::string(argv[1] + 4);

        // Execute the command
        system(cmd.c_str());
    }

    return 0;
}
