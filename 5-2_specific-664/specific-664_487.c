#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char permission_type[256];
} User_Data;

bool delete_user(char user_name[256]) {
    User_Data *ud = NULL;
    char user_name_to_copy[256];
    char password_to_copy[256];
    char old_file_name[256];
    
    ud = find_user(user_name);
    if (ud == NULL) {
        printf("The username wasn't found!\n");
        return false;
    }
    
    if (!strcmp(ud->permission_type, "Admin")) {
        printf("Cannot delete an admin user.\n");
        return false;
    } else {
        char duplicate_file_name[256] = "duplicate.txt";
        FILE *new_file = fopen(duplicate_file_name, "wt");
        if (new_file == NULL) {
            perror("Error opening duplicate file");
            return false;
        }
        
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");
        FILE *fp = fopen(old_file_name, "rt");
        if (fp == NULL) {
            perror("Error opening user file to read");
            fclose(new_file);
            return false;
        }
        
        while (fscanf(fp, "%s %s", user_name_to_copy, password_to_copy) == 2) {
            if (strcmp(user_name_to_copy, user_name) != 0) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }
        
        fclose(fp);
        fclose(new_file);
        
        if (remove(old_file_name) != 0) {
            perror("Error deleting old user file");
            return false;
        }
        
        if (rename(duplicate_file_name, old_file_name) != 0) {
            perror("Error renaming file");
            return false;
        }
        
        return true;
    }
}
