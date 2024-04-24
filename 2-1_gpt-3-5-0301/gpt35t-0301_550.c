#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[100];
    FILE* output;

    // Run the command and capture its output
    sprintf(command, "mycommand --args");
    output = popen(command, "r");

    // Read the output and print it to the console
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), output)) {
        printf("%s", buffer);
    }

    // Close the output stream and exit
    pclose(output);
    return 0;
}
