if (strlen(user) > sizeof(buf))
  die("error: user string too long\n");
strcpy(buf, user);
