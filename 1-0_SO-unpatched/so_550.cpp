    #include <stdio.h>  
    #include <stdlib.h>  
    
    int main(void) {       
       FILE* pipe = popen("ls -l", "rt");
    
       if (!pipe) {
          perror("popen");
          exit(1);
       }
       char buffer[128];
       while (fgets(buffer, 128, pipe)) {
          printf(buffer);
       }
       return pclose(pipe);
    }