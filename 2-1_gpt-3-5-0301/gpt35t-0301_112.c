typedef struct {
    FILE* fp;
} FileHandle;

void FileHandle_init(FileHandle* handle, const char* filename) {
    handle->fp = fopen(filename, "r");
}

void FileHandle_destroy(FileHandle* handle) {
    fclose(handle->fp);
}

void FileHandle_use(FileHandle* handle) {
    // use the file handle, e.g.:
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), handle->fp)) {
        // do something with each line
    }
}

int main() {
    {
        FileHandle handle;
        FileHandle_init(&handle, "test.txt");
        FileHandle_use(&handle);
        // handle goes out of scope here and is automatically destroyed
    }
}
