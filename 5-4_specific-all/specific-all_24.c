#include <stdio.h>
#include <string.h>

#define USER_FILE_PATH "user_files/"

typedef enum { FALSE, TRUE } boolean;

boolean delete_user(char user_name[256]) {
    boolean status = FALSE;
    User_Data *ud = NULL;
    boolean found_user = FALSE;
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
    }

    // Construct the old file name
    snprintf(old_file_name, sizeof(old_file_name), "%s%s%s%s", USER_FILE_PATH, ud->permission_type, "s.txt");

    // Open the old file for reading
    FILE *fp = fopen(old_file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", old_file_name);
        return FALSE;
    }

    // Open a new file for writing
    FILE *new_file = fopen("duplicate.txt", "w");
    if (new_file == NULL) {
        printf("Error creating new file\n");
        fclose(fp);
        return FALSE;
    }

    // Read from old file, write to new file
    while (fscanf(fp, "%s %s\n", user_name_to_copy, password_to_copy) == 2) {
        if (strcmp(user_name_to_copy, user_name)) {
            fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
        }
    }

    fclose(fp);
    fclose(new_file);

    // Remove the old file and rename the new file
    if (remove(old_file_name) == 0) {
        if (rename("duplicate.txt", old_file_name) == 0) {
            status = TRUE;
        } else {
            printf("Error renaming file\n");
            remove("duplicate.txt");
        }
    } else {
        printf("Error deleting file\n");
        remove("duplicate.txt");
    }

    return status;
}
