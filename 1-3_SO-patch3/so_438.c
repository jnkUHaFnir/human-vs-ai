    #include <stdbool.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    bool is_program_installed(const char *cmd) {
        const char *path = getenv("PATH");
        if(!path) return false;
        // won't ever need a buffer this long
        char *buf = malloc(strlen(path)+strlen(cmd)+2);
        // loop as long as we have stuff to examine in path
        for(; *path; ++path) {
            // start from the beginning of the buffer
            char *p = buf;
            // copy in buf the current path element
            for(; *path && *path!=':'; ++path,++p) {
                *p = *path;
            }
            // slash and command name
            *p++='/';
            strcpy(p, cmd);
            // check if we can execute it
            if(access(buf, X_OK)==0) {
                free(buf);
                return true;
            }
        }
        // not found
        free(buf);
        return false;
    }