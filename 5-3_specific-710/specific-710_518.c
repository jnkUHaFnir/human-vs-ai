#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char source[MAX_FILE_SIZE];
    
    FILE *fp = fopen("TheFile.txt", "r");
    if(fp != NULL)
    {
        size_t bytesRead = fread(source, 1, sizeof(source), fp);
        source[bytesRead] = '\0'; // Null-terminate the buffer
        
        fclose(fp);

        // Process the contents of the buffer
        for(size_t x = 0; x < bytesRead; x++)
        {
            char c = source[x];
            //Process chars
        }
    }
    
    return 0;
}
