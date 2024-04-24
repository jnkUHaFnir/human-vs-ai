#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp = NULL;
    int result = EXIT_SUCCESS; // Assume success initially

    fp = fopen("test.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    if (other_condition) {
        perror("Other error occurred!");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    // Do something with the file

cleanup:
    if (fp) {
        fclose(fp);
    }
    return result;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct RAIIFile_ {
    FILE* fp;
    void (*cleanup)(struct RAIIFile_*);
} RAIIFile;

void closeFile(RAIIFile* rfile) {
    if (rfile->fp) {
        fclose(rfile->fp);
        rfile->fp = NULL;
    }
    free(rfile); // free RAIIFile if dynamically allocated
}

RAIIFile* openRAIIFile(const char* filename, const char* mode) {
    RAIIFile* rfile = malloc(sizeof(RAIIFile)); // Assume malloc succeeds for brevity 
    rfile->fp = fopen(filename, mode);
    if (!rfile->fp) {
        free(rfile); // Handle fopen failure
        return NULL;
    }
    rfile->cleanup = closeFile;
    return rfile;
}

int main() {
    RAIIFile* rfile = openRAIIFile("test.txt", "r");
    if (!rfile) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    if (other_condition) {
        perror("Other error occurred!");
        rfile->cleanup(rfile);
        return EXIT_FAILURE;
    }

    // Do something with the file

    rfile->cleanup(rfile); // Cleanup
    return EXIT_SUCCESS;
}
