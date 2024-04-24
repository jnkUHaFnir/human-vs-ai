#include <string.h>

void get_user(char* user)
{
  char buf[1024];
  if (strlen(user) >= sizeof(buf)) {
    die("error: user string too long\n");
  }
  strncpy(buf, user, sizeof(buf) - 1); // Limit the size to avoid buffer overflow
  buf[sizeof(buf) - 1] = '\0'; // Ensure null termination
  // ...
}