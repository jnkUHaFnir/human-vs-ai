int i = 0;
while (i < b) {
    if (strcmp(states[i], "tx") == 0) {
      printf("Person living in Texas: %s\n",  names[i]);
    }
    i++;
}
