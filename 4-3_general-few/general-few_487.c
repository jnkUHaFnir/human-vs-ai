boolean delete_user(char user_name[256])   //only for Admin
{
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
        printf("Cant delete an admin.");
        return FALSE;
    }
    else {
        // reset file pointers to beginning of files
        new_file = fopen("duplicate.txt", "wt");
        rewind(new_file);
        
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt"); 
        fp = fopen(old_file_name, "rt");
        rewind(fp);

        while (fscanf(fp, "%s %s\n", user_name_to_copy, password_to_copy) != EOF) {
            if (strcmp(user_name_to_copy, user_name) == 0) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }

        fclose(fp);
        fclose(new_file);
        
        printf(" %d ", remove(old_file_name));
        rename("duplicate.txt", old_file_name);
        remove("duplicate.txt");
        return TRUE;
    }
}
