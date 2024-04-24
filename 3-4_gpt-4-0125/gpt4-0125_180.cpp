#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <string>

int main(int argc, char* argv[])
{
    // Change the current working directory.
    _chdir("C:\\Program Files\\NCHSoftware\\Talk\\");

    if (argc > 1 && _strnicmp(argv[1], "sip:", 4) == 0)
    { 
        // Extract the phone number from the "sip:" URI.
        std::string phoneNumber = std::string(argv[1] + 4); // Skip the "sip:" part.
        
        // Construct the command to execute.
        std::string cmd = "\"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial " + phoneNumber;
        
        // Execute the command.
        system(cmd.c_str());
    }
    else
    {
        // Handle the case where no valid argument is passed.
        MessageBox(NULL, L"No valid SIP URI provided.", L"Error", MB_OK);
    }
    
    return 0;
}
