#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i;
    char command_line[1024] = ""; // Assuming a maximum length for the command line
    
    for(i = 0; i < argc; i++){
        strcat(command_line, argv[i]);     // Concatenate each argument to the command_line
        strcat(command_line, " ");         // Separate arguments by space
    }

    printf("Whole command line: %s\n", command_line);

    return 0;
}
