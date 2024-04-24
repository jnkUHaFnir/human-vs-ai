#include <windows.h>
#include <string>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    if (strncmp(lpCmdLine, "sip:", 4) == 0) { // Check if the command line starts with "sip:"
        std::string url(lpCmdLine);
        
        // Extract the phone number from the URL
        std::string phoneNumber = url.substr(4); // Skip "sip:"
        
        // Prepare the command to dial the phone number using talk.exe
        std::string command = "start \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial " + phoneNumber;
        
        // Execute the command
        system(command.c_str());
    }

    return 0;
}
