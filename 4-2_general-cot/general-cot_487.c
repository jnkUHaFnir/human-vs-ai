#include <stdio.h>
#include <string.h>

typedef enum {FALSE, TRUE} boolean;

typedef struct {
    char permission_type[256];
} User_Data;

User_Data* find_user(char user_name[256]) {
    // Implement your logic to find user
    // This is just a placeholder function
    return NULL;
}

boolean delete_user(char user_name[256]) {
    boolean status = FALSE;
    User_Data *ud = NULL;
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
        printf("Can't delete an admin.\n");
        return FALSE;
    } else {
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");

        fp = fopen(old_file_name, "rt");
        if (fp == NULL) {
            printf("Error opening file for reading.\n");
            return FALSE;
        }

        new_file = fopen("duplicate.txt", "wt");
        if (new_file == NULL) {
            printf("Error opening file for writing.\n");
            fclose(fp);
            return FALSE;
        }

        while (fscanf(fp, "%s %s", user_name_to_copy, password_to_copy) == 2) {
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
                printf("Error renaming file.\n");
            }
        } else {
            printf("Error removing original file.\n");
        }
    }

    return status;
}

int main() {
    // Test the function
    if (delete_user("user1")) {
        printf("User deleted successfully.\n");
    } else {
        printf("User deletion failed.\n");
    }
    return 0;
}
