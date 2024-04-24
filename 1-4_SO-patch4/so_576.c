    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    
    #define S_SIZE 128
    char * exec(const char* cmd) 
    {
      FILE* pipe = popen(cmd, "r"); // open a pipe to the command
      if (!pipe) return NULL; // return on Error
      char buffer[S_SIZE];
      int size = S_SIZE + 1;
      char * result = NULL;
      do
      {
        result = realloc(result, size); // allocate or reallocate memory on the heap
        strcat(result, buffer);
        size += S_SIZE; // increase size for the next run
      } while (fgets(buffer, S_SIZE, pipe) != NULL);
      pclose(pipe);
    
      return result; // return a pointer to the result string
    }
    
    int main(void)
    {
      char* result = exec("echo %username%");
      if (result) // check for errors
      {
        printf("%s", result); // print username
        free(result); // free allocated string!
      }
    }