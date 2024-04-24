strncpy(buf,user,sizeof(buf));
buf[sizeof(buf) - 1] = '\0'; // ensure null termination
#define MAX_USERNAME_LENGTH 1024
void get_user(char* user){
    if(strlen(user) >= MAX_USERNAME_LENGTH)
        die("Error: Username is too long.\n");
    char buf[MAX_USERNAME_LENGTH];
    strncpy(buf, user, sizeof(buf));
    buf[sizeof(buf) - 1] = 0; // ensure null termination
}
