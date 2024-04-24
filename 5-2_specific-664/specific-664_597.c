#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv) {

    struct stat buf;
    
    DIR *current_directory_ptr;
    struct dirent *next_entry_ptr;

    char dirToView[200];

    printf("Enter path of desired directory: ");
    scanf("%s", dirToView);

    current_directory_ptr = opendir(dirToView);

    next_entry_ptr = readdir(current_directory_ptr);

    while (next_entry_ptr != NULL) {
        printf("File has inode number %ld and is called %s\n",
               (long)next_entry_ptr->d_ino, next_entry_ptr->d_name);
        next_entry_ptr = readdir(current_directory_ptr);
    }

    char fileToView[200];
    printf("Enter name of desired file: ");
    scanf("%s", fileToView);

    stat(fileToView, &buf);
    off_t size = buf.st_size;
    printf("Size = %ld \n", (long)size);

    uid_t owner = buf.st_uid;
    printf("Owner = %d \n", owner);

    closedir(current_directory_ptr);

    return (EXIT_SUCCESS);
}
