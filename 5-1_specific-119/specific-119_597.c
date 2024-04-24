#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>  // Added for string functions

int main(int argc, char** argv) {

    struct stat *buf;
    buf = malloc(sizeof(struct stat)); 

    DIR * current_directory_ptr;
    struct dirent * next_entry_ptr;

    char dirToView[200];  // Changed to char array
    printf("Enter path of desired directory\n");
    scanf("%199s", dirToView);  // Limit input length to prevent buffer overflow

    current_directory_ptr = opendir(dirToView);
    if (current_directory_ptr == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    next_entry_ptr = readdir(current_directory_ptr);

    while (next_entry_ptr != NULL) {
        printf("File has inode number %d and is called %s \n", (int) next_entry_ptr->d_ino, next_entry_ptr->d_name);
        next_entry_ptr = readdir(current_directory_ptr);
    }

    char fileToView[200];
    printf("Enter name of desired file\n");
    scanf("%199s", fileToView);  // Limit input length to prevent buffer overflow

    if (stat(fileToView, buf) == -1) {
        perror("Error getting file information");
        closedir(current_directory_ptr);
        return EXIT_FAILURE;
    }

    off_t size = buf->st_size;
    printf("Size = %ld\n", size);

    uid_t owner = buf->st_uid;
    printf("owner = %d\n", owner);

    closedir(current_directory_ptr);

    free(buf);  // Free the memory allocated for buf

    return EXIT_SUCCESS;
}
