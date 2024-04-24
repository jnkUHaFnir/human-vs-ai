    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    
    #define S_SIZE 128
    char * exec(const char* cmd) 
    {
      FILE* pipe = _popen(cmd, "r"); // open a pipe to the command
      if (!pipe) return NULL; // return on Error
      char buffer[S_SIZE];
      int size = S_SIZE;
      char * result = NULL;
      while (fgets(buffer, 128, pipe) != NULL)
      {
        result = realloc(result, size); // allocate or reallocate memory on the heap
        if (result && strlen(result)) // check if an error occured or result is empty 
          strcat(result, buffer);  
        else if (result) 
          strcpy(result, buffer); 
        else
        {
          _pclose(pipe);
          return NULL; // return since reallocation has failed!
        }
        size += 128;
      }
      _pclose(pipe);
    
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