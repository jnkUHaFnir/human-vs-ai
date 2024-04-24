#include <stdio.h>
#include <string.h>

typedef struct {
    char user_name[256];
    char permission_type[256];
} User_Data;

int delete_user(const char *user_name) {
    User_Data *ud = find_user(user_name);
    if (ud == NULL) {
        printf("The username wasn't found!\n");
        return 0;
    }

    if (strcmp(ud->permission_type, "Admin") == 0) {
        printf("Cannot delete an admin.\n");
        return 0;
    }

    char old_file_name[256];
    snprintf(old_file_name, 256, "%ss.txt", ud->permission_type);

    FILE *fp = fopen(old_file_name, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 0;
    }

    FILE *new_file = fopen("duplicate.txt", "w");
    if (new_file == NULL) {
        printf("Error opening file for writing.\n");
        fclose(fp); // Close opened files before returning
        return 0;
    }

    char user_name_to_copy[256];
    char password_to_copy[256];

    while (fscanf(fp, "%s %s", user_name_to_copy, password_to_copy) == 2) {
        if (strcmp(user_name_to_copy, user_name)) {
            fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
        }
    }

    fclose(fp);
    fclose(new_file);

    if (remove(old_file_name) != 0) {
        printf("Error deleting old file.\n");
        return 0;
    }

    if (rename("duplicate.txt", old_file_name) != 0) {
        printf("Error renaming file.\n");
        return 0;
    }

    return 1;
}
