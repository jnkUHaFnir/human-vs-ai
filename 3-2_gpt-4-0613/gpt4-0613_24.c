if(remove(old_file_name) != 0) {
    printf("Error deleting file %s: %s\n", old_file_name, strerror(errno));
} else {
    printf("File %s deleted successfully\n", old_file_name);
}

if(rename("duplicate.txt", old_file_name) != 0) {
    printf("Error renaming file %s to %s: %s\n", "duplicate.txt", old_file_name, strerror(errno));
} else {
    printf("File %s renamed successfully to %s\n", "duplicate.txt", old_file_name);
}
