#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {

    struct stat buf;
    
    DIR *current_directory_ptr;
    struct dirent *next_entry_ptr;

    char dirToView[200];
    
    printf("Enter path of the desired directory\n");
    scanf("%199s", dirToView);

    current_directory_ptr = opendir(dirToView);

    if(current_directory_ptr == NULL) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    while((next_entry_ptr = readdir(current_directory_ptr)) != NULL) {
        printf("File has inode number %ld and is called %s \n",
             (long) next_entry_ptr->d_ino, next_entry_ptr->d_name);
    }

    closedir(current_directory_ptr);

    char fileToView[200];
    printf("\nEnter name of desired file\n");
    scanf("%199s", fileToView);

    if(stat(fileToView, &buf) == -1) {
        perror("Failed to get file details");
        return EXIT_FAILURE;
    }

    off_t size = buf.st_size;
    printf("Size = %ld \n", size);

    uid_t owner = buf.st_uid;
    printf("Owner = %d \n", owner);


    return EXIT_SUCCESS;
}
