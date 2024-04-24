typedef struct file
{
    char *name;
    struct stat file_info;
} File;

void listFilesRecursively(char *basePath, File* files, int *index) {
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

            // Dynamically allocate memory for files[*index].name
            files[*index].name = malloc(strlen(path) + 1);
            strcpy(files[*index].name, path);

            stat(path, &buf);
            files[*index].file_info.st_size = buf.st_size;
            printf("%s%s%ld%s\n", files[*index].name, " - ", files[*index].file_info.st_size, "bytes");
            (*index)++;

            listFilesRecursively(path, files, index);
        }
    }
    closedir(dir);
}

#define SIZE 1024

int main() {
    int index = 0;
    File files[SIZE];
    listFilesRecursively("/path/to/directory", files, &index);

    // Now your files array contains data 
    // You can now implement sort here for files array
  
  // Remember to free the allocated memory
  for (int i = 0; i < index; i++) {
      free(files[i].name);
  }

  return 0;
}
