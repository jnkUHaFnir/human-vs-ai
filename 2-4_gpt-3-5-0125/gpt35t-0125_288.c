#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    while(fgets(cmd,128,stdin) != NULL){
        cmd[strcspn(cmd, "\n")] = '\0'; // Remove trailing newline character
        
        if(strcmp(cmd, "exit") == 0){
            break; // Exit the loop if "exit" is entered
        }
        
        // Do something with the input
    }

    return 0;
}
