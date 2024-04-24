boolean delete_user(char user_name[256]) //only for Admin
{
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
        new_file = fopen("duplicate.txt", "wt");
        if (!new_file) {
            printf("Failed to open duplicate.txt for writing.\n");
            return FALSE;
        }

        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt"); // The name of the file is in plural and ends with .txt
        fp = fopen(old_file_name, "rt");
        if (!fp) {
            printf("Failed to open the original file for reading.\n");
            fclose(new_file); // Important to close new_file before returning
            return FALSE;
        }

        while (fscanf(fp, "%255s %255s\n", user_name_to_copy, password_to_copy) == 2) {
            if (strcmp(user_name_to_copy, user_name)) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }
        fclose(fp);
        fclose(new_file);

        if (remove(old_file_name) != 0) {
            perror("Error deleting the original file");
            return FALSE;
        }

        if (rename("duplicate.txt", old_file_name) != 0) {
            perror("Error renaming `duplicate.txt` to the original file name");
            return FALSE;
        }

        // No need to remove "duplicate.txt" since we've just renamed it to old_file_name.
        return TRUE;
    }
}
