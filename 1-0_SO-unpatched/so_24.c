        FILE *fp = open_file(old_file_name, "rt");
        char line[1024];
        while (fgets(line, 1024, fp)) {
            //copy all the users except the user to delete the new file 
            if( sscanf(fp, "%255s %255s\n", user_name_to_copy, password_to_copy) != 2 ) {
                fprintf(stderr, "Couldn't understand line '%s'\n", line);
                continue;
            }
            if (strcmp(user_name_to_copy, user_name)) {
                fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
            }
        }
        fclose(fp);