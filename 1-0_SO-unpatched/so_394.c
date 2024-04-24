    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    
    #define N 10 
    #define BLOCK 9
    int main(void) {
      size_t message_len = N ; // you might want to use N * 7 for a better initial guess - 
                               // but then you don't see the realloc at work...
      char *buffer = (char*) malloc(message_len);
      int i;
      char* a = buffer;
      for (i = 0; i < N; i++)
      {
        int size, n;
        n = sprintf(a, "%d \n", i);
        a += n;
        if ((buffer + message_len - a) < BLOCK) {
          message_len += BLOCK;
          printf("increased buffer to %d\n", message_len);
          buffer = realloc(buffer, message_len);
        }
      }
      printf("at the end, buffer length is %d\n", strlen(buffer));
      buffer = realloc(buffer, strlen(buffer+1)); // trim unused space
      printf("buffer is now: \n%s\n", buffer);
    
    }