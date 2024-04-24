void get_user(char* user)
{
  char buf[1024];
  if (strlen(user) > sizeof(buf) - 1) // substract 1 so there will be space for null-terminator
    die("error: user string too long\n");
  strncpy(buf, user, sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0'; // Adding null-terminator in case user string is as long as the buffer
  …
} 
