    #include <stdbool.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    bool can_run_command(const char *cmd) {
        if(strchr(cmd, '/')) {
            // if cmd includes a slash, no path search must be performed,
            // go straight to checking if it's executable
            return access(cmd, X_OK)==0;
        }
        const char *path = getenv("PATH");
        if(!path) return false; // something is horribly wrong...
        // we are sure we won't need a buffer any longer
        char *buf = malloc(strlen(path)+strlen(cmd)+3);
        if(!buf) return false; // actually useless, see comment
        // loop as long as we have stuff to examine in path
        for(; *path; ++path) {
            // start from the beginning of the buffer
            char *p = buf;
            // copy in buf the current path element
            for(; *path && *path!=':'; ++path,++p) {
                *p = *path;
            }
            // empty path entries are treated like "."
            if(p==buf) *p++='.';
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