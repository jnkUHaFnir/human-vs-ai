    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    char *convert_to_16(char const *array, size_t const len);
    
    char *convert_to_16(char const *array, size_t const len) {
      size_t const len_buffer = len * 2 + 1;
      char *buffer = malloc(len_buffer);
      if (buffer == NULL) {
        return NULL;
      }
      size_t used = 0;
      for (size_t i = 0; i < len; i++) {
        if (len_buffer < used || len_buffer - used < 3) {
          free(buffer);
          return NULL;
        }
        int ret = sprintf(buffer + used, "%2x", (int)array[i]);
        if (ret < 0) {
          free(buffer);
          return NULL;
        }
        used += (size_t)ret;
      }
      char *ret = realloc(buffer, used + 1); // we don't need the extra space
      return ret != NULL ? ret : buffer;
    }
    
    int main(void) {
      char const param[] = "ABCDEFGHTUIKLL";
      printf("%s\n", param);
      char *ret = convert_to_16(param, sizeof param - 1);
      if (ret != NULL) {
        printf("%s\n", ret);
      }
      free(ret);
    }