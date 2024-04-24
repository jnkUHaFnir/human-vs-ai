    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    
    char * exec(const char* cmd) 
    {
      FILE* pipe = popen(cmd, "r"); // open a pipe to the command
      if (!pipe) return NULL; // return on Error
      char buffer[128];
      int size = 129;
      char * result = NULL;
      while (!feof(pipe))
      {
        result = realloc(result, size); // allocate or reallocate memory on the heap
        if (fgets(buffer, 128, pipe) != NULL) // read til eof and concatinate the strings 
          strcat(result, buffer);
    
        size += 128;
      }
      pclose(pipe);
    
      return result; // return a pointer to the result string
    }
    
    int main(void)
    {
      char* result = exec("echo \"Hello World!\"");
      if (result) // check for errors
      {
        printf("%s", result); // print Hello World!
        free(result); // free allocated string!
      }
    }