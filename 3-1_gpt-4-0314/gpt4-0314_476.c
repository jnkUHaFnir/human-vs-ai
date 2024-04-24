#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp, char **buffer, size_t *buffer_size) {
    char ch;
    int i = 0;
    size_t buff_len = *buffer_size;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        if (i + 1 >= buff_len) {
            buff_len = (buff_len == 0) ? 1 : (buff_len * 2);
            *buffer = realloc(*buffer, buff_len);

            if (!*buffer) {
                fprintf(stderr, "Error: Memory reallocation failed.\n");
                return NULL;
            }
            *buffer_size = buff_len;
        }

        (*buffer)[i] = ch;

        ++i;
    }

    if (ch == EOF && i == 0) {
        return NULL; // End of the file
    }

    if (i + 1 < buff_len) {
        *buffer = realloc(*buffer, i + 1);
        if (!*buffer) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            return NULL;
        }
        *buffer_size = i + 1;
    }

    (*buffer)[i] = '\0'; // Add null terminator

    return *buffer;
}
#include <stdio.h>
#include <stdlib.h>

size_t buffer_size = 0;
   char *buffer = NULL;
   FILE *fp = fopen("file.txt", "r");
   if (!fp) {
       perror("Error opening file");
       return 1;
   }

   while (readline(fp, &buffer, &buffer_size) != NULL) {
       printf("%s\n", buffer);
   }

   free(buffer);
   fclose(fp);
