#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean;

typedef struct {
    char user_name[256];
    char permission_type[256];
} User_Data;

User_Data* find_user(const char user_name[256]) {
    // Implementation of finding a user, not provided here for brevity
    return NULL;
}

boolean delete_user(const char user_name[256]) {
    boolean status = FALSE;
    User_Data *ud = NULL;
    boolean found_user = FALSE;
    FILE *new_file = NULL;
    FILE *fp = NULL;
    char user_name_to_copy[256];
    char password_to_copy[256];
    char old_file_name[256];

    ud = find_user(user_name);
    if (ud == NULL) {
        printf("The username wasn't found!\n");
        return FALSE;
    }
    if (!strcmp(ud->permission_type, "Admin")) {
        printf("Can't delete an admin.");
        return FALSE;
    } else {
        // The user to delete was found
        new_file = fopen("duplicate.txt", "wt");
        if (new_file == NULL) {
            perror("Error opening new file");
            return FALSE;
        }
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");

        fp = fopen(old_file_name, "rt");
        if (fp == NULL) {
            perror("Error opening old file");
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

        if (remove(old_file_name) != 0) {
            perror("Error deleting old file");
            return FALSE;
        }
        
        if (rename("duplicate.txt", old_file_name) != 0) {
            perror("Error renaming file");
            return FALSE;
        }
        
        if (remove("duplicate.txt") != 0) {
            perror("Error deleting duplicate file");
            return FALSE;
        }

        return TRUE;
    }
}

int main() {
    // Test the delete_user function
    boolean result = delete_user("user1");
    if (result) {
        printf("User deleted successfully.\n");
    } else {
        printf("Failed to delete user.\n");
    }

    return 0;
}
