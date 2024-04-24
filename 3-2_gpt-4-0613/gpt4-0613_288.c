#include <string.h>

char cmd[128];

fgets(cmd, 128, stdin);

// remove newline character at the end of the input (if any)
cmd[strcspn(cmd, "\n")] = 0;

if(strcmp(cmd, "exit") == 0){
    //stuff
}
