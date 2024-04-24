#include <cstdlib>
#include <string>

int main(int argc, char *argv[])
{
    // Change working directory
    _chdir("C:\\Program Files\\NCHSoftware\\Talk\\");

    // Ensure that a phone number argument is provided
    if (argc > 1)
    {
        // Extract the phone number, skipping the "sip:" prefix if present
        std::string phone_number = (std::strncmp(argv[1], "sip:", 4) == 0) ? argv[1] + 4 : argv[1];

        // Build the command string
        std::string cmd = "start \"\" \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial " + phone_number;

        // Execute the command
        system(cmd.c_str());
    }

    return 0;
}
