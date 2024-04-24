#include <stdio.h>

int main()
{
    char String4H1[20]; // Ensure buffers are large enough to hold the entire string
    char String4H3[20];

    unsigned short BUF = GetWord("@FrontVIB@", 0); // Dummy implementation for demonstration
    unsigned short BUF1 = GetWord("@RearVIB@", 0); // Dummy implementation for demonstration

    // Assuming you have a function GetWord defined elsewhere that returns an unsigned short

    // Construct strings directly using snprintf
    snprintf(String4H1, sizeof(String4H1), "*FV%03d#", BUF);
    snprintf(String4H3, sizeof(String4H3), "*RV%03d#", BUF1);

    // Display String4H1 And String4H3
    printf("%s\n", String4H1);
    printf("%s\n", String4H3);

    return 0;
}

// Dummy implementation for demonstration purposes
unsigned short GetWord(const char *alias, int offset)
{
    // Replace this with the actual implementation that fetches
    // the value from memory
    if (alias && offset == 0) {
        if (alias[1] == 'F') // If it's the front VIB
            return 200;
        if (alias[1] == 'R') // If it's the rear VIB
            return 200;
    }
    return 0; // Fallback for incorrect input
}
