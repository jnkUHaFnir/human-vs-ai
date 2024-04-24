#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* read_file_contents(FILE* file) {
    char* buffer = NULL;
    char* tmp_buffer = NULL;
    size_t buffer_size = 0;
    size_t total_size = 0;
    
    while (!feof(file)) {
        tmp_buffer = (char*)malloc(BUFFER_SIZE);
        if (tmp_buffer == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            free(buffer);
            return NULL;
        }
        
        if (fgets(tmp_buffer, BUFFER_SIZE, file) != NULL) {
            total_size += strlen(tmp_buffer);
            buffer = (char*)realloc(buffer, total_size + 1);
            
            if (buffer == NULL) {
                fprintf(stderr, "Memory allocation error\n");
                free(tmp_buffer);
                return NULL;
            }
            
            strcat(buffer, tmp_buffer);
        }
        
        free(tmp_buffer);
    }
    
    return buffer;
}

int main() {
    FILE *tmp1;
    char *artist = NULL;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (tmp1 == NULL) {
        fprintf(stderr, "Failed to open pipe\n");
        return 1;
    }
    
    artist = read_file_contents(tmp1);
    
    pclose(tmp1);
    
    if (artist != NULL) {
        printf("Artist: %s\n", artist);
        free(artist);
    } else {
        fprintf(stderr, "Error reading file contents\n");
        return 1;
    }

    return 0;
}
