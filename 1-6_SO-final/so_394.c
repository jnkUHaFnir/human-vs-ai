      size_t message_len = 200000 * 7; // good initial guess given we will have 200000 numbers.
      char *buffer = (char*) malloc(message_len);
      for (int i = 0; i < 200000; i++)
      {
        int size;
        char* a = buffer;
        a += sprintf(a, "%d \n", i);
        if ((buffer - a) > 0.95 * message_len) {
          message_len *= 1.1;
          buffer = realloc(buffer, message_len);
        }
      }