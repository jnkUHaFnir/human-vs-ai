char str[] = "?cmd=ASET&08&30";

// check if the string starts with "?cmd=ASET"
if (strncmp(str, "?cmd=ASET", 10) == 0) {
  char *hour_ptr, *min_ptr;

  // find the hour value
  hour_ptr = strtok(str + 10, "&");

  // find the minute value
  min_ptr = strtok(NULL, "&");

  // convert the hour and minute values to integers and assign to global variables
  hour = atoi(hour_ptr);
  minute = atoi(min_ptr);
}
