int file_exists(char *filename)
{
    struct stat buffer;
    char home_path[256];
    char etc_path[256];
    char full_path[512];
    
    // Get the path to the user's home directory
    char *user_home = getenv("HOME");
    
    // Create the full path to the file in the user's home directory
    snprintf(home_path, sizeof(home_path), "%s/%s", user_home, filename);
    
    // Check if the file exists in the user's home directory
    if (stat(home_path, &buffer) == 0) {
        return 1;
    }
    
    // Create the full path to the file in the /etc directory
    snprintf(etc_path, sizeof(etc_path), "/etc/%s", filename);
    
    // Check if the file exists in the /etc directory
    if (stat(etc_path, &buffer) == 0) {
        return 1;
    }
    
    return 0;
}
