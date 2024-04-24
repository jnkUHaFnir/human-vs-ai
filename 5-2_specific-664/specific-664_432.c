void get_user(char* user)
{
  char buf[1024];
  if (strlen(user) > sizeof(buf))
    die("error: user string too long\n");
  strncpy(buf, user, sizeof(buf) - 1); // Copy up to sizeof(buf) - 1 characters
  buf[sizeof(buf) - 1] = '\0'; // Ensure null-termination
  …
}
