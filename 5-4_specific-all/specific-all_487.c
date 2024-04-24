#include <stdio.h>
#include <string.h>

// Assuming User_Data and find_user functions are properly defined

int delete_user(const char user_name[256]) {
    FILE *new_file = NULL;
    FILE *fp = NULL;
    char user_name_to_copy[256];
    char password_to_copy[256];
    char old_file_name[256];
    char temp_file_name[] = "duplicate.txt";
    
    User_Data *ud = find_user(user_name);
    if (ud == NULL) {
        printf("The username wasn't found!\n");
        return 0;
    }

    if (strcmp(ud->permission_type, "Admin") == 0) {
        printf("Can't delete an admin.\n");
        return 0;
    } else {
        strcpy(old_file_name, ud->permission_type);
        strcat(old_file_name, "s.txt");
        
        fp = fopen(old_file_name, "r");
        if (fp == NULL) {
            printf("Error opening file for reading.\n");
            return 0;
        }
        
        new_file = fopen(temp_file_name, "w");
        if (new_file == NULL) {
            printf("Error opening file for writing.\n");
            fclose(fp);
            return 0;
        }
        
        while (fscanf(fp, "%s %s", user_name_to_copy, password_to_copy) == 2) {
            if (strcmp(user_name_to_copy, user_name) != 0) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }
        
        fclose(fp);
        fclose(new_file);
        
        if (remove(old_file_name) != 0) {
            printf("Error deleting file.\n");
            return 0;
        }
        
        if (rename(temp_file_name, old_file_name) != 0) {
            printf("Error renaming file.\n");
            return 0;
        }
        
        return 1;
    }
}

int main() {
    // Test the delete_user function
    printf("Result: %d\n", delete_user("username_to_delete"));
    return 0;
}
