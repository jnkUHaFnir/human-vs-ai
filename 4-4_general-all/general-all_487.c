#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 255

typedef struct {
    char username[MAX_USERNAME_LENGTH + 1]; // +1 for null terminator
    char permission_type[10]; // Assuming permission type to be less than 10 characters
} User_Data;

typedef enum {
    FALSE,
    TRUE
} boolean;

User_Data* find_user(const char* username) {
    // Placeholder for finding user data
    return NULL;
}

boolean delete_user(const char user_name[]) {
    boolean status = FALSE;
    User_Data *ud = NULL;
    FILE *new_file = NULL;
    FILE *fp = NULL;
    char user_name_to_copy[MAX_USERNAME_LENGTH + 1];
    char password_to_copy[256];
    char old_file_name[256];

    ud = find_user(user_name);
    if (ud == NULL) {
        printf("The username wasn't found!\n");
        return FALSE;
    }
    if (strcmp(ud->permission_type, "Admin") == 0) {
        printf("Cannot delete an admin.\n");
        return FALSE;
    } else {
        // User to delete was found
        new_file = fopen("duplicate.txt", "wt");
        if (new_file == NULL) {
            printf("Error creating duplicate file.\n");
            return FALSE;
        }
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");

        fp = fopen(old_file_name, "rt");
        if (fp == NULL) {
            printf("Error opening file for reading.\n");
            fclose(new_file);
            return FALSE;
        }

        while (fscanf(fp, "%s %s\n", user_name_to_copy, password_to_copy) == 2) {
            if (strcmp(user_name_to_copy, user_name) != 0) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }

        fclose(fp);
        fclose(new_file);

        if (remove(old_file_name) == 0) {
            if (rename("duplicate.txt", old_file_name) == 0) {
                status = TRUE;
            } else {
                // Error renaming file
                remove("duplicate.txt");
            }
        } else {
            // Error removing original file
            remove("duplicate.txt");
        }
    }

    return status;
}
