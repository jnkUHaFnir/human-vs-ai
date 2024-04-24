#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Use this for standard boolean type in C99 and later

bool delete_user(const char user_name[256]) {
    bool status = false;
    User_Data *ud = find_user(user_name);
    if (!ud) {
        printf("The username wasn't found!\n");
        return status;
    }
    
    if (strcmp(ud->permission_type, "Admin") == 0) {
        printf("Can't delete an admin.\n");
        return status;
    }
    
    FILE *new_file = fopen("duplicate.txt", "wt");
    if (!new_file) {
        fprintf(stderr, "Failed to open new file for writing.\n");
        return status;
    }
    
    char old_file_name[256] = {0};
    strcpy(old_file_name, ud->permission_type);
    strcat(old_file_name, "s.txt"); //the name of the file is in plural and ends with .txt
    
    FILE *fp = fopen(old_file_name, "rt");
    if (!fp) {
        fprintf(stderr, "Failed to open old file for reading.\n");
        fclose(new_file);
        return status;
    }
    
    char user_name_to_copy[256];
    char password_to_copy[256];
    while (fscanf(fp, "%255s %255s\n", user_name_to_copy, password_to_copy) == 2) {
        if (strcmp(user_name_to_copy, user_name) != 0) {
            fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
        }
    }
    
    fclose(fp);
    fclose(new_file);
    
    if (remove(old_file_name) != 0) {
        fprintf(stderr, "Failed to remove old file.\n");
        return status;
    }
    if (rename("duplicate.txt", old_file_name) != 0) {
        fprintf(stderr, "Failed to rename new file to old file name.\n");
        return status;
    }
    
    status = true;
    return status;
}
