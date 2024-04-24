#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char** argv) {

    struct stat *buf;
    buf = malloc(sizeof(struct stat)); 

    DIR *current_directory_ptr; /* DIR is a type from dirent.h */
    struct dirent *next_entry_ptr; /* struct dirent is a type from dirent.h */

    char dirToView[200]; // Changed from char* dirToView[200] to char dirToView[200]

    printf("Enter path of desired directory\n");
    scanf("%s", dirToView); // Removed & before dirToView

    current_directory_ptr = opendir(dirToView);

    next_entry_ptr = readdir(current_directory_ptr);

    while(next_entry_ptr != NULL){
        printf("File has inode number %lu and is called %s \n", 
             (unsigned long)next_entry_ptr->d_ino, next_entry_ptr->d_name);
        next_entry_ptr = readdir(current_directory_ptr);
    }

    char fileToView[200]; // Changed from char* fileToView[200] to char fileToView[200]
    printf("Enter name of desired file\n");
    scanf("%s", fileToView); // Removed & before fileToView

    stat(fileToView, buf);
    off_t size = buf->st_size;
    printf("Size = %jd \n", (intmax_t)size); // Modified to use %jd for off_t
    uid_t owner = buf->st_uid;
    printf("Owner = %d \n", owner);

    closedir(current_directory_ptr);

    free(buf); // Free allocated memory

    return (EXIT_SUCCESS);
}
