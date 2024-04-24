#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char *argv[])
{
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        std::string phoneNumber = std::string(argv[1] + 4); // Extract phone number from the argument

        // Build the full path to talk.exe
        std::string talkExePath = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe";

        // Check if talk.exe exists at the specified path
        if (GetFileAttributesA(talkExePath.c_str()) != INVALID_FILE_ATTRIBUTES)
        {
            // Construct the command to dial the phone number
            std::string command = talkExePath + " -dial " + phoneNumber;

            // Execute the command
            system(command.c_str());
        }
        else
        {
            std::cout << "talk.exe not found at the specified path." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid command line argument. Please provide a SIP phone number." << std::endl;
    }

    return 0;
}
