#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean; // Define boolean type

typedef struct {
    char username[256];
    char password[256];
    char permission_type[256];
} User_Data;

User_Data* find_user(const char user_name[256]) {
    // Implementation of finding user
    return NULL;
}

boolean delete_user(const char user_name[256]) {
    boolean status = FALSE;
    User_Data *ud = NULL;

    ud = find_user(user_name);
    if (ud == NULL) {
        printf("The username wasn't found!\n");
        return FALSE;
    }

    if (!strcmp(ud->permission_type, "Admin")) {
        printf("Cannot delete an admin.\n");
        return FALSE;
    }

    // Delete user
    FILE *fp = fopen("users.txt", "r");
    FILE *new_file = fopen("temp.txt", "w");

    if (fp == NULL || new_file == NULL) {
        printf("Error opening files.\n");
        if (fp) fclose(fp);
        if (new_file) fclose(new_file);
        return FALSE;
    }

    char user_name_to_copy[256];
    char password_to_copy[256];

    while (fscanf(fp, "%s %s\n", user_name_to_copy, password_to_copy) == 2) {
        if (strcmp(user_name_to_copy, user_name) != 0) {
            fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
        }
    }

    fclose(fp);
    fclose(new_file);

    if (remove("users.txt") != 0) {
        printf("Error deleting file.\n");
        return FALSE;
    }

    if (rename("temp.txt", "users.txt") != 0) {
        printf("Error renaming file.\n");
        return FALSE;
    }

    printf("User deleted successfully.\n");
    return TRUE;
}

int main() {
    delete_user("user1");
    return 0;
}
