#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <stdlib.h>

int file_exists_in_home_or_etc(char *filename)
{
    // Get the current user's home directory
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    
    // Create the full file path for home directory
    char *homepath = malloc(strlen(homedir) + strlen(filename) + 2);
    strcpy(homepath, homedir);
    strcat(homepath, "/");
    strcat(homepath, filename);
    
    if (file_exists(homepath)) {
        free(homepath);
        return 1;
    }
    
    free(homepath);
    
    // Create the full file path for /etc directory
    char etcpath[256];
    snprintf(etcpath, sizeof(etcpath), "/etc/%s", filename);
    
    return file_exists(etcpath);
}
