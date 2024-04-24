// Define the struct for file info
struct file {
    char name[1000];
    struct stat file_info;
};

// Recursive function to list files recursively
void listFilesRecursively(char *basePath, struct file files[], int *counter, int size) {
    char path[1000];
    struct dirent *dp;
    struct stat buf;
    DIR *dir = opendir(basePath);

    if (!dir) return;

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            strcpy(files[*counter].name, path);
            stat(path, &buf);
            files[*counter].file_info.st_size = buf.st_size;
            printf("%s%s%ld%s\n", files[*counter].name, " - ",
                   files[*counter].file_info.st_size, "bytes");
            (*counter)++;

            listFilesRecursively(path, files, counter, size);
        }
    }

    closedir(dir);
}

int main() {
    char basePath[1000] = "your_base_path_here";
    int size = your_size_calculation_function_here();
    struct file files[size];
    int counter = 0;

    // Call the recursive function to populate the files array
    listFilesRecursively(basePath, files, &counter, size);

    // Sorting the files array after population
    qsort(files, size, sizeof(struct file), compare); // Implement your compare function

    return 0;
}
