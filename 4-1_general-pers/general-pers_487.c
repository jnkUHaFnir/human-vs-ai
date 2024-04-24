#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean;

boolean delete_user(char user_name[256]) {
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
        printf("Cannot delete an admin.");
        return FALSE;
    } else {
        new_file = fopen("duplicate.txt", "wt");
        if (new_file == NULL) {
            printf("Error creating duplicate file.\n");
            return FALSE;
        }

        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");
        fp = fopen(old_file_name, "rt");
        if (fp == NULL) {
            printf("Error opening file to read.\n");
            fclose(new_file);
            return FALSE;
        }

        while (fscanf(fp, "%255s %255s", user_name_to_copy, password_to_copy) == 2) {
            if (strcmp(user_name_to_copy, user_name) != 0) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }

        fclose(fp);
        fclose(new_file);

        if (remove(old_file_name) == 0) {
            if (rename("duplicate.txt", old_file_name) == 0) {
                remove("duplicate.txt");
                return TRUE;
            } else {
                printf("Error renaming file.\n");
            }
        } else {
            printf("Error deleting file.\n");
        }
    }

    return FALSE;
}
