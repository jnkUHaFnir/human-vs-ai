#include <stdio.h>
#include <string.h>

typedef struct User_Data {
    char user_name[256];
    char permission_type[256];
} User_Data;

// Define boolean type for C
typedef int bool;
#define TRUE 1
#define FALSE 0

User_Data* find_user(const char* user_name) {
    // Implementation of finding user by user_name
    return NULL;
}

bool delete_user(const char user_name[256]) {
    bool status = FALSE;
    User_Data* ud = NULL;
    bool found_user = FALSE;
    FILE* new_file = NULL;
    FILE* fp = NULL;
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
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");

        fp = fopen(old_file_name, "rt");
        if (fp == NULL) {
            printf("Error opening file %s\n", old_file_name);
            return FALSE;
        }

        new_file = fopen("duplicate.txt", "wt");
        while (fscanf(fp, "%s %s", user_name_to_copy, password_to_copy) == 2) {
            if (strcmp(user_name_to_copy, user_name) != 0) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }

        fclose(fp);
        fclose(new_file);

        if (remove(old_file_name) != 0) {
            printf("Error deleting file %s\n", old_file_name);
            return FALSE;
        }

        if (rename("duplicate.txt", old_file_name) != 0) {
            printf("Error renaming file\n");
            return FALSE;
        }

        return TRUE;
    }
}

int main() {
    // Test delete_user function
    delete_user("Alice");

    return 0;
}
