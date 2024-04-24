#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean; // define boolean enum type

typedef struct {
    char permission_type[256];
} User_Data;

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
        printf("Can't delete an admin.\n");
        return FALSE;
    } else {
        // the user to delete was found 
        new_file = fopen("duplicate.txt", "wt");
        snprintf(old_file_name, sizeof(old_file_name), "%s.txt", ud->permission_type); 

        fp = fopen(old_file_name, "rt");
        while (fscanf(fp, "%s %s", user_name_to_copy, password_to_copy) == 2) {
            //copy all the users except the user to delete to the new file 
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
                remove("duplicate.txt");
            }
        }

        return status;
    }
}
