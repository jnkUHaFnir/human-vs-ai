boolean delete_user(char user_name[256])   //only for Admin
{
    boolean status = FALSE;//what does the function return
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
    } else {
        // the user to delete was found 
        new_file = fopen("duplicate.txt", "wt");
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt"); //the name of the file is in plural and ends with .txt
        fp = fopen(old_file_name, "rt");
        while (!feof(fp)) {
            //copy all the users except the user to delete the new file 
            fscanf(fp, "%s %s\n", user_name_to_copy, password_to_copy);
            if (strcmp(user_name_to_copy, user_name)) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }
        fclose(fp);
        fclose(new_file);
        printf(" %d ", remove(old_file_name));

        if (rename("duplicate.txt", old_file_name) != 0) {
            remove("duplicate.txt");
        }
        return TRUE;
    }
}
while (fscanf(fp, "%s %s\n", user_name_to_copy, password_to_copy) == 2) {
    if (strcmp(user_name_to_copy, user_name) != 0) {
        fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
    }
}
