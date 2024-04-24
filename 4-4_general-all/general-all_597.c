int main(int argc, char** argv) {

    struct stat *buf;
    buf = malloc(sizeof(struct stat)); 

    DIR * current_directory_ptr;
    struct dirent * next_entry_ptr;

    char dirToView[200]; // Changed to a single pointer to store the directory path
    printf("Enter path of desired directory\n");
    scanf("%199s", dirToView); // Changed to correctly read the directory path

    current_directory_ptr = opendir(dirToView);

    next_entry_ptr = readdir(current_directory_ptr);

    while(next_entry_ptr != NULL){
        printf("File has inode number %ld and is called %s \n", (long) next_entry_ptr->d_ino, next_entry_ptr->d_name);
        next_entry_ptr = readdir(current_directory_ptr);
    }

    char fileToView[200]; // Changed to a single pointer to store the file name
    printf("Enter name of desired file\n");
    scanf("%199s", fileToView); // Changed to correctly read the file name

    stat(fileToView, buf);
    
    if (S_ISREG(buf->st_mode)) {
        off_t size = buf->st_size;
        printf("Size = %lld \n", (long long)size); // Corrected to use %lld for off_t type
        uid_t owner = buf->st_uid;
        printf("Owner = %d \n", owner);
    } else {
        printf("The specified file is not a regular file.\n");
    }

    closedir(current_directory_ptr);

    free(buf); // Free the allocated memory

    return (EXIT_SUCCESS);
}
