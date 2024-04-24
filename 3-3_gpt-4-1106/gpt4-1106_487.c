if ((fp = fopen(old_file_name, "rt")) == NULL) {
    perror("Error opening file");
    return FALSE;
}

// ... Processing ...

if (fclose(fp) != 0) {
    perror("Error closing file");
    return FALSE;
}

if (fclose(new_file) != 0) {
    perror("Error closing new_file");
    return FALSE;
}

if (remove(old_file_name) != 0) {
    perror("Error removing old file");
    return FALSE;
}

if (rename("duplicate.txt", old_file_name) != 0) {
    perror("Error renaming file");
    remove("duplicate.txt"); // Attempt to clean up
    return FALSE;
}

// The duplicate file removal is redundant at this point, so it can be removed.
while (fscanf(fp, "%255s %255s", user_name_to_copy, password_to_copy) == 2) {
    if (strcmp(user_name_to_copy, user_name)) {
        fprintf(new_file, "%s %s\n", user_name_to_copy, password_to_copy);
    }
}
