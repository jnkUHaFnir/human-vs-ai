#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv) {

    struct stat buf; // No need to dynamically allocate memory, use automatic storage

    DIR *current_directory_ptr; // Pointer to the directory stream
    struct dirent *next_entry_ptr; // Pointer to the directory entry

    char dirToView[200]; // Array to store the directory path
    char fileToView[200]; // Array to store the file path

    printf("Enter path of desired directory\n");
    scanf("%199s", dirToView); // Limit string length to prevent buffer overflow

    current_directory_ptr = opendir(dirToView);
    if (current_directory_ptr == NULL) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    while ((next_entry_ptr = readdir(current_directory_ptr)) != NULL) {
        printf("File has inode number %ld and is called %s \n", 
             (long)next_entry_ptr->d_ino, next_entry_ptr->d_name);
    }

    printf("Enter name of desired file\n");
    scanf("%199s", fileToView); // Limit string length to prevent buffer overflow

    // Use the address of buf since stat expects a pointer to struct stat
    if (stat(fileToView, &buf) == -1) {
        perror("Failed to get file status");
        closedir(current_directory_ptr);
        return EXIT_FAILURE;
    }

    off_t size = buf.st_size; // Access the members directly, no need for a pointer
    printf("Size = %ld \n", size);

    uid_t owner = buf.st_uid;
    printf("owner = %u \n", owner); // Use %u for uid_t, which is typically unsigned

    closedir(current_directory_ptr);

    return EXIT_SUCCESS;
}
