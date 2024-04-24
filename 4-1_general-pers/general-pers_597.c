#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv) {

    struct stat *buf;
    buf = malloc(sizeof(struct stat)); 

    DIR * current_directory_ptr; 
    struct dirent * next_entry_ptr; 

    char dirToView[200]; // Changed array declaration

    printf("Enter path of desired directory: \n");
    scanf("%s", dirToView);

    current_directory_ptr = opendir(dirToView);

    next_entry_ptr = readdir(current_directory_ptr);

    while(next_entry_ptr != NULL){
        printf("File has inode number %ld and is called %s \n", 
             next_entry_ptr->d_ino, next_entry_ptr->d_name);
        next_entry_ptr=readdir(current_directory_ptr);

    }

    char fileToView[200]; // Changed array declaration
    printf("Enter name of desired file: \n");
    scanf("%s", fileToView);

    if(stat(fileToView, buf) == 0) {
        off_t size = buf -> st_size;
        printf("Size = %lld bytes\n", (long long)size); // Cast to proper type for printing

        uid_t owner = buf -> st_uid;
        printf("Owner UID = %d \n", (int)owner); // Cast to proper type for printing
    }
    else {
        printf("Error: Unable to get file stat.\n");
    }

    closedir(current_directory_ptr);
    free(buf);

    return EXIT_SUCCESS;
}
