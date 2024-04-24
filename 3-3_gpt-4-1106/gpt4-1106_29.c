FILE* fp = fopen("test.txt", "r");
if (!fp) {
    perror("file opening failed");
    return EXIT_FAILURE;
}
if (other_condition) {
    perror("other error occurred!");
    fclose(fp);
    return EXIT_FAILURE;
}

// Other code that uses the file
// ...

fclose(fp); // Make sure to close the file in the normal workflow too
return EXIT_SUCCESS;
FILE* fp = fopen("test.txt", "r");
if (!fp) {
    perror("file opening failed");
    return EXIT_FAILURE;
}

if (other_condition) {
    perror("other error occurred!");
    goto cleanup; // goto used for cleanup
}

// ... other work with the file ...

cleanup:
fclose(fp); // Close the file at the cleanup point
return EXIT_FAILURE;

// Normal function exit
return EXIT_SUCCESS;
typedef struct FileHandleWrapper {
    FILE* file;
} FileHandleWrapper;

void FileHandleWrapperDestructor(FileHandleWrapper* wrapper) {
    if (wrapper->file) {
        fclose(wrapper->file);
        wrapper->file = NULL;
    }
}

int main(void) {
    FileHandleWrapper wrapper = {fopen("test.txt", "r")};
    if (!wrapper.file) {
        perror("file opening failed");
        FileHandleWrapperDestructor(&wrapper);
        return EXIT_FAILURE;
    }

    if (other_condition) {
        perror("other error occurred!");
        FileHandleWrapperDestructor(&wrapper);
        return EXIT_FAILURE;
    }

    // ... other work with the file ...

    FileHandleWrapperDestructor(&wrapper);
    return EXIT_SUCCESS;
}
